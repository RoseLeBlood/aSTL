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
 * File:   new.hpp
 * Author: annas
 *
 * Created on 7. November 2016, 00:11
 */

#ifndef __NEW_CXX_H__
#define __NEW_CXX_H__


void* operator new (unsigned int n);
void* operator new[] (unsigned int n);
void  operator delete (void* p);
void  operator delete[] (void* p);

void* operator new (unsigned int, void* p);
void* operator new[] (unsigned int, void* p);

void  operator delete  (void*, void*);
void  operator delete[](void*, void*);

void  operator delete (void* p, unsigned int);
void  operator delete[] (void* p, unsigned int);

namespace std
{
    typedef void (*new_handler)();

    new_handler set_new_handler (new_handler new_p);
    new_handler get_new_handler();
}
#endif


