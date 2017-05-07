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

#include "include/mutex.hpp"



namespace std
{

    mutex::mutex(Sys::mutex_init_t type, 
              bool shared, bool robust)
    {
        Sys::mutexInit(_m_locked, type, shared, robust);
    }
    mutex::~mutex()
    {
        unlock();
        Sys::mutexDestroy( _m_locked );
        delete _m_locked;
    }
    void mutex::lock()
    {
        Sys::mutexLock( _m_locked );
    }
    void mutex::unlock()
    {
        Sys::mutexUnLock( _m_locked );
    }
    bool mutex::try_lock()
    {
       return  Sys::mutexTryLock( _m_locked ) == 0;
    }
    mutex::native_handle_type mutex::native_handle()
    {
        return _m_locked;
    }
    mutex& mutex::operator=(const mutex& m) {
        _m_locked = m._m_locked;
        return *this;
    }
    mutex::mutex(const mutex& m) {
        _m_locked = m._m_locked;
    }
}