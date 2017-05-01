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
 * File:   bitset.hpp
 * Author: annas
 *
 * Created on 1. Mai 2017, 22:36
 */

#ifndef BITSET_HPP
#define BITSET_HPP

#include "string.hpp"
#include "fixed_vector.hpp"

namespace std {
    
    template<size_t N, class TAllocator = std::allocator> 
    class bitset  {
    public:
        using value_type = uint32_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using iterator =  fixed_vector<bool, N, false, TAllocator>::iterator;
        using const_iterator =  fixed_vector<bool, N, false, TAllocator>::const_iterator;
        using allocator_type = TAllocator;
        using self_type = bitset<N, TAllocator>;
    public:
        template<size_t N, class TAllocator>
        class reference {
            friend class bitset<N, TAllocator>;
        public:
            explicit reference(uint32_t pos) : m_pos(pos) {}
            
            operator bool () const noexcept {
                return bitset<N, TAllocator>.m_vecPointer[m_pos];
            }
            reference& operator = (bool b) noexcept {
                bitset<N,TAllocator>.m_vecPointer[m_pos] = b;
                return *this;
            }
            reference& operator = (const reference& x) noexcept {
                m_pos = x.m_pos; return *this;
            }
            reference& flip() noexcept {
                bitset<N, TAllocator>.flip(m_pos); return *this;
            }
            
            reference& operator ~() const noexcept {
                bitset<N,TAllocator>.m_vecPointer[m_pos] = ~bitset<N,TAllocator>.m_vecPointer[m_pos];
                return *this;
            }
        private:
            reference() noexcept {} 
            uint32_t m_pos;
        };
        bitset() {
            for(size_t i=0; i<N; i++)
                m_vecPointer.push_back(false);
        }
        
        inline void flip(value_type n) { 
            m_vecPointer[n] = !(m_vecPointer[n]);
        }
        inline void reset() {
            for(size_t i=0; i<N; i++)
                m_vecPointer[i] = false;
        }
        inline void clear() {
            reset();
        }
        inline size_t size() {
            return N;
        }
        inline bool test(size_t pos) {
            return m_vecPointer[pos];
        }
        inline bool none() {
            for(size_t i=0; i<N; i++)
                if(m_vecPointer[i]) return false;
            return true;
        }
        inline bool any() {
            for(size_t i=0; i<N; i++)
                if(!m_vecPointer[i]) return false;
            return true;
        }
        inline value_type count() {
            value_type c = 0;
            for(size_t i=0; i<N; i++)
                if(test(i)) c++;
            return c;
        }
        inline iterator begin() {
            return m_vecPointer.begin();
        }
        inline const_iterator begin() {
            return m_vecPointer.begin();
        }
        inline iterator end() {
            return m_vecPointer.end();
        }
        inline const_iterator end() {
            return m_vecPointer.end();
        }
        bool& operator [] (size_t pos) { return m_vecPointer[pos]; }
        reference& operator [] (size_t pos) { return reference(pos); } 
        
        bitset<N, TAllocator>& operator &= (bitset<N, TAllocator>& rhs) {
             for(size_t i=0; i<N; i++)
                m_vecPointer[i] = m_vecPointer[i] & rhs.m_vecPointer[i];
             return *this;
        }
        bitset<N, TAllocator>& operator ^= (bitset<N, TAllocator>& rhs) {
             for(size_t i=0; i<N; i++)
                m_vecPointer[i] = ~(m_vecPointer[i] & rhs.m_vecPointer[i]);
             return *this;
        }
        bitset<N, TAllocator>& operator |= (bitset<N, TAllocator>& rhs) {
             for(size_t i=0; i<N; i++)
                m_vecPointer[i] = m_vecPointer[i] | rhs.m_vecPointer[i];
             return *this;
        }
        bitset<N, TAllocator>& operator -= (bitset<N, TAllocator>& rhs) {
             for(size_t i=0; i<N; i++)
                m_vecPointer[i] = m_vecPointer[i] & ~(rhs.m_vecPointer[i]);
             return *this;
        }
        
        bool operator == (bitset<N, TAllocator> rhs, bitset<N, TAllocator> lhs) {
             for(size_t i=0; i<N; i++) {
                 if(rhs.m_vecPointer[i] != lhs.m_vecPointer[i]) return false;
             }
             return true;   
        }
        bool operator != (bitset<N, TAllocator> rhs, bitset<N, TAllocator> lhs) {
             for(size_t i=0; i<N; i++) {
                 if(rhs.m_vecPointer[i] == lhs.m_vecPointer[i]) return false;
             }
             return true;   
        }
        template<typename E, class TAllocator = std::allocator, typename TStorage = std::simple_string_storage<E, TAllocator> >
        inline basic_string<E, TAllocator, TStorage> to_string(E zero = E('0'), E one = E('1')) {
            basic_string<E, TAllocator, TStorage> ret;
            for(size_t i=0; i<N; i++) {
                ret << ((m_vecPointer[i]) ? one : zero);
            }
            return ret;
        }
    private:
        fixed_vector<bool, N, false, TAllocator> m_vecPointer;
    };
}

#endif /* BITSET_HPP */

