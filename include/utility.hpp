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
 * File:   utility.hpp
 * Author: annas
 *
 * Created on 7. November 2016, 00:18
 */

#ifndef _STD_UTILITY_H_
#define _STD_UTILITY_H_

#include "common.hpp"
#include "new.hpp"
#include "inttokey.hpp"

/// Shorthand for container iteration.
#define foreach(type,i,ctr)	for (type i = (ctr).begin(); i != (ctr).end(); ++ i)
/// Shorthand for container reverse iteration.
#define eachfor(type,i,ctr)	for (type i = (ctr).rbegin(); i != (ctr).rend(); ++ i)

#define TEMPLATE_FULL_DECL1(d1,t1)		template <d1 t1>
#define TEMPLATE_FULL_DECL2(d1,t1,d2,t2)	template <d1 t1, d2 t2>
#define TEMPLATE_FULL_DECL3(d1,t1,d2,t2,d3,t3)	template <d1 t1, d2 t2, d3 t3>
#define TEMPLATE_DECL1(t1)		TEMPLATE_FULL_DECL1(typename,t1)
#define TEMPLATE_DECL2(t1,t2)		TEMPLATE_FULL_DECL2(typename,t1,typename,t2)
#define TEMPLATE_DECL3(t1,t2,t3)	TEMPLATE_FULL_DECL3(typename,t1,typename,t2,typename,t3)
#define TEMPLATE_TYPE1(type,a1)		type<a1>
#define TEMPLATE_TYPE2(type,a1,a2)	type<a1,a2>
#define TEMPLATE_TYPE3(type,a1,a2,a3)	type<a1,a2,a3>


namespace std
{
	namespace internal {
        TEMPLATE_FULL_DECL1(typename, T)
        void copy_n(const T* first, size_t n, T* result, int_to_type<false>) {
            const T* last = first + n;

            while (first != last) {
                switch (n & 0x3) {
                    case 0: *result++ = *first++;
                    case 3: *result++ = *first++;
                    case 2: *result++ = *first++;
                    case 1: *result++ = *first++;
                }
            }
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void copy_n(const T* first, size_t n, T* result, int_to_type<true>) {
            assert(result >= first + n || result < first);
            memcpy(result, first, n * sizeof(T));
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void copy(const T* first, const T* last, T* result, int_to_type<false>) {
            T* localResult = result;
            while (first != last)
                *localResult++ = *first++;
        }
        TEMPLATE_FULL_DECL1(typename, T)
        void copy(const T* first, const T* last, T* result, int_to_type<true>) {
            const size_t n = reinterpret_cast<const char*>(last) - reinterpret_cast<const char*>(first);
            memcpy(result, first, n);
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void move_n(const T* from, size_t n, T* result, int_to_type<false>) {
            for (int i = int(n) - 1; i >= 0; --i)
                    result[i] = from[i];
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void move_n(const T* first, size_t n, T* result, int_to_type<true>) {
            memmove(result, first, n * sizeof(T));
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void move(const T* first, const T* last, T* result, int_to_type<false>) {
            result += (last - first);
            while (--last >= first)
                    *(--result) = *last;
        }
        TEMPLATE_FULL_DECL1(typename, T)
        inline  void move(const T* first, const T* last, T* result, int_to_type<true>) {
            const size_t n = reinterpret_cast<uintptr_t>(last) - reinterpret_cast<uintptr_t>(first);
            memmove(result, first, n);
        }
		

        TEMPLATE_FULL_DECL1(typename, T)
        void copy_construct_n(const T* first, size_t n, T* result, int_to_type<false>) {
            for (size_t i = 0; i < n; ++i)
                new (result + i) T(first[i]);
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void copy_construct_n(const T* first, size_t n, T* result, int_to_type<true>) {
            assert(result >= first + n || result < first);
            memcpy(result, first, n * sizeof(T));
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void destruct_n(T* first, size_t n, int_to_type<false>) {
            sizeof(first);
            for (size_t i = 0; i < n; ++i)
                    (first + i)->~T();
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void destruct_n(T*, size_t, int_to_type<true>) {
            // Nothing to do, no destructor needed.
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void destruct(T* mem, int_to_type<false>) {
            sizeof(mem);
            mem->~T();
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void destruct(T*, int_to_type<true>) {
             // Nothing to do, no destructor needed.
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void construct(T* mem, int_to_type<false>) {
            new (mem) T();
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void construct(T*, int_to_type<true>) {
            // Nothing to do
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void copy_construct(T* mem, const T& orig, int_to_type<false>) {
            new (mem) T(orig);
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void copy_construct(T* mem, const T& orig, int_to_type<true>) {
            mem[0] = orig;
        }

        TEMPLATE_FULL_DECL1(typename, T)
        void construct_n(T* to, size_t count, int_to_type<false>) {
            sizeof(to);
            for (size_t i = 0; i < count; ++i)
                    new (to + i) T();
        }

        TEMPLATE_FULL_DECL1(typename, T)
        inline void construct_n(T*, int, int_to_type<true>) {
            // trivial ctor, nothing to do.
        }

        TEMPLATE_FULL_DECL2(class, TIter, class, TPred)
        void test_ordering(TIter first, TIter last, const TPred& pred) {
        	sizeof(first); sizeof(last); sizeof(pred);
        }

        TEMPLATE_FULL_DECL3(typename, T1, typename, T2, class, TPred)
        inline bool debug_pred(const TPred& pred, const T1& a, const T2& b) {
         	return pred(a, b);
        }
    }
	TEMPLATE_FULL_DECL1(typename, T) 
    struct less {
        bool operator()(const T& lhs, const T& rhs) const {
            return lhs < rhs;
        }
	};
	TEMPLATE_FULL_DECL1(typename, T) 
    struct greater {
        bool operator()(const T& lhs, const T& rhs) const {
            return lhs > rhs;
        }
	};
	TEMPLATE_FULL_DECL1(typename, T) 
    struct equal_to {
        bool operator()(const T& lhs, const T& rhs) const {
            return lhs == rhs;
        }
	};
    
	TEMPLATE_FULL_DECL1(typename, T) 
    T nexthigher(T k) {
		k--;
		for (unsigned int i=1; i< sizeof(T) * 8; i <<= 1)
			k |= (k >> i);
		return k+1;
	}
}
#endif


