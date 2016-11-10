/**
 * @file utils.h
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

#ifndef __N2A_UTILS
#define __N2A_UTILS


#include <wchar.h>

#ifdef _MSC_VER
	#define WCSDUP _wcsdup
#else
	#ifdef _ndk
		#define WCSDUP n2a_wcsdup
	#else
		#define WCSDUP wcsdup
	#endif
#endif


#ifdef __cplusplus
extern "C" {
#endif

int n2a_sprintf(
	char *buffer,
	size_t sizeOfBuffer,
	const char *format,
	... 
	);

int n2a_swprintf(
	wchar_t *buffer,
	size_t count,
	const wchar_t *format,
	...
	);
	
wchar_t * n2a_wcscpy(
	wchar_t* dest, 
	const wchar_t *src, 
	size_t count
	);
	
wchar_t * n2a_wcscat(
		wchar_t *dest,
		size_t sizeOfBuffer,
		const wchar_t *src
		);

wchar_t* n2a_wcsdup(const wchar_t* ptr);

	
#ifdef __cplusplus
}
#endif

#endif
