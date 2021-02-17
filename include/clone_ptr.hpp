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
 * File:   clone_ptr.hpp
 * Author: annas
 *
 * Created on 11. November 2016, 06:19
 */

#ifndef _STL_CLONE_PTR_HPP_
#define _STL_CLONE_PTR_HPP_

#include "common.hpp"
#include "save_ptr.hpp"

namespace std
{
    template<typename T>
    class clone_ptr_interface {
    protected:
        using pointer = T*;

        virtual pointer clone(pointer src) {
            pointer _clone = NULL;
            
            if(other != NULL) {
                _clone = new value_type();
                memcpy(_clone, src, sizeof(src));
            }
            return _clone;
        }
    };
    
    template<typename T, class TInterface = clone_ptr_interface<T> >
    class clone_ptr : public TInterface
    {
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using self_type = clone_ptr<value_type, TInterface<T> >;
        using cloneptrinterface = TInterface;
        
        clone_ptr() : m_ptr(0) { }
        explicit clone_ptr(T *v) : m_ptr(v) { }
        
        //clone_ptr(save_ptr const &other) { if(other.get() != NULL)  m_ptr = other->clone(); }
        clone_ptr(const self_type& other) { if(other.get() != NULL)  m_ptr = other->clone(); }

        ~clone_ptr() { if(m_ptr) delete m_ptr; }

        pointer const get() const               { return m_ptr;  }
        pointer get()                           { return m_ptr;  }
 
        value_type const &operator *() const    { return *m_ptr; }
        value_type &operator *()                { return *m_ptr; }

        pointer const *operator->() const       { return m_ptr; }
        pointer operator->()                    { return m_ptr; }
        pointer release()                       { pointer tmp = m_ptr;  m_ptr = NULL; return tmp; }

        void reset(pointer p = NULL)            { if(m_ptr) delete m_ptr; m_ptr = p; }

        void swap(self_type &other) { 
            pointer tmp = clone();             
            
            reset(other->clone());
            other.reset(tmp);
        }

        self_type& const &operator = (const self_type& other) {
            if(other != this) clone_ptr tmp(other); return *this;
        }
    
        pointer clone() {
            return TInterface::clone(m_ptr);
        }
    private:
        pointer m_ptr;
    };
}
#endif /* CLONE_PTR_HPP */

