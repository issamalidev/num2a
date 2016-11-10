#ifdef _WIN32   
#include "zend_config.w32.h"    
#endif

#include "php.h"

#include <glib.h>

#include "../../../../../../src/num2a.h"


#ifdef _WIN32
#define UTF8_TO_WIDECHAR g_utf8_to_utf16
#define WIDECHAR_TO_UTF8 g_utf16_to_utf8
#define UNICHAR gunichar2
#else
#define UTF8_TO_WIDECHAR g_utf8_to_ucs4
#define WIDECHAR_TO_UTF8 g_ucs4_to_utf8
#define UNICHAR gunichar
#endif

#define MAX_NUMBER_NAME 2048


ZEND_FUNCTION(num2a_num2aW);
ZEND_FUNCTION(num2a_get_num2aW);
ZEND_FUNCTION(num2a_fnum2aW);
ZEND_FUNCTION(num2a_get_fnum2aW);


 
zend_function_entry CustomExtModule_functions[] = {    
   ZEND_FE(num2a_num2aW, NULL)
   ZEND_FE(num2a_get_num2aW, NULL)
   ZEND_FE(num2a_fnum2aW, NULL)
   ZEND_FE(num2a_get_fnum2aW, NULL)
    {NULL, NULL, NULL}    
};    

 
zend_module_entry CustomExtModule_module_entry = {    
    STANDARD_MODULE_HEADER,    
    "num2a Module by Issam Ali  issamsoft.com",    
    CustomExtModule_functions,    
    NULL, NULL, NULL, NULL, NULL,    
    NO_VERSION_YET, STANDARD_MODULE_PROPERTIES    
};    

  
ZEND_GET_MODULE(CustomExtModule)    


ZEND_FUNCTION(num2a_num2aW)
{
	double num;
	char *itemName;
	int itemName_len;
	char *itemNameWithTanween;
	int itemNameWithTanween_len;
	char *dualItemName;
	int dualItemName_len;
	char *pluralItemName;
	int pluralItemName_len;
	long ig;
	GError *error;
	UNICHAR * wres, *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName;
	int len = 0;
	char *cres = NULL, *phpRes = NULL;
	glong br, bw;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,    
		"dssssl", &num, &itemName, &itemName_len, &itemNameWithTanween, &itemNameWithTanween_len,
		&dualItemName, &dualItemName_len, &pluralItemName, &pluralItemName_len, &ig
							  ) == FAILURE){    
        RETURN_STRING("Bad parameters!", 1);    
    } 
	wItemName = UTF8_TO_WIDECHAR(itemName, -1, &br, &bw, &error);
	wItemNameWithTanween = UTF8_TO_WIDECHAR(itemNameWithTanween, -1, &br, &bw, &error);
	wDualItemName = UTF8_TO_WIDECHAR(dualItemName, -1, &br, &bw, &error);
	wPluralItemName = UTF8_TO_WIDECHAR(pluralItemName, -1, &br, &bw, &error);


	wres = num2aW(
				num, 
				wItemName, 
				wItemNameWithTanween,
				wDualItemName,
				wPluralItemName,
				ig
				);
	if(wres)
	{
		cres = WIDECHAR_TO_UTF8(wres, -1, &br, &bw, &error);
		if(cres)
		{
			phpRes = estrdup(cres);
			g_free(cres);
		}
		n2a_clean(wres);		
	}
	
	if(wItemName)
		g_free(wItemName);
	if(wItemNameWithTanween)
		g_free(wItemNameWithTanween);
	if(wDualItemName)
		g_free(wDualItemName);
	if(wPluralItemName)
		g_free(wPluralItemName);
	if(phpRes)
	{
		RETURN_STRING(phpRes, 0);
	}
	else
		RETURN_STRING("", 1);
}

ZEND_FUNCTION(num2a_get_num2aW)
{
	double num;
	char *itemName;
	int itemName_len;
	char *itemNameWithTanween;
	int itemNameWithTanween_len;
	char *dualItemName;
	int dualItemName_len;
	char *pluralItemName;
	int pluralItemName_len;
	long ig;
	GError *error;
	UNICHAR *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName;
	UNICHAR  wres[MAX_NUMBER_NAME];
	int len = 0;
	char *cres = NULL, *phpRes = NULL;
	glong br, bw;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,    
		"dssssl", &num, &itemName, &itemName_len, &itemNameWithTanween, &itemNameWithTanween_len,
		&dualItemName, &dualItemName_len, &pluralItemName, &pluralItemName_len, &ig
							  ) == FAILURE){    
        RETURN_STRING("Bad parameters!", 1);    
    } 
	wItemName = UTF8_TO_WIDECHAR(itemName, -1, &br, &bw, &error);
	wItemNameWithTanween = UTF8_TO_WIDECHAR(itemNameWithTanween, -1, &br, &bw, &error);
	wDualItemName = UTF8_TO_WIDECHAR(dualItemName, -1, &br, &bw, &error);
	wPluralItemName = UTF8_TO_WIDECHAR(pluralItemName, -1, &br, &bw, &error);


	if( get_num2aW(
				wres,
				MAX_NUMBER_NAME,
				num, 
				wItemName, 
				wItemNameWithTanween,
				wDualItemName,
				wPluralItemName,
				ig
				) == 1)
	{
		cres = WIDECHAR_TO_UTF8(wres, -1, &br, &bw, &error);
		if(cres)
		{
			phpRes = estrdup(cres);
			g_free(cres);
		}
	}
	
	if(wItemName)
		g_free(wItemName);
	if(wItemNameWithTanween)
		g_free(wItemNameWithTanween);
	if(wDualItemName)
		g_free(wDualItemName);
	if(wPluralItemName)
		g_free(wPluralItemName);
	if(phpRes)
	{
		RETURN_STRING(phpRes, 0);
	}
	else
		RETURN_STRING("", 1);
}



ZEND_FUNCTION(num2a_fnum2aW)
{
	double num;
	char *itemName;
	int itemName_len;
	char *itemNameWithTanween;
	int itemNameWithTanween_len;
	char *dualItemName;
	int dualItemName_len;
	char *pluralItemName;
	int pluralItemName_len;
	long ig;
	GError *error;
	UNICHAR * wres, *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName;
	int len = 0;
	char *cres = NULL, *phpRes = NULL;
	glong br, bw;
	char *fractionalItemName;
	int fractionalItemName_len;
	char *fractionalItemNameWithTanween;
	int fractionalItemNameWithTanween_len;
	char *fractionalDualItemName;
	int fractionalDualItemName_len;
	char *fractionalPluralItemName;
	int fractionalPluralItemName_len;
	long fig;
	long decimalPlace;
	UNICHAR *wFractionalItemName, *wFractionalItemNameWithTanween, *wFractionalDualItemName, *wFractionalPluralItemName;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,    
		"dsssslssssll", &num, &itemName, &itemName_len, &itemNameWithTanween, &itemNameWithTanween_len,
		&dualItemName, &dualItemName_len, &pluralItemName, &pluralItemName_len, &ig,
		&fractionalItemName, &fractionalItemName_len, &fractionalItemNameWithTanween, &fractionalItemNameWithTanween_len,
		&fractionalDualItemName, &fractionalDualItemName_len, &fractionalPluralItemName, &fractionalPluralItemName_len,
		&fig, &decimalPlace) == FAILURE){    
        RETURN_STRING("Bad parameters!", 1);    
    } 
	wItemName = UTF8_TO_WIDECHAR(itemName, -1, &br, &bw, &error);
	wItemNameWithTanween = UTF8_TO_WIDECHAR(itemNameWithTanween, -1, &br, &bw, &error);
	wDualItemName = UTF8_TO_WIDECHAR(dualItemName, -1, &br, &bw, &error);
	wPluralItemName = UTF8_TO_WIDECHAR(pluralItemName, -1, &br, &bw, &error);
	wFractionalItemName = UTF8_TO_WIDECHAR(fractionalItemName, -1, &br, &bw, &error);
	wFractionalItemNameWithTanween = UTF8_TO_WIDECHAR(fractionalItemNameWithTanween, -1, &br, &bw, &error);
	wFractionalDualItemName = UTF8_TO_WIDECHAR(fractionalDualItemName, -1, &br, &bw, &error);
	wFractionalPluralItemName = UTF8_TO_WIDECHAR(fractionalPluralItemName, -1, &br, &bw, &error);

	wres = fnum2aW(
				num, 
				wItemName, 
				wItemNameWithTanween,
				wDualItemName,
				wPluralItemName,
				ig,
				wFractionalItemName,
				wFractionalItemNameWithTanween,
				wFractionalDualItemName,
				wFractionalPluralItemName,
				fig,
				decimalPlace
				);
	if(wres)
	{
		cres = WIDECHAR_TO_UTF8(wres, -1, &br, &bw, &error);
		if(cres)
		{
			phpRes = estrdup(cres);
			g_free(cres);
		}
		n2a_clean(wres);		
	}
	
	if(wItemName)
		g_free(wItemName);
	if(wItemNameWithTanween)
		g_free(wItemNameWithTanween);
	if(wDualItemName)
		g_free(wDualItemName);
	if(wPluralItemName)
		g_free(wPluralItemName);
	if(wFractionalItemName)
		g_free(wFractionalItemName);
	if(wFractionalItemNameWithTanween)
		g_free(wFractionalItemNameWithTanween);
	if(wFractionalDualItemName)
		g_free(wFractionalDualItemName);
	if(wFractionalPluralItemName)
		g_free(wFractionalPluralItemName);
	if(phpRes)
	{
		RETURN_STRING(phpRes, 0);
	}
	else
		RETURN_STRING("", 1);
}

ZEND_FUNCTION(num2a_get_fnum2aW)
{
	double num;
	char *itemName;
	int itemName_len;
	char *itemNameWithTanween;
	int itemNameWithTanween_len;
	char *dualItemName;
	int dualItemName_len;
	char *pluralItemName;
	int pluralItemName_len;
	long ig;
	GError *error;
	UNICHAR *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName;
	UNICHAR  wres[MAX_NUMBER_NAME];
	int len = 0;
	char *cres = NULL, *phpRes = NULL;
	glong br, bw;
	char *fractionalItemName;
	int fractionalItemName_len;
	char *fractionalItemNameWithTanween;
	int fractionalItemNameWithTanween_len;
	char *fractionalDualItemName;
	int fractionalDualItemName_len;
	char *fractionalPluralItemName;
	int fractionalPluralItemName_len;
	long fig;
	long decimalPlace;
	UNICHAR *wFractionalItemName, *wFractionalItemNameWithTanween, *wFractionalDualItemName, *wFractionalPluralItemName;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,    
		"dsssslssssll", &num, &itemName, &itemName_len, &itemNameWithTanween, &itemNameWithTanween_len,
		&dualItemName, &dualItemName_len, &pluralItemName, &pluralItemName_len, &ig,
		&fractionalItemName, &fractionalItemName_len, &fractionalItemNameWithTanween, &fractionalItemNameWithTanween_len,
		&fractionalDualItemName, &fractionalDualItemName_len, &fractionalPluralItemName, &fractionalPluralItemName_len,
		&fig, &decimalPlace) == FAILURE){    
        RETURN_STRING("Bad parameters!", 1);    
    } 
	wItemName = UTF8_TO_WIDECHAR(itemName, -1, &br, &bw, &error);
	wItemNameWithTanween = UTF8_TO_WIDECHAR(itemNameWithTanween, -1, &br, &bw, &error);
	wDualItemName = UTF8_TO_WIDECHAR(dualItemName, -1, &br, &bw, &error);
	wPluralItemName = UTF8_TO_WIDECHAR(pluralItemName, -1, &br, &bw, &error);
	wFractionalItemName = UTF8_TO_WIDECHAR(fractionalItemName, -1, &br, &bw, &error);
	wFractionalItemNameWithTanween = UTF8_TO_WIDECHAR(fractionalItemNameWithTanween, -1, &br, &bw, &error);
	wFractionalDualItemName = UTF8_TO_WIDECHAR(fractionalDualItemName, -1, &br, &bw, &error);
	wFractionalPluralItemName = UTF8_TO_WIDECHAR(fractionalPluralItemName, -1, &br, &bw, &error);

	if( get_fnum2aW(
				wres,
				MAX_NUMBER_NAME,
				num, 
				wItemName, 
				wItemNameWithTanween,
				wDualItemName,
				wPluralItemName,
				ig,
				wFractionalItemName,
				wFractionalItemNameWithTanween,
				wFractionalDualItemName,
				wFractionalPluralItemName,
				fig,
				decimalPlace
				) == 1)
	{
		cres = WIDECHAR_TO_UTF8(wres, -1, &br, &bw, &error);
		if(cres)
		{
			phpRes = estrdup(cres);
			g_free(cres);
		}
	}
	
	if(wItemName)
		g_free(wItemName);
	if(wItemNameWithTanween)
		g_free(wItemNameWithTanween);
	if(wDualItemName)
		g_free(wDualItemName);
	if(wPluralItemName)
		g_free(wPluralItemName);
	if(wFractionalItemName)
		g_free(wFractionalItemName);
	if(wFractionalItemNameWithTanween)
		g_free(wFractionalItemNameWithTanween);
	if(wFractionalDualItemName)
		g_free(wFractionalDualItemName);
	if(wFractionalPluralItemName)
		g_free(wFractionalPluralItemName);
	if(phpRes)
	{
		RETURN_STRING(phpRes, 0);
	}
	else
		RETURN_STRING("", 1);
}


