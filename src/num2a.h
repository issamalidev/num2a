/**
 * @file num2a.h
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

#ifndef __NUM2A_H
#define __NUM2A_H



#include <wchar.h>




#ifdef __cplusplus
extern "C" {
#endif




#ifdef _WIN32
	#define CALL_CONV __cdecl
#ifdef BUILD_DLL
	#define MODULE_API __declspec(dllexport)
#else 
	#ifdef STATIC
		#define MODULE_API
	#else
		#define MODULE_API __declspec(dllimport)
	#endif
#endif
#else
	#define CALL_CONV
	#define MODULE_API
#endif

typedef enum  { IG_MALE = 0, IG_FEMALE = 1} ItemGender;

MODULE_API wchar_t *  CALL_CONV num2aW(
								double num, 							//العدد
								const wchar_t *itemName, 				//اسم المعدود
								const wchar_t *itemNameWithTanween,		//اسم المعدود منوناً
								const wchar_t *dualItemName,			//مثنى المعدود
								const wchar_t *pluralItemName,			//جمع المعدود
								ItemGender ig							//جنس المعدود 0 -> مذكر   1 -> مؤنث
								);

MODULE_API int CALL_CONV get_num2aW(
								wchar_t *dest,							//الذاكرة التي ستحتوي نتيجة التفقيط
								size_t dest_len,						//طول هذه الذاكرة
								double num, 							//العدد
								const wchar_t *itemName, 				//اسم المعدود
								const wchar_t *itemNameWithTanween,		//اسم المعدود منوناً
								const wchar_t *dualItemName,			//مثنى المعدود
								const wchar_t *pluralItemName,			//جمع المعدود
								ItemGender ig							//جنس المعدود 0 -> مذكر   1 -> مؤنث
								);								
								
MODULE_API wchar_t * CALL_CONV fnum2aW(
								double num, 									//العدد
								const wchar_t *itemName, 						//اسم المعدود
								const wchar_t *itemNameWithTanween,				//اسم المعدود منوناً
								const wchar_t *dualItemName,					//مثنى المعدود
								const wchar_t *pluralItemName,					//جمع المعدود
								ItemGender ig,									//جنس المعدود 0 -> مذكر   1 -> مؤنث
								const wchar_t *fractionalItemName,				//اسم كسر المعدود
								const wchar_t *fractionalItemNameWithTanween,	//اسم كسر المعدود منوناً
								const wchar_t *fractionalDualItemName,			//مثنى كسر المعدود
								const wchar_t *fractionalPluralItemName,		//جمع كسر المعدود
								ItemGender fig,									//جنس كسر المعدود 0 -> مذكر  1 -> مؤنث
								int decimalPlace								//خانة كسر المعدود  إذا كان يمثل 1/100 من المعدود تكون الخانة هنا 2  1/1000 تكون 3 وهكذا 
								);
								
MODULE_API int CALL_CONV get_fnum2aW(
								wchar_t *dest,									//الذاكرة التي ستحتوي نتيجة التفقيط
								size_t dest_len,								//طول هذه الذاكرة
								double num, 									//العدد
								const wchar_t *itemName, 						//اسم المعدود
								const wchar_t *itemNameWithTanween,				//اسم المعدود منوناً
								const wchar_t *dualItemName,					//مثنى المعدود
								const wchar_t *pluralItemName,					//جمع المعدود
								ItemGender ig,									//جنس المعدود 0 -> مذكر   1 -> مؤنث
								const wchar_t *fractionalItemName,				//اسم كسر المعدود
								const wchar_t *fractionalItemNameWithTanween,	//اسم كسر المعدود منوناً
								const wchar_t *fractionalDualItemName,			//مثنى كسر المعدود
								const wchar_t *fractionalPluralItemName,		//جمع كسر المعدود
								ItemGender fig,									//جنس كسر المعدود 0 -> مذكر  1 -> مؤنث
								int decimalPlace								//خانة كسر المعدود  إذا كان يمثل 1/100 من المعدود تكون الخانة هنا 2  1/1000 تكون 3 وهكذا 
								);								

MODULE_API void CALL_CONV n2a_clean(void *ptr);								

#ifdef __cplusplus
}
#endif

#endif
