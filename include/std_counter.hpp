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
 * File:   std_counter.hpp
 * Author: annas
 *
 * Created on 18. April 2017, 20:46
 */

#ifndef STD_COUNTER_HPP
#define STD_COUNTER_HPP

#include "lock_ptr.hpp"

namespace std {
    class safe_counter {
    public:
        safe_counter() : m_iCount(0) {}
        safe_counter(int start) : m_iCount(start) {}
        
        safe_counter& operator ++() {
            ++(*lock_ptr<int>(m_iCount, m_mutex));
            return *this;
        }
        safe_counter& operator --() {
            --(*lock_ptr<int>(m_iCount, m_mutex));
            return *this;
        }
        int64_t count() {
            return *lock_ptr<int>(m_iCount, m_mutex);
        }
    protected:
        mutex m_mutex;
        volatile int m_iCount; 
    };
}


#endif /* STD_COUNTER_HPP */

