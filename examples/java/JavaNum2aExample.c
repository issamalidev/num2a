/*
 * @file JavaNum2aExample.c
 * num2a Java wrapper using Java Native Interface (JNI) 
 * By Issam Ali  issamsoft.com
 */
 

#include <jni.h>
#include <stdlib.h>
#include "JavaNum2aExample.h"
#include <num2a.h>
#include <wchar.h>

#define MAX_NUMBER_NAME_LENGTH 2048

wchar_t *toWchr(JNIEnv *env, jbyteArray s)
{
    wchar_t *result = NULL;
	const wchar_t *buf = (wchar_t*) (*env)->GetByteArrayElements(env, s, NULL);
	int n = (*env)->GetArrayLength(env, s) / sizeof(wchar_t);
	result = malloc((n+1) * sizeof(wchar_t));
    //todo: if first byte is BOM (0xfeff), you should skip it.
	result = wcsncpy(result, buf, n);
	result[n] = L'\0';	
	(*env)->ReleaseByteArrayElements(env, s, (jbyte*) buf, 0);

    return result;
}

jbyteArray fromWchr(JNIEnv *env, const wchar_t *s)
{
    jbyteArray result = (*env)->NewByteArray(env, (wcslen(s))*sizeof(wchar_t));
	//todo: in some systems you may need to Add the BOM (0xfeff) in front .
	(*env)->SetByteArrayRegion(env, result, 0, (wcslen(s))*sizeof(wchar_t), (const jbyte*) s);
	
	return result;
}


JNIEXPORT jbyteArray JNICALL Java_JavaNum2aExample_num2aW (
		JNIEnv *env, 
		jclass cls, 
		jdouble num, 
		jbyteArray itemName, 
		jbyteArray itemNameWithTanween, 
		jbyteArray dualItemName, 
		jbyteArray pluralItemName, 
		jint ig
		)
{
	wchar_t *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName, *wRes;
	jbyteArray result = NULL;
	
	wItemName = toWchr(env, itemName);
	wItemNameWithTanween = toWchr(env, itemNameWithTanween);
	wDualItemName = toWchr(env, dualItemName);
	wPluralItemName = toWchr(env, pluralItemName);
	wRes = num2aW(num, wItemName, wItemNameWithTanween, wDualItemName, wPluralItemName, ig);
	if(wRes)
	{
	 result = fromWchr(env, wRes);
	 n2a_clean(wRes);
	}
	
	if(wItemName)
		free(wItemName);
	if(wItemNameWithTanween)
		free(wItemNameWithTanween);
	if(wDualItemName)
		free(wDualItemName);
	if(wPluralItemName)
		free(wPluralItemName);	
	return result;
}

JNIEXPORT jbyteArray JNICALL Java_JavaNum2aExample_fnum2aW(
		JNIEnv * env, 
		jclass cls, 
		jdouble num, 
		jbyteArray itemName, 
		jbyteArray itemNameWithTanween, 
		jbyteArray dualItemName, 
		jbyteArray pluralItemName, 
		jint ig, 
		jbyteArray fractionalItemName, 
		jbyteArray fractionalItemNameWithTanween, 
		jbyteArray fractionalDualItemName, 
		jbyteArray fractionalPluralItemName, 
		jint fig, 
		jint decimalPlace)
{
	wchar_t *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName, 
		*wFractionalItemName, *wFractionalItemNameWithTanween, *wFractionalDualItemName,
		*wFractionalPluralItemName, *wRes;
	jbyteArray result = NULL;
	
	wItemName = toWchr(env, itemName);
	wItemNameWithTanween = toWchr(env, itemNameWithTanween);
	wDualItemName = toWchr(env, dualItemName);
	wPluralItemName = toWchr(env, pluralItemName);
	wFractionalItemName = toWchr(env, fractionalItemName);
	wFractionalItemNameWithTanween = toWchr(env, fractionalItemNameWithTanween);
	wFractionalDualItemName = toWchr(env, fractionalDualItemName);
	wFractionalPluralItemName = toWchr(env, fractionalPluralItemName);
	wRes = fnum2aW(num, wItemName, wItemNameWithTanween, wDualItemName, wPluralItemName, ig,
					wFractionalItemName, wFractionalItemNameWithTanween, wFractionalDualItemName,
					wFractionalPluralItemName,fig, decimalPlace);
	if(wRes)
	{
	 result = fromWchr(env, wRes);
	 n2a_clean(wRes);
	}
	
	if(wItemName)
		free(wItemName);
	if(wItemNameWithTanween)
		free(wItemNameWithTanween);
	if(wDualItemName)
		free(wDualItemName);
	if(wPluralItemName)
		free(wPluralItemName);	
	if(wFractionalItemName)
		free(wFractionalItemName);
	if(wFractionalItemNameWithTanween)
		free(wFractionalItemNameWithTanween);
	if(wFractionalDualItemName)
		free(wFractionalDualItemName);
	if(wFractionalPluralItemName)
		free(wFractionalPluralItemName);
	return result;	
}

JNIEXPORT jbyteArray JNICALL Java_JavaNum2aExample_get_1num2aW(
	JNIEnv *env, 
	jclass cls, 
	jdouble num, 
	jbyteArray itemName, 
	jbyteArray itemNameWithTanween, 
	jbyteArray dualItemName, 
	jbyteArray pluralItemName, 
	jint ig
	)
{
	wchar_t *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName;
	wchar_t wRes[MAX_NUMBER_NAME_LENGTH];
	jbyteArray result = NULL;
	
	wItemName = toWchr(env, itemName);
	wItemNameWithTanween = toWchr(env, itemNameWithTanween);
	wDualItemName = toWchr(env, dualItemName);
	wPluralItemName = toWchr(env, pluralItemName);
	if(get_num2aW(wRes, MAX_NUMBER_NAME_LENGTH, num, wItemName, wItemNameWithTanween, wDualItemName, wPluralItemName, ig))
	{
	 result = fromWchr(env, wRes);
	}
	
	if(wItemName)
		free(wItemName);
	if(wItemNameWithTanween)
		free(wItemNameWithTanween);
	if(wDualItemName)
		free(wDualItemName);
	if(wPluralItemName)
		free(wPluralItemName);	
	return result;

}


JNIEXPORT jbyteArray JNICALL Java_JavaNum2aExample_get_1fnum2aW(
		JNIEnv * env, 
		jclass cls, 
		jdouble num, 
		jbyteArray itemName, 
		jbyteArray itemNameWithTanween, 
		jbyteArray dualItemName, 
		jbyteArray pluralItemName, 
		jint ig, 
		jbyteArray fractionalItemName, 
		jbyteArray fractionalItemNameWithTanween, 
		jbyteArray fractionalDualItemName, 
		jbyteArray fractionalPluralItemName, 
		jint fig, 
		jint decimalPlace
		)
{
	wchar_t *wItemName, *wItemNameWithTanween, *wDualItemName, *wPluralItemName, 
		*wFractionalItemName, *wFractionalItemNameWithTanween, *wFractionalDualItemName,
		*wFractionalPluralItemName, wRes[MAX_NUMBER_NAME_LENGTH];
	jbyteArray result = NULL;
	
	wItemName = toWchr(env, itemName);
	wItemNameWithTanween = toWchr(env, itemNameWithTanween);
	wDualItemName = toWchr(env, dualItemName);
	wPluralItemName = toWchr(env, pluralItemName);
	wFractionalItemName = toWchr(env, fractionalItemName);
	wFractionalItemNameWithTanween = toWchr(env, fractionalItemNameWithTanween);
	wFractionalDualItemName = toWchr(env, fractionalDualItemName);
	wFractionalPluralItemName = toWchr(env, fractionalPluralItemName);
	if(get_fnum2aW(wRes, MAX_NUMBER_NAME_LENGTH,  num, wItemName, wItemNameWithTanween, wDualItemName, wPluralItemName, ig,
			wFractionalItemName, wFractionalItemNameWithTanween, wFractionalDualItemName,
			wFractionalPluralItemName,fig, decimalPlace))
	{
	 result = fromWchr(env, wRes);
	}
	
	if(wItemName)
		free(wItemName);
	if(wItemNameWithTanween)
		free(wItemNameWithTanween);
	if(wDualItemName)
		free(wDualItemName);
	if(wPluralItemName)
		free(wPluralItemName);	
	if(wFractionalItemName)
		free(wFractionalItemName);
	if(wFractionalItemNameWithTanween)
		free(wFractionalItemNameWithTanween);
	if(wFractionalDualItemName)
		free(wFractionalDualItemName);
	if(wFractionalPluralItemName)
		free(wFractionalPluralItemName);
	return result;	
}




