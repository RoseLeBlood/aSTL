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
 * File:   fixed_array.hpp
 * Author: annas
 *
 * Created on 7. November 2016, 23:22
 */

#ifndef _STL_FIXED_ARRAY_H
#define _STL_FIXED_ARRAY_H

#include "algorithm.hpp"

namespace std
{
	template<typename T, size_t N>
        class fixed_array
	{
	public:
            using value_type = T;
            using iterator = value_type*;
            using pointer = value_type*;
            using reference = value_type&;
            using const_iterator = const value_type*;
	    using size_type = size_t;  
	        
            fixed_array() { }
	    fixed_array(const T array[N]) {
	        std::copy_n(&array[0], N, m_data); }

            iterator begin() 
                { return &m_data[0]; }
	    const_iterator begin() const    
	        { return &m_data[0]; }
	    iterator end()                                  
	        { return begin() + N; }
	    const_iterator end() const              
	        { return begin() + N; }
	    size_type size() const  
	        { return N; }
	    pointer data()                               
	        { return &m_data[0]; }
	    const pointer data() const  
	        { return &m_data[0]; }

	    const reference front() const  
	        { return *begin(); }
	    reference front()                              
	        { return *begin(); }
	    const reference back() const   
	        { return *(end() - 1); }
	    reference back()                               
	        { return *(end() - 1); }

	    inline reference operator[](size_type i) {
	        assert(i < size());
	        return m_data[i];
	    }
	    inline const reference operator[](size_type i) const {
	        assert(i < size());
	        return m_data[i];
	    }
	private:
	    value_type m_data[N];
	};

} 
#endif 



