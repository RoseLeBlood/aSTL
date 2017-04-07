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

namespace std
{
    class alignas(16) float4 {
    public:
        float4 () { m_xmm = _mm_set1_ps(0); }
        float4 (__m128 v) : m_xmm (v) {}
        float4 (const float4 &v) { m_xmm = v.m_xmm; }
        float4 (float v) { m_xmm = _mm_set1_ps(v); }
        float4 (float x, float y, float z, float w) { m_xmm = _mm_set_ps(w,z,y,x); }
        float4 (const float *v) { m_xmm = _mm_load_ps(v); }
        
       // float4 shuffle (int a, int b, int c, int d) const
       //     { return float4(_mm_shuffle_ps(m_xmm, m_xmm, _MM_SHUFFLE(d,c,b,a))); }
       // 
        
        float X () const { return ((float*)&m_xmm)[0]; }
        float Y () const { return ((float*)&m_xmm)[1]; }
        float Z () const { return ((float*)&m_xmm)[2]; }
        float W () const { return ((float*)&m_xmm)[3]; }
        
        
    private:
        __m128 m_xmm;
    };
}


#endif

#endif /* FLOAT_SSE_HPP */

