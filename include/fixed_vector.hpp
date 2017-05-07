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
 * File:   fixed_vector.hpp
 * Author: annas
 *
 * Created on 7. November 2016, 23:23
 */

#ifndef STD_FIXED_VECTOR_H
#define STD_FIXED_VECTOR_H

#include "alignment.hpp"
#include "vector.hpp"
#include <assert.h>

namespace std
{
	template<typename T, class TAllocator, int TCapacity, bool TGrowOnOverflow>
        struct fixed_vector_storage 
	{
        explicit fixed_vector_storage(const TAllocator& allocator)
        	: m_begin((T*)&m_data[0]),  m_end(m_begin), m_capacityEnd(m_begin + TCapacity), m_allocator(allocator) , m_max_size(0)
        {
        }       
        explicit fixed_vector_storage(e_noinitialize)
        {
        }
        void reallocate(base_vector::size_type newCapacity, base_vector::size_type oldSize)
        {
                if (!TGrowOnOverflow)
                {
                        assert(!"fixed_vector cannot grow");
                }
                T* newBegin = static_cast<T*>(m_allocator.allocate(newCapacity * sizeof(T)));
                const base_vector::size_type newSize = oldSize < newCapacity ? oldSize : newCapacity;

                if (m_begin)
                {
                        std::copy_construct_n(m_begin, newSize, newBegin);
                        destroy(m_begin, oldSize);
                }
                m_begin = newBegin;
                m_end = m_begin + newSize;
                m_capacityEnd = m_begin + newCapacity;
                record_high_watermark();
                assert(invariant());
        }
        void reallocate_discard_old(base_vector::size_type newCapacity)
        {
                if (newCapacity > base_vector::size_type(m_capacityEnd - m_begin))
                {
                        if (!TGrowOnOverflow)
                        {
                                assert(!"fixed_vector cannot grow");
                        }
                        T* newBegin = static_cast<T*>(m_allocator.allocate(newCapacity * sizeof(T)));
                        const base_vector::size_type currSize((size_t)(m_end - m_begin));
                        if (m_begin)
                                destroy(m_begin, currSize);
                        m_begin = newBegin;
                        m_end = m_begin + currSize;
                        record_high_watermark();
                        m_capacityEnd = m_begin + newCapacity;
                }
                assert(invariant());
        }
        inline void destroy(T* ptr, base_vector::size_type n)
        {
                std::destruct_n(ptr, n);
                if ((etype_t*)ptr != &m_data[0])
                        m_allocator.deallocate(ptr, n * sizeof(T));
        }
        bool invariant() const
        {
                return m_end >= m_begin;
        }
        inline void record_high_watermark()
        {
            const base_vector::size_type curr_size((size_t)(m_end - m_begin));
            if (curr_size > m_max_size)
                    m_max_size = curr_size;
        }
        base_vector::size_type get_high_watermark() const
        {
			return m_max_size;
        }

        typedef typename aligned_as<T>::res     		etype_t;        
        T*                                              m_begin;
        T*                                              m_end;
        etype_t                                 		m_data[(TCapacity * sizeof(T)) / sizeof(etype_t)];
        T*                                              m_capacityEnd;
        TAllocator                              		m_allocator;
        base_vector::size_type  						m_max_size;
	};


	template<typename T, int TCapacity, bool TGrowOnOverflow, class TAllocator = std::allocator> 
		class fixed_vector : public vector<T, TAllocator, fixed_vector_storage<T, TAllocator, TCapacity, TGrowOnOverflow> >
	{
        typedef vector<T, TAllocator, fixed_vector_storage<T, TAllocator, TCapacity, TGrowOnOverflow> > base_vector;
    	typedef TAllocator allocator_type;
    	typedef typename base_vector::size_type size_type;
    	typedef T value_type;
	public:
        explicit fixed_vector(const allocator_type& allocator = allocator_type())
        	: base_vector(allocator)
        {
        }
        explicit fixed_vector(size_type initialSize, const allocator_type& allocator = allocator_type())
        	: base_vector(initialSize, allocator)
        {
        }
        fixed_vector(const T* first, const T* last, const allocator_type& allocator = allocator_type())
        	: base_vector(first, last, allocator)
        {
        }
        fixed_vector(const fixed_vector& rhs, const allocator_type& allocator = allocator_type())
        	: base_vector(rhs, allocator)
        {
        }
        explicit fixed_vector(e_noinitialize n)
        	: base_vector(n)
        {
        }

        fixed_vector& operator=(const fixed_vector& rhs)
        {
	        if (&rhs != this)
	        {
	    		base_vector::copy(rhs);
	        }
	        return *this;
        }
	};
} 

#endif 


