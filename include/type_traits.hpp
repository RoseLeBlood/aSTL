/*
 * The MIT License
 *
 * Copyright 2016 annas.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   type_traits.hpp
 * Author: annas
 *
 * Created on 7. November 2016, 00:26
 */

#ifndef _STD_TYPETRAITS_H_
#define _STD_TYPETRAITS_H_

namespace std
{
	template<typename T> struct is_integral 
	{
	        enum { value = false };
	};

	template<typename T> struct is_floating_point
	{
	        enum { value = false };
	};

	#define STL_INTEGRAL(TYPE)      template<> struct is_integral<TYPE> { enum { value = true }; }

	STL_INTEGRAL(char);
	STL_INTEGRAL(unsigned char);
	STL_INTEGRAL(short);
	STL_INTEGRAL(unsigned short);
	STL_INTEGRAL(int);
	STL_INTEGRAL(unsigned int);
	STL_INTEGRAL(long);
	STL_INTEGRAL(unsigned long);
	STL_INTEGRAL(wchar_t);

	template<> struct is_floating_point<float> { enum { value = true }; };
	template<> struct is_floating_point<double> { enum { value = true }; };

	template<typename T> struct is_pointer
	{
	        enum { value = false };
	};
	template<typename T> struct is_pointer<T*>
	{
	        enum { value = true };
	};

	template<typename T> struct is_pod
	{
	        enum { value = false };
	};

	template<typename T> struct is_fundamental
	{
	        enum 
	        {
	                value = is_integral<T>::value || is_floating_point<T>::value
	        };
	};

	template<typename T> struct has_trivial_constructor
	{
	        enum
	        {
	                value = is_fundamental<T>::value || is_pointer<T>::value || is_pod<T>::value
	        };
	};

	template<typename T> struct has_trivial_copy
	{
	        enum
	        {
	                value = is_fundamental<T>::value || is_pointer<T>::value || is_pod<T>::value
	        };
	};

	template<typename T> struct has_trivial_assign
	{
	        enum
	        {
	                value = is_fundamental<T>::value || is_pointer<T>::value || is_pod<T>::value
	        };
	};

	template<typename T> struct has_trivial_destructor
	{
	        enum
	        {
	                value = is_fundamental<T>::value || is_pointer<T>::value || is_pod<T>::value
	        };
	};

	template<typename T> struct has_cheap_compare
	{
	        enum
	        {
	                value = has_trivial_copy<T>::value && sizeof(T) <= 4
	        };
	};

} 

#endif 



