/**
 * @file num2a.c
 * Copyright 2016 Issam Ali /Syria- Baniyas/ issamsoft.com
 * 
 * جميع الحقوق محفوظة 2016 عصام علي / سوريا-بانياس issamsoft.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "num2a.h"
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <wchar.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"



#define MAX_DIGIT_NAME_LENGTH 64
#define MAX_STRING_INPUT_LENGTH 64
#define MAX_DIG_ARRAY_SIZE 16
#define MAX_TWO_CORRECTION_ARRAY 6
#define MAX_DOUBLE_ARRAY_LENGTH (DBL_MANT_DIG - DBL_MIN_EXP + 3)
#define DEFAULT_DECIMAL_POINT '.'
#define STR_NEGATIVE_SIGN L"ناقص"
#define STR_ZERO_NAME L"صفر"
#define STR_POINT_NAME L"فاصلة"
#define STR_TANWEEN_NASEB L"اً"
#define STR_SPACE L" "
#define STR_AND L" و "


typedef struct {
	int hasOneName;
	int place;
	wchar_t *maleName;
	wchar_t *femaleName;
	wchar_t *combinedMaleName;
	wchar_t *combinedFemaleName;
	wchar_t *addedMaleName;
	wchar_t *addedFemaleName;
} NUMBER_NAME;


wchar_t* get_number_name(const NUMBER_NAME *np, ItemGender ig, int isCombined, int isAdded)
{
	if(!np)
		return NULL;
	if(np->hasOneName)
		return np->maleName;
	if(isCombined)
		return (ig == IG_MALE)? np->combinedMaleName : np->combinedFemaleName;
	if(isAdded)
		return (ig == IG_MALE)? np->addedMaleName : np->addedFemaleName;
	return (ig == IG_MALE)? np->maleName : np->femaleName;
}

wchar_t* correct_two_name(int power)
{
	//تصحيح حذف نون المثنى عند الاضافة: مئتان --مئتا، ألفان -- ألفا ....
	static NUMBER_NAME two_names_correction[MAX_TWO_CORRECTION_ARRAY] = 
			{{1, 3, L"مئتا"}, {1, 4, L"ألفا"}, {1, 7, L"مليونا"}, {1, 10, L"مليارا"}, {1, 13, L"تريليونا"}, {1, 16, L"كوادريليونا"}};
	int idx = 0;
	wchar_t *result = NULL;
	for(idx = 0; idx < MAX_TWO_CORRECTION_ARRAY; idx ++)
	{
		if(two_names_correction[idx].place == power)
		{
			result = two_names_correction[idx].maleName;
			break;
		}
	}
	return result;
}

NUMBER_NAME *get_dig_arr(int dig)
{
	static NUMBER_NAME one_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"واحد", L"واحدة", NULL, NULL, L"واحد", L"إحدى"}, {0, 2, L"عشرة", L"عشر", L"عشر", L"عشرة"},
			{1, 3, L"مئة"},{1, 4, L"ألف"},{0, 5, L"عشرة ألاف", L"عشر آلاف", L"عشر ألف", L"عشرة ألف"}, {1, 6, L"مئة ألف"},
			{1, 7, L"مليون"}, {0, 8, L"عشرة ملايين", L"عشر ملايين", L"عشر مليون", L"عشرة مليون"},{1, 9, L"مئة مليون"}, {1, 10, L"مليار"},
			{0, 11, L"عشرة مليارات", L"عشر مليارات", L"عشر مليار", L"عشرة مليار"}, {1, 12, L"مئة مليار"},	{1, 13, L"ترليون"},
			{0, 14, L"عشرة ترليونات", L"عشر ترليونات", L"عشر ترليون", L"عشرة ترليون"},{1, 15, L"مئة ترليون"},{1, 16, L"كوادريليون"}};
	static NUMBER_NAME two_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"اثنان", L"اثنتان", NULL, NULL, L"اثنان", L"اثنتان"}, {1, 2, L"عشرون"},{1, 3, L"مئتان"},{1, 4, L"ألفان"},
			{1, 5, L"عشرون ألف"}, {1, 6, L"مئتا ألف"},{1, 7, L"مليونان"},{1, 8, L"عشرون مليون"},{1, 9, L"مئتا مليون"}, {1, 10, L"ملياران"},
			{1, 11, L"عشرون مليار"}, {1, 12, L"مئتا مليار"},	{1, 13, L"تريليونان"}, {1, 14, L"عشرون تريليون"},{1, 15, L"مئتا تريليون"},{1, 16, L"كوادريليونان"}};
	static NUMBER_NAME three_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"ثلاثة", L"ثلاث", NULL, NULL, L"ثلاثة", L"ثلاث"}, {1, 2, L"ثلاثون"},{1, 3, L"ثلاثمئة"},{0, 4, L"ثلاثة آلاف", L"ثلاث آلاف"},
			{1, 5, L"ثلاثون ألف"}, {1, 6, L"ثلاثمئة ألف"},{0, 7, L"ثلاثة ملايين", L"ثلاث ملايين"},{1, 8, L"ثلاثون مليون"},{1, 9, L"ثلاثمئة مليون"}, {0, 10, L"ثلاثة مليارات", L"ثلاث مليارات"},
			{1, 11, L"ثلاثون مليار"}, {1, 12, L"ثلاثمئة مليار"},	{0, 13, L"ثلاثة تريليونات", L"ثلاث تريليونات"}, {1, 14, L"ثلاثون تريليون"},{1, 15, L"ثلاثمئة تريليون"},{0, 16, L"ثلاثة كوادريليونات", L"ثلاث كوادريليونات"}};
	static NUMBER_NAME four_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"أربعة", L"أربع", NULL, NULL, L"أربعة", L"أربع"}, {1, 2, L"أربعون"},{1, 3, L"أربعمئة"},{0, 4, L"أربعة آلاف", L"أربع آلاف"},
			{1, 5, L"أربعون ألف"}, {1, 6, L"أربعمئة ألف"},{0, 7, L"أربعة ملايين", L"أربع ملايين"},{1, 8, L"أربعون مليون"},{1, 9, L"أربعمئة مليون"}, {0, 10, L"أربعة مليارات", L"أربع مليارات"},
			{1, 11, L"أربعون مليار"}, {1, 12, L"أربعمئة مليار"},	{0, 13, L"أربعة تريليونات", L"أربع تريليونات"}, {1, 14, L"أربعون تريليون"},{1, 15, L"أربعمئة تريليون"},{0, 16, L"أربعة كوادريليونات", L"أربع كوادريليونات"}};
	static NUMBER_NAME five_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"خمسة", L"خمس", NULL, NULL, L"خمسة", L"خمس"}, {1, 2, L"خمسون"},{1, 3, L"خمسمئة"},{0, 4, L"خمسة آلاف", L"خمس آلاف"},
			{1, 5, L"خمسون ألف"}, {1, 6, L"خمسمئة ألف"},{0, 7, L"خمسة ملايين", L"خمس ملايين"},{1, 8, L"خمسون مليون"},{1, 9, L"خمسمئة مليون"}, {0, 10, L"خمسة مليارات", L"خمس مليارات"},
			{1, 11, L"خمسون مليار"}, {1, 12, L"خمسمئة مليار"},	{0, 13, L"خمسة تريليونات", L"خمس تريليونات"}, {1, 14, L"خمسون تريليون"},{1, 15, L"خمسمئة تريليون"},{0, 16, L"خمسة كوادريليونات", L"خمس كوادريليونات"}};
	static NUMBER_NAME six_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"ستة", L"ست", NULL, NULL, L"ستة", L"ست"}, {1, 2, L"ستون"},{1, 3, L"ستمئة"},{0, 4, L"ستة آلاف", L"ست آلاف"},
			{1, 5, L"ستون ألف"}, {1, 6, L"ستمئة ألف"},{0, 7, L"ستة ملايين", L"ست ملايين"},{1, 8, L"ستون مليون"},{1, 9, L"ستمئة مليون"}, {0, 10, L"ستة مليارات", L"ست مليارات"},
			{1, 11, L"ستون مليار"}, {1, 12, L"ستمئة مليار"},	{0, 13, L"ستة تريليونات", L"ست تريليونات"}, {1, 14, L"ستون تريليون"},{1, 15, L"ستمئة تريليون"},{0, 16, L"ستة كوادريليونات", L"ست كوادريليونات"}};
	static NUMBER_NAME seven_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"سبعة", L"سبع", NULL, NULL, L"سبعة", L"سبع"}, {1, 2, L"سبعون"},{1, 3, L"سبعمئة"},{0, 4, L"سبعة آلاف", L"سبع آلاف"},
			{1, 5, L"سبعون ألف"}, {1, 6, L"سبعمئة ألف"},{0, 7, L"سبعة ملايين", L"سبع ملايين"},{1, 8, L"سبعون مليون"},{1, 9, L"سبعمئة مليون"}, {0, 10, L"سبعة مليارات", L"سبع مليارات"},
			{1, 11, L"سبعون مليار"}, {1, 12, L"سبعمئة مليار"},	{0, 13, L"سبعة تريليونات", L"سبع تريليونات"}, {1, 14, L"سبعون تريليون"},{1, 15, L"سبعمئة تريليون"},{0, 16, L"سبعة كوادريليونات", L"سبع كوادريليونات"}};
	static NUMBER_NAME eight_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"ثمانية", L"ثمان", NULL, NULL, L"ثمانية", L"ثمان"}, {1, 2, L"ثمانون"},{1, 3, L"ثمانمئة"},{0, 4, L"ثمانية آلاف", L"ثمان آلاف"},
			{1, 5, L"ثمانون ألف"}, {1, 6, L"ثمانمئة ألف"},{0, 7, L"ثمانية ملايين", L"ثمان ملايين"},{1, 8, L"ثمانون مليون"},{1, 9, L"ثمانمئة مليون"}, {0, 10, L"ثمانية مليارات", L"ثمان مليارات"},
			{1, 11, L"ثمانون مليار"}, {1, 12, L"ثمانمئة مليار"},	{0, 13, L"ثمانية تريليونات", L"ثمان تريليونات"}, {1, 14, L"ثمانون تريليون"},{1, 15, L"ثمانمئة تريليون"},{0, 16, L"ثمانية كوادريليونات", L"ثمان كوادريليونات"}};
	static NUMBER_NAME nine_names[MAX_DIG_ARRAY_SIZE] = 
			{{0, 1, L"تسعة", L"تسع", NULL, NULL, L"تسعة", L"تسع"}, {1, 2, L"تسعون"},{1, 3, L"تسعمئة"},{0, 4, L"تسعة آلاف", L"تسع آلاف"},
			{1, 5, L"تسعون ألف"}, {1, 6, L"تسعمئة ألف"},{0, 7, L"تسعة ملايين", L"تسع ملايين"},{1, 8, L"تسعون مليون"},{1, 9, L"تسعمئة مليون"}, {0, 10, L"تسعة مليارات", L"تسع مليارات"},
			{1, 11, L"تسعون مليار"}, {1, 12, L"تسعمئة مليار"},	{0, 13, L"تسعة تريليونات", L"تسع تريليونات"}, {1, 14, L"تسعون تريليون"},{1, 15, L"تسعمئة تريليون"},{0, 16, L"تسعة كوادريليونات", L"تسع كوادريليونات"}};
	
	switch(dig)
	{
		case 1:
			return one_names;
		break;
		case 2:
			return two_names;
		break;
		case 3:
			return three_names;
		break;
		case 4:
			return four_names;
		break;
		case 5:
			return five_names;
		break;
		case 6:
			return six_names;
		break;		
		case 7:
			return seven_names;
		break;		
		case 8:
			return eight_names;
		break;
		case 9:
			return nine_names;
		break;
		default:
			return NULL;
	}
}

void add_dig_str_tanween(wchar_t **pStr, size_t sizeOfBuffer)
{
	//اضافة تنوين
	wchar_t *tmpStr = NULL;
	if(*pStr)
	{
		tmpStr = realloc(*pStr, (wcslen(*pStr) +2 + 1) * sizeof(wchar_t));
		if(tmpStr == NULL)
		{
			free(*pStr);
			*pStr = NULL;
			return;
		}
		*pStr = tmpStr;
		n2a_wcscat(*pStr, sizeOfBuffer, STR_TANWEEN_NASEB);
	}
}

wchar_t *get_dig_str(
			int dig,
			char master_dig,
			int power, 
			int isCombine, 
			int isMaster,
			int isFinal, 
			int useThirdIdx,
			int isDigitsToRight,
			const wchar_t *itemName, 
			const wchar_t *dualItemName,
			const wchar_t *pluralItemName,
			ItemGender ig
			)
{
	NUMBER_NAME *str_ar;
	wchar_t *number_name = NULL;
	wchar_t *final_str = NULL;
	size_t len = 0;
	str_ar = get_dig_arr(dig);

	if((power > (MAX_DIG_ARRAY_SIZE - 1)) || power < 0)
		return NULL;
	if(!str_ar)
		return NULL;
	if(!isCombine)
	{
		if(isFinal)
		{
			switch(dig)
			{
				case 1:
					number_name = get_number_name(&str_ar[power], ig, isMaster, isCombine);
					len = wcslen(itemName) + 1 + wcslen(number_name) + 1;
					final_str = (wchar_t *) malloc(len * sizeof(wchar_t));
					if(!final_str)
						return NULL;
					n2a_wcscpy(final_str, itemName, len);
					final_str[wcslen(itemName)] = L'\0';
					n2a_wcscat(final_str, len, STR_SPACE);
					n2a_wcscat(final_str, len, number_name);
					return final_str;
				break;
				case 2:
					number_name = get_number_name(&str_ar[power], ig, isMaster, isCombine);
					len = wcslen(dualItemName) + 1 + wcslen(number_name) + 1;
					final_str = (wchar_t *) malloc(len * sizeof(wchar_t));
					if(!final_str)
						return NULL;
					n2a_wcscpy(final_str, dualItemName, len);
					final_str[wcslen(dualItemName)] = L'\0';
					n2a_wcscat(final_str, len, STR_SPACE);
					n2a_wcscat(final_str, len, number_name);
					return final_str;
				break;
				default:
					number_name = get_number_name(&str_ar[power], ig, isMaster, isCombine);
					len = wcslen(number_name) + 1 + wcslen(pluralItemName) + 1; 
					final_str = (wchar_t *) malloc(len * sizeof(wchar_t));
					if(!final_str)
						return NULL;
					n2a_wcscpy(final_str, number_name, len);
					final_str[wcslen(number_name)] = L'\0';
					n2a_wcscat(final_str, len, STR_SPACE);
					n2a_wcscat(final_str, len, pluralItemName);
					return final_str;
				break;
			}
				
		}
		else
		{
			if(useThirdIdx)
				return WCSDUP(get_number_name(&str_ar[2], ig, isMaster, isCombine));
			else
			{
				
				if(dig == 2 && power > 0 && (power == 2 || power % 3 == 0) && !isDigitsToRight)
					return WCSDUP(correct_two_name(power+1));
				else
					return WCSDUP(get_number_name(&str_ar[power], ig, isMaster, isCombine));
			}
		}
	}
	else
	{
		if(master_dig == '\0')
			return NULL;
		
		switch(dig)
		{
			case 1:
				if(master_dig == '1')
					return (ig == IG_MALE) ? WCSDUP(L"أحد") : WCSDUP(L"إحدى");
				else
					return (ig == IG_MALE) ? WCSDUP(L"واحد") :  WCSDUP(L"إحدى");
			break;
			case 2:
				if(master_dig == '1')
					return (ig == IG_MALE) ? WCSDUP(L"اثنا"): WCSDUP(L"اثنتا");
				else
					return (ig == IG_MALE) ? WCSDUP(L"اثنان"): WCSDUP(L"اثنتان");
			break;
			default:
				return WCSDUP(get_number_name(&str_ar[0], ig, isMaster, isCombine));
		}
	}

}

int hasDigToRight(const char *numArr, size_t idx, size_t length)
{
	int result = 0; 
	size_t i = 0;
	if(idx <= length -1 && idx > 0)
	{
		for(i = idx; i-->0;)
		{
			if(numArr[i] != '0')
			{
				result = 1;
				break;
			}
		}
	}
	return result;
}

double get_fractional_part(double num, int decimalPlace, int *leadingZeros)
{
	char snum[MAX_DOUBLE_ARRAY_LENGTH];
	char *result = NULL;
	double dres = 0;
	size_t idx = 0, cnt = 0, stpi = 0;

	n2a_sprintf(snum, MAX_DOUBLE_ARRAY_LENGTH, "%.6f", num);
	
	cnt = strlen(snum);
	for(idx = 0; idx < cnt; idx++)
	{
		if((!isdigit(snum[idx])) && (idx < (cnt - 1)))
		{
			result = snum + idx+1;
			break;
		}
	}
	if(result)
	{
		cnt = strlen(result);
		//count leading zeros
		for(idx = 0; idx < cnt; idx ++)
		{
			if(result[idx] != '0')
				break;
			(*leadingZeros)++;
		}			
		//remove extra zeros
		if(decimalPlace > 0)
			stpi = decimalPlace;
		for(idx = cnt-1; idx >= stpi; idx--)
		{
			if(decimalPlace <= 0 && result[idx] != '0')
				break;
			result[idx] = '\0';
		}			
		#ifdef _MSC_VER
		sscanf_s(result, "%lf", &dres);
		#else
		sscanf(result, "%lf", &dres);
		#endif
	}
	
	return dres;
}

 wchar_t *process_numW(
					double num, 
					const wchar_t *itemName, 
					const wchar_t *itemNameWithTanween,
					const wchar_t *dualItemName,
					const wchar_t *pluralItemName,
					ItemGender ig,
					int isFractionalOnly
					)
{
	wchar_t *result = NULL, *bkPtr = NULL;
	wchar_t *dig_str = NULL;
	wchar_t *tResult = NULL;
	wchar_t master_in_hold[MAX_DIGIT_NAME_LENGTH];
	char numArr[MAX_DOUBLE_ARRAY_LENGTH], tempArr[MAX_DOUBLE_ARRAY_LENGTH];
	
	int idx2 = 0, dig = 0, isCombine = 0 , isMaster = 0, isFinal = 0, useThirdIdx = 0, isDigitToRight = 0, 
		isNegative = 0, isTenth = 0;
	size_t numLen = 0, strLen = 0, in_hold_len = 0, tmp_len = 0, idx = 0;
	
	char master_dig = '\0';

	if(num < 0)
	{
		num = -1 * num;
		isNegative = 1;
	}
	
	wmemset(master_in_hold, L'\0', MAX_DIGIT_NAME_LENGTH);

	//convert number to string 
	n2a_sprintf(tempArr, MAX_DOUBLE_ARRAY_LENGTH, "%.6f", num);
	
	//remove fractional part
	numLen = strlen(tempArr);
	for(idx = 0; idx < numLen; idx++)
	{
		if(!isdigit(tempArr[idx]))
		{
			tempArr[idx] = '\0';
			break;
		}
	}

	//reverse it
	numLen = strlen(tempArr);
	for(idx = numLen; idx-->0;)
	{
		numArr[idx2++] = tempArr[idx];
	}
	numArr[numLen] = '\0';
	
	//process it
	for(idx = numLen; idx --> 0;)
	{
		dig = numArr[idx] - '0';
		if(dig == 0)
			continue;
			
		isCombine = ((idx + 1) % 3 == 1) & (idx < numLen - 1) & (numArr[idx + 1] != '0');
		isMaster = ((idx + 1) % 3 == 2) & (numArr[idx - 1] != '0');
		isFinal = (((numLen > 1) & (numArr[1] == '0') &  (idx == 0))) | (numLen == 1);
		useThirdIdx = (numLen >= 6) &  ((idx + 1) % 3 == 0) &  (idx != 0) & ((numArr[idx-1] != '0') | (numArr[idx-2] != '0'));
		isDigitToRight = hasDigToRight(numArr, idx, numLen);
		isTenth = (idx == 1) & (numArr[idx] != '0') & (numArr[0] == '0'); 
		master_dig = '\0';
		if(isCombine)
			master_dig = numArr[idx+1];
		dig_str = get_dig_str(dig, master_dig, idx, isCombine, isMaster, isFinal, useThirdIdx, isDigitToRight,itemName, dualItemName, pluralItemName,ig);
		
		if(dig_str)
		{
			strLen = wcslen(dig_str);
			if(isMaster)
			{
				if(strLen > (MAX_DIGIT_NAME_LENGTH -1))
				{
					free(dig_str);
					if(result)
						free(result);
					return NULL;
				}
				wmemset(master_in_hold, L'\0', MAX_DIGIT_NAME_LENGTH);
				n2a_wcscpy(master_in_hold, dig_str, MAX_DIGIT_NAME_LENGTH);
				master_in_hold[strLen] = L'\0';
			}
			else
			{
				if(result)
				{
					if(isCombine)
					{
						in_hold_len = wcslen(master_in_hold);
						
						tmp_len = wcslen(result);
						bkPtr = result;
						if(numArr[idx+1] == '1')
							tmp_len = wcslen(result) + 3 + strLen + 1 + in_hold_len + 1;
						else
							tmp_len = wcslen(result) + 3 + strLen + 3 + in_hold_len + 1;
						result = realloc(result, tmp_len * sizeof(wchar_t));
						if(result == NULL)
						{
							free(dig_str);
							free(bkPtr);
							return NULL;
						}

						n2a_wcscat(result, tmp_len, STR_AND);

						n2a_wcscat(result, tmp_len, dig_str);
						
						
						if(numArr[idx+1] == '1')
							n2a_wcscat(result, tmp_len, STR_SPACE);
						else
							n2a_wcscat(result, tmp_len, STR_AND);
						

						
						n2a_wcscat(result, tmp_len, master_in_hold);
						
						if(idx > 2 && isDigitToRight)
						{
							add_dig_str_tanween(&result, tmp_len);
							if(!result)
							{
								free(dig_str);
								return NULL;
							}
						}						
						
					}
					else
					{
						bkPtr = result;
						tmp_len = wcslen(result) + 3 + strLen + 1;
						result = realloc(result, tmp_len * sizeof(wchar_t));
						if(result == NULL)
						{
							free(dig_str);
							free(bkPtr);
							return NULL;
						}
						n2a_wcscat(result, tmp_len, STR_AND);
						n2a_wcscat(result, tmp_len, dig_str);
					}
				}
				else
				{
					//First readed digit 
					if(isCombine)
					{
						in_hold_len = wcslen(master_in_hold);
						if(numArr[idx+1] == '1')
							tmp_len = strLen + 1 + in_hold_len + 1;
						else
							tmp_len = strLen + 3 + in_hold_len + 1;
						result = (wchar_t *) malloc(tmp_len * sizeof(wchar_t));
						if(result)
						{
							n2a_wcscpy(result, dig_str, tmp_len);
							result[strLen] = L'\0'; 
							if(numArr[idx+1] == '1')
								n2a_wcscat(result, tmp_len, STR_SPACE);
							else
								n2a_wcscat(result, tmp_len, STR_AND);
							n2a_wcscat(result, tmp_len, master_in_hold);
							if(idx > 2 && isDigitToRight )
							{
								add_dig_str_tanween(&result, tmp_len);
								if(!result)
								{
									free(dig_str);
									return NULL;
								}
							}
						}
						else
						{
							free(dig_str);
							return NULL;
						}
					}
					else
					{
						result = (wchar_t *) malloc((strLen + 1) * sizeof(wchar_t));
						if(result)
						{
							n2a_wcscpy(result, dig_str, strLen + 1);
							result[strLen] = L'\0'; 
						}
						else
						{
							free(dig_str);
							return NULL;
						}
					}
				}
			}
			free(dig_str);
			dig_str = NULL;
		}
		else
		{
			return NULL;
		}
		
	}
	
	//add the negative sign and the itemName if not added before
	if(result)
	{
		if(!isFinal)
		{
			if (((numLen > 1) & (numArr[0] == '0') & (numArr[1] == '1'))) 
				tmp_len = wcslen(result) + 1 + wcslen(pluralItemName) + 1;
			else
			{
				if(isCombine||isTenth)
					tmp_len = wcslen(result) + 1 + wcslen(itemNameWithTanween) + 1;
				else
					tmp_len = wcslen(result) + 1 + wcslen(itemName) + 1;
			}
			bkPtr = result;
			result = realloc(result, tmp_len * sizeof(wchar_t));
			if(!result)
			{
				free(bkPtr);
				return NULL;
			}
			n2a_wcscat(result, tmp_len, STR_SPACE);
			if (((numLen > 1) & (numArr[0] == '0') & (numArr[1] == '1'))) 
				n2a_wcscat(result, tmp_len, pluralItemName);
			else
			{
				if(isCombine || isTenth)
					n2a_wcscat(result, tmp_len, itemNameWithTanween);
				else
					n2a_wcscat(result, tmp_len, itemName);
			}
			
		}
		
		if(isNegative && !isFractionalOnly)
		{
			tResult = WCSDUP(result);
			if(!tResult)
			{
				free(result);
				return NULL;
			}
			bkPtr = result;
			tmp_len = wcslen(STR_NEGATIVE_SIGN) + 1 +  wcslen(result) + 1;
			result = realloc(result, tmp_len * sizeof(wchar_t));
			if(!result)
			{
				free(bkPtr);
				return NULL;
			}
			n2a_wcscpy(result, STR_NEGATIVE_SIGN, tmp_len);
			result[wcslen(STR_NEGATIVE_SIGN)] = L'\0';
			n2a_wcscat(result, tmp_len, STR_SPACE);
			n2a_wcscat(result, tmp_len, tResult);
			free(tResult);
			
		}
	}
	
	return result;
	
}


MODULE_API wchar_t * CALL_CONV num2aW(
								double num, 
								const wchar_t *itemName, 
								const wchar_t *itemNameWithTanween,
								const wchar_t *dualItemName,
								const wchar_t *pluralItemName,
								ItemGender ig
								)
{
	return process_numW(num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig, 0);
}

MODULE_API int CALL_CONV get_num2aW(
								wchar_t *dest,
								size_t dest_len,
								double num, 
								const wchar_t *itemName, 
								const wchar_t *itemNameWithTanween,
								const wchar_t *dualItemName,
								const wchar_t *pluralItemName,
								ItemGender ig
								)
{
	size_t len = 0;
	wchar_t *result = num2aW(num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig);
	if(!result)
		return 0;
	len = wcslen(result);
	if((len+1) > dest_len)
		return 0;
	n2a_wcscpy(dest, result, len +1);
	dest[len] = L'\0';
	free(result);
	return 1;
}



MODULE_API wchar_t * CALL_CONV fnum2aW(
								double num, 
								const wchar_t *itemName, 
								const wchar_t *itemNameWithTanween,
								const wchar_t *dualItemName,
								const wchar_t *pluralItemName,
								ItemGender ig,
								const wchar_t *fractionalItemName,
								const wchar_t *fractionalItemNameWithTanween,
								const wchar_t *fractionalDualItemName,
								const wchar_t *fractionalPluralItemName,
								ItemGender fig,
								int decimalPlace
								)
{
	wchar_t *result = NULL;
	wchar_t *fresult = NULL, *bkPtr = NULL;
	wchar_t *tmpStr = NULL;
	double f = 0;
	int useFractionalItemName = 0, is_empty_int = 0, leadingZeros = 0, idx = 0, isNegative = 0;
	size_t len = 0, tmp_len = 0;
	result = process_numW(num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig, 0);
	
	
	useFractionalItemName = ((fractionalDualItemName != NULL) & (fractionalItemName != NULL) & (fractionalPluralItemName != NULL) & 
							(fractionalItemNameWithTanween != NULL)) &&
							((wcslen(fractionalDualItemName) > 0) & (wcslen(fractionalItemName) > 0) & (wcslen(fractionalPluralItemName) > 0) & 
							(wcslen(fractionalItemNameWithTanween) > 0)) && (decimalPlace > 0);
	if(!useFractionalItemName)
		decimalPlace = 0;
		
	if(num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	f = get_fractional_part(num, decimalPlace, &leadingZeros);

							
	
	if(f != 0)
	{
		if(useFractionalItemName)
			fresult = process_numW(f, fractionalItemName, fractionalItemNameWithTanween, fractionalDualItemName, fractionalPluralItemName, fig, 1);
		else
			fresult = process_numW(f, L"", L"", L"", L"", fig, 1);
		if(!fresult)
		{
			if(result)
				free(result);
			return NULL;
		}
		
		//عند عدم وجود اسم لكسر المعدود يجب قراء الاصفار في بداية الرقم العشري
		// 1.005 -> واحد فاصلة صفر صفر خمسة
		if(!useFractionalItemName && leadingZeros > 0)
		{
		
			len = wcslen(STR_ZERO_NAME);
			for(idx = 0; idx < leadingZeros; idx ++)
			{
				tmpStr = WCSDUP(fresult);
				bkPtr = fresult;
				tmp_len =  len + 1 + wcslen(fresult) + 1;
				fresult = realloc(fresult, tmp_len * sizeof(wchar_t));
				if(!fresult)
				{
					free(bkPtr);
					return NULL;
				}
				n2a_wcscpy(fresult, STR_ZERO_NAME, tmp_len);
				fresult[len]= L'\0';
				n2a_wcscat(fresult, tmp_len, STR_SPACE);
				n2a_wcscat(fresult, tmp_len, tmpStr);
				free(tmpStr);
			}
		}
		
		if(!result)
		{
			is_empty_int = 1;
			if(useFractionalItemName)
			{
				
				if(isNegative)
				{
					tmp_len = wcslen(STR_NEGATIVE_SIGN) + 1 +1;
					result = (wchar_t *) malloc(tmp_len * sizeof(wchar_t));
					if(!result)
					{
						if(fresult)
							free(fresult);
						return NULL;
					}
					n2a_wcscpy(result, STR_NEGATIVE_SIGN, tmp_len);
					result[wcslen(STR_NEGATIVE_SIGN)] = L'\0';
					n2a_wcscat(result, tmp_len, STR_SPACE);
				}
				else  
					result = WCSDUP(L"");
			}
			else
			{
				if(isNegative)
				{
					tmp_len = wcslen(STR_NEGATIVE_SIGN) + 1 + wcslen(STR_ZERO_NAME) + 1 + 1;
					result = (wchar_t *) malloc(tmp_len * sizeof(wchar_t));
					if(!result)
					{
						if(fresult)
							free(fresult);
						return NULL;
					}
					n2a_wcscpy(result, STR_NEGATIVE_SIGN, tmp_len);
					result[wcslen(STR_NEGATIVE_SIGN)] = L'\0';
					n2a_wcscat(result, tmp_len, STR_SPACE);
					n2a_wcscat(result, tmp_len, STR_ZERO_NAME);
					n2a_wcscat(result, tmp_len, STR_SPACE);
				}
				else
					result = WCSDUP(STR_ZERO_NAME);
			}
		}
		
		if(useFractionalItemName)
		{
			if(is_empty_int)
				len = wcslen(fresult) + 1;
			else
				len = wcslen(result) + 3 + wcslen(fresult) + 1;
		}
		else
			len = wcslen(result) + 1 + wcslen(STR_POINT_NAME) + 1 + wcslen(fresult) + 1;
		
		bkPtr = result;
		result = realloc(result, len * sizeof(wchar_t));
		if(!result)
		{
			free(bkPtr);
			return NULL;
		}
		if(useFractionalItemName)
		{
			if(!is_empty_int)
				n2a_wcscat(result, len, STR_AND);
		}
		else
		{
			n2a_wcscat(result, len, STR_SPACE);
			n2a_wcscat(result, len, STR_POINT_NAME);
			n2a_wcscat(result, len, STR_SPACE);
		}
		n2a_wcscat(result, len, fresult);
		free(fresult);
	}
	
	return result;
}


MODULE_API int CALL_CONV get_fnum2aW(
							wchar_t *dest,
							size_t dest_len,								
							double num, 
							const wchar_t *itemName, 
							const wchar_t *itemNameWithTanween,
							const wchar_t *dualItemName,
							const wchar_t *pluralItemName,
							ItemGender ig,
							const wchar_t *fractionalItemName,
							const wchar_t *fractionalItemNameWithTanween,
							const wchar_t *fractionalDualItemName,
							const wchar_t *fractionalPluralItemName,
							ItemGender fig,
							int decimalPlace
							)
{
	size_t len = 0;
	wchar_t *result = fnum2aW(num, itemName, itemNameWithTanween, dualItemName, pluralItemName, ig, 
								fractionalItemName, fractionalItemNameWithTanween, fractionalDualItemName, 
								fractionalPluralItemName, fig, decimalPlace);
	if(!result)
		return 0;
	len = wcslen(result);
	if((len+1) > dest_len)
		return 0;
	n2a_wcscpy(dest, result, len+1);
	dest[len] = L'\0';
	free(result);
	return 1;
}


MODULE_API void CALL_CONV n2a_clean(void *ptr)
{
	if(ptr)
		free(ptr);
}





