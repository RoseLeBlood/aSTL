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
 * File:   event.hpp
 * Author: annas
 *
 * Created on 11. November 2016, 14:39
 */

#ifndef _STD_EVENT_HPP_
#define _STD_EVENT_HPP_

#include "common.hpp"
#include "auto_ptr.hpp"
#include "list.hpp"

namespace std 
{
    template<typename TYPE>
    class delegateparam 
    {
    public:
	delegateparam() {
	}
        void operator += (TYPE data) {
	   m_data.push_back(data);
	}
    
        std::list<TYPE> m_data;
    };

    template<class TSender, typename TYPE>
    class delegate_base
    {
    public:
	virtual bool equals( const delegate_base<TSender, TYPE>* pOther) = 0;
	virtual void operator()( const TSender* pSender, delegateparam<TYPE>* pParam) = 0;
	virtual void call( const TSender* pSender, delegateparam<TYPE>* pParam) = 0;
    };

    template<class TReciever, class TSender, typename TYPE>
    class delegate : public delegate_base<TSender, TYPE>
    {
    private:
	typedef void (TReciever::*callFunction)(const TSender*, delegateparam<TYPE>* pParam);
	callFunction         m_ptr2Func;
	TReciever*  m_ptr2Object;

    public:
	delegate(TReciever* p_ptr2Object, callFunction p_ptr2Func){
            m_ptr2Func      = p_ptr2Func;
            m_ptr2Object    = p_ptr2Object;
	}

	bool equals(const delegate_base<TSender, TYPE>* pOther){
            const delegate<TReciever, TSender, TYPE>* other;
            other = static_cast<const delegate<TReciever, TSender, TYPE>*>(pOther);
            assert(other != NULL);
            assert(m_ptr2Object != NULL);
            return other->m_ptr2Object == m_ptr2Object && other->m_ptr2Func == m_ptr2Func;
	}
        virtual void operator()(const TSender* pSender, delegateparam<TYPE>* pParam){
	    assert(pSender != NULL);
	    (m_ptr2Object->*m_ptr2Func)(pSender, pParam);
	}

	virtual void call(const TSender* pSender, delegateparam<TYPE>* pParam){
            assert(pSender != NULL);
            (m_ptr2Object->*m_ptr2Func)(pSender, pParam);
	}
    };
    template<class TSender, typename TYPE>
    class event
    {
    public:
	event() { }
	~event() { }

	void call( const TSender* pSender, delegateparam<TYPE>* pParameter) {
            for(auto itr = m_observers.begin();
			itr != m_observers.end();
			itr++)
            {
                (*itr)->call(pSender, pParameter);
            }
        }

	void operator += ( const delegate_base<TSender, TYPE>* pHandler) {
            add(pHandler);
        }
	void operator -= ( const delegate_base<TSender, TYPE>* pHandler) {
            rem(pHandler);
        }
	void operator () ( const TSender* pSender, delegateparam<TYPE>* pParameter) {
            call(pSender, pParameter);
        }
    private:
	void add( const delegate_base<TSender, TYPE>* pHandler) {
            assert(pHandler != NULL);
            m_observers.push_back(const_cast<delegate_base<TSender, TYPE>*>(pHandler));
        }
	void rem( const delegate_base<TSender, TYPE>* pHandler) {
            assert(pHandler != NULL);
            for(auto itr = m_observers.begin();
			itr != m_observers.end();
			itr++)
            //std::vector< delegate_base<TSender, TYPE>* >::iterator itr = m_observers.begin();
            {
                if(itr->equals(pHandler))
                {
                    m_observers.erase(itr);
                    break;
                }
            }
        }
    private:
	std::list< delegate_base<TSender, TYPE>* > m_observers;
    };

	
}

#endif /* EVENT_HPP */

