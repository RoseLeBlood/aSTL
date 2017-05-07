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
 * File:   property.hpp
 * Author: annas
 *
 * Created on 26. November 2016, 18:53
 */

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include "auto_ptr.hpp"

namespace std
{

    template <typename T, class C>
    class iproperty_base 
    {
    public:
        using value_type = T;
        using cont_type = C;
        using self_type = iproperty_base<value_type, cont_type>;
        
        iproperty_base(cont_type* ctype, const T(cont_type::*pget)()) 
            :  m_pContainer(ctype) { 
            m_pSetter = (void*)0;
            m_pGetter = pget;
        }
        iproperty_base(cont_type* ctype, void (cont_type::*pset)(const T& value)) 
            :  m_pContainer(ctype) { 
            m_pSetter = pset;
            m_pGetter = (void*)0;
        }
        iproperty_base(cont_type* ctype, void (cont_type::*pset)(const T& value), const T(cont_type::*pget)()) 
            :  m_pContainer(ctype) { 
            m_pSetter = pset;
            m_pGetter = pget;
        }
        value_type operator = (const value_type& value) {
            assert(m_pContainer != NULL);
            assert(m_pSetter != NULL);
            (m_pContainer->*m_pSetter)(value);
            return value;
        }
        explicit operator value_type() {
            assert(m_pContainer != NULL);
            assert(m_pGetter != NULL);
            return (m_pContainer->*m_pGetter)();
        }
    private:
        cont_type* m_pContainer;
        void (cont_type::*m_pSetter)(const value_type& value);
        const value_type (cont_type::*m_pGetter)();
    }; 
    
    
    
    template <typename T, bool read = true, bool write = false>
    class value_property 
    {
    public:
         using value_type = T;
         using self_type = value_property<T, read, write>;
          
        value_property() { }
        explicit value_property(value_type value) 
            :  m_tValue(value) { 
        }
        bool can_read() { return read; }
        bool can_write() { return write; }
        
        value_type operator = (const value_type& value) {
            assert(write);
            set(value);
            return value;
        }
        explicit operator value_type() {
            assert(read);
            return get();
        }
    protected:
        virtual void set(const value_type& value) {  m_tValue = value; } 
        virtual const value_type get() { return m_tValue; }
    private:
        value_type m_tValue;
    };
   
    typedef value_property<int8_t>                      setp8_t;
    typedef value_property<uint8_t>                     setpu8_t;
    typedef value_property<int16_t>                     setp16_t;
    typedef value_property<uint16_t>                    setpu16_t;
    typedef value_property<int32_t>                     setp32_t;
    typedef value_property<uint32_t>                    setpu32_t;
    typedef value_property<int64_t>                     setp64_t;
    typedef value_property<uint64_t>                    setpu64_t;
    typedef value_property<float>                       setpf_t;
    typedef value_property<double>                      setpd_t;
    typedef value_property<bool>                        setpb_t;
    
    
    typedef value_property<int8_t, false, true>         getp8_t;
    typedef value_property<uint8_t, false, true>        getpu8_t;
    typedef value_property<int16_t, false, true>        getp16_t;
    typedef value_property<uint16_t, false, true>       getpu16_t;
    typedef value_property<int32_t, false, true>        getp32_t;
    typedef value_property<uint32_t, false, true>       getpu32_t;
    typedef value_property<int64_t, false, true>        getp64_t;
    typedef value_property<uint64_t, false, true>       getpu64_t;
    typedef value_property<float, false, true>          getpf_t;
    typedef value_property<double, false, true>         getpd_t;
    typedef value_property<bool, false, true>           getpb_t;
    
    typedef value_property<int8_t, true, true>          prop8_t;
    typedef value_property<uint8_t, true, true>         propu8_t;
    typedef value_property<int16_t, true, true>         prop16_t;
    typedef value_property<uint16_t, true, true>        propu16_t;
    typedef value_property<int32_t, true, true>         prop32_t;
    typedef value_property<uint32_t, true, true>        propu32_t;
    typedef value_property<int64_t, true, true>         prop64_t;
    typedef value_property<uint64_t, true, true>        propu64_t;
    typedef value_property<float, true, true>           propf_t;
    typedef value_property<double, true, true>          propd_t;
    typedef value_property<bool, true, true>            propb_t;
    
    template <typename T> using setp_t = value_property<T, true, false>;
    template <typename T> using getp_t = value_property<T, false, true>;
    template <typename T> using prop_t = value_property<T, true, true>;
}

#endif /* PROPERTY_HPP */

