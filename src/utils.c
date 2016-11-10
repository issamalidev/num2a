/**
 * @file utils.c
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

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdarg.h>
#include "utils.h"



int n2a_sprintf(
	char *buffer,
	size_t sizeOfBuffer,
	const char *format,
	... 
	)
{
	int result = -1;
	va_list ap;
	va_start(ap, format);
	#ifdef _MSC_VER
	result = vsprintf_s(buffer, sizeOfBuffer, format, ap);
	#else
	result = vsnprintf(buffer, sizeOfBuffer, format, ap);
	#endif
	va_end(ap);
	return result;
}

int n2a_swprintf(
	wchar_t *buffer,
	size_t count,
	const wchar_t *format,
	...
	)
{
	int result = -1;
	va_list ap;
	va_start(ap, format);	
	#ifdef __MINGW32__
	result = vsnwprintf(buffer, count, format, ap); 
	buffer[count-1] = L'\0';
	#else
	result = vswprintf(buffer, count, format, ap);
	buffer[count-1] = L'\0';
	#endif
	return result;
}

wchar_t * n2a_wcscpy(
	wchar_t* dest, 
	const wchar_t *src, 
	size_t count
	)
{
	#ifdef _MSC_VER
	wcsncpy_s(dest, count, src, _TRUNCATE);
	#else
	wcsncpy(dest, src, count);
	dest[count -1] = L'\0';
	#endif
	return dest;
}

wchar_t * n2a_wcscat(
		wchar_t *dest,
		size_t sizeOfBuffer,
		const wchar_t *src
		)
{
	#ifdef _MSC_VER
	wcsncat_s(dest, sizeOfBuffer, src, _TRUNCATE);
	#else
	wcscat(dest, src);
	#endif
	return dest;
}



wchar_t* n2a_wcsdup(const wchar_t* ptr)
{
    wchar_t* dup;
	size_t len = wcslen(ptr) + 1;
    dup = malloc( len * sizeof(wchar_t));
    if (dup == NULL) {
        return NULL;
    }
    n2a_wcscpy(dup, ptr, len);
    return dup;
}		
		


