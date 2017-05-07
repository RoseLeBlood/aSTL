/*
 * The MIT License
 *
 * Copyright 2017 annas.
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
 * File:   float_sse.hpp
 * Author: annas
 *
 * Created on 7. April 2017, 23:30
 */

#ifndef FLOAT_SSE_HPP
#define FLOAT_SSE_HPP

#include "config.h"
#ifdef ASSTL_USE_SSE

#include <mmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>

#include "../algorithm.hpp"
#include "../common.hpp"
#include "../unknown.hpp"

namespace std
{
    namespace math {
        class alignas(16) vecf_sse;

        using vec2f_sse = vecf_sse;
        using vec3f_sse = vecf_sse;
        using vec4f_sse = vecf_sse;

        class alignas(16) vecf_sse : public object {
        public:
            vecf_sse () { m_xmm = _mm_set1_ps(0); }
            vecf_sse (__m128 v) : m_xmm (v) {}
            vecf_sse (const vecf_sse &v) { m_xmm = v.m_xmm; }

            vecf_sse (float v) { m_xmm = _mm_set1_ps(v); }
            vecf_sse (float x, float y) { m_xmm = _mm_set_ps(0,0,y,x); }
            vecf_sse (float x, float y, float z) { m_xmm = _mm_set_ps(0,z,y,x); }
            vecf_sse (float x, float y, float z, float w) { m_xmm = _mm_set_ps(w,z,y,x); }

            vecf_sse (const float *v) { m_xmm = _mm_load_ps(v); }


            float X () const { return ((float*)&m_xmm)[0]; }
            float Y () const { return ((float*)&m_xmm)[1]; }
            float Z () const { return ((float*)&m_xmm)[2]; }
            float W () const { return ((float*)&m_xmm)[3]; }

            __m128 M()  { return m_xmm; }

            void operator *= (const vecf_sse &v) { m_xmm = _mm_mul_ps(m_xmm, v.m_xmm); }
            void operator += (const vecf_sse &v) { m_xmm = _mm_add_ps(m_xmm, v.m_xmm); }
            void operator -= (const vecf_sse &v) { m_xmm = _mm_sub_ps(m_xmm, v.m_xmm); }
            void operator /= (const vecf_sse &v) { m_xmm = _mm_div_ps(m_xmm, v.m_xmm); }


        private:
            __m128 m_xmm;
        };
        inline vecf_sse operator + (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_add_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator - (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_sub_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator * (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_mul_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator / (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_div_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator & (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_and_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator ^ (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_xor_ps(a.M(), b.M() ));
        }
        inline vecf_sse operator | (const vecf_sse &a, const vecf_sse &b) const {
            return vecf_sse(_mm_or_ps(a.M(), b.M() ));
        }
        inline bool operator == (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() == b.X()) && (a.Y() == b.Y()) && (a.Z() == b.Z()) &&
                    (a.W() == b.W())); 
        }
        inline bool operator != (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() != b.X()) && (a.Y() != b.Y()) && (a.Z() != b.Z()) &&
                    (a.W() != b.W())); 
        } 
        inline bool operator <= (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() <= b.X()) && (a.Y() <= b.Y()) && (a.Z() <= b.Z()) &&
                    (a.W() <= b.W())); 
        } 
        inline bool operator >= (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() >= b.X()) && (a.Y() >= b.Y()) && (a.Z() >= b.Z()) &&
                    (a.W() >= b.W())); 
        } 
        inline bool operator < (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() < b.X()) && (a.Y() < b.Y()) && (a.Z() < b.Z()) &&
                    (a.W() < b.W())); 
        } 
        inline bool operator > (const vecf_sse& a, const vecf_sse& b) { 
            return ((a.X() > b.X()) && (a.Y() > b.Y()) && (a.Z() > b.Z()) &&
                    (a.W() > b.W())); 
        } 

        inline vecf_sse shuffle (const vecf_sse &v, int a, int b, int c, int d) const {
            return vecf_sse( _mm_shuffle_ps(v.M(), v.M(), _MM_SHUFFLE(d,c,b,a) ) );
        }
        inline vecf_sse shuffle (const vecf_sse &v1, const vecf_sse &v2, int a, int b, int c, int d) const {
            return vecf_sse( _mm_shuffle_ps(v1.M(), v2.M(), _MM_SHUFFLE(d,c,b,a) ) );
        }
        inline vecf_sse hadd (const vecf_sse &v) const { 
            return vecf_sse(_mm_hadd_ps(v.M(), v.M() )); 
        }
        inline vecf_sse hadd (const vecf_sse &a, const vecf_sse &b) const { 
            return vecf_sse(_mm_hadd_ps(a.M(), b.M() )); 
        }
        inline vecf_sse hsub (const vecf_sse &v) const { 
            return vecf_sse(_mm_hsub_ps(v.M(), v.M() )); 
        }
        inline vecf_sse hsub (const vecf_sse &a, const vecf_sse &b) const { 
            return vecf_sse(_mm_hsub_ps(a.M(), b.M() )); 
        }
        inline float sum (const vecf_sse& v) const {
            vecf_sse s = hadd(hadd(v), v);
            float t; _mm_store_ss(&t, s.M());
            return t;
        }
        inline float dot (const vecf_sse &a, const vecf_sse &b) const { 
            return sum(a * b); 
        }
        inline vecf_sse sqrt (const vecf_sse &v) const { 
            return vecf_sse(_mm_sqrt_ps(v.M() )); 
        }
        inline vecf_sse rsqrt (const vecf_sse &v) const { 
            return vecf_sse(_mm_rsqrt_ps(v.M() )); 
        }
        inline vecf_sse min (const vecf_sse &v) const { 
            return vecf_sse(_mm_min_ps(v.M() )); 
        }
        inline vecf_sse max (const vecf_sse &v) const { 
            return vecf_sse(_mm_max_ps(v.M() )); 
        }
        inline vecf_sse andnot (const vecf_sse &v) const { 
            return vecf_sse(_mm_andnot_ps(v.M() )); 
        }
        inline vecf_sse rcp (const vecf_sse &v) const { 
            return vecf_sse(_mm_rcp_ps(v.M() )); 
        }
    }   
}


#endif

#endif /* FLOAT_SSE_HPP */

