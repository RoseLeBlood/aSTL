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
 * File:   lock_base.hpp
 * Author: annas
 *
 * Created on 17. November 2016, 21:08
 */

#ifndef LOCK_BASE_HPP
#define LOCK_BASE_HPP

#include "common.hpp"

namespace std
{
    class lock_base
    {
    public:
        lock_base() { }
        virtual ~lock_base() { }
        virtual void lock( void ) = 0;
        virtual bool try_lock() = 0;
	virtual void unlock( void ) = 0;
    private:
        lock_base(const lock_base&) { }
        lock_base& operator=(const lock_base&) { }
    };
    
     
    template < class T = std::lock_base> void lock(T* m1) { m1->lock(); }
    template < class T = std::lock_base> void unlock(T* m1) { m1->unlock(); }
    template < class T = std::lock_base> void try_lock(T* m1) { m1->try_lock(); }
     
    
    template <class T = std::lock_base> 
    class lock_util
    {
        public:
            explicit lock_util(T* rc) :  m_rc(rc) 
            { 
                m_rc->lock();
            }
            ~lock_util(void) 
            {
                m_rc->unlock();
            }
            operator bool() { return m_rc != 0; }
        private:
            T*		m_rc;
    };
    
    
}


#endif /* LOCK_BASE_HPP */

