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
 * File:   exception.hpp
 * Author: annas
 *
 * Created on 25. April 2017, 22:03
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "string.hpp"

namespace std {
    typedef void (* terminate_handler)();
    typedef void (* unexpected_handler)();
    
    terminate_handler set_terminate(terminate_handler pHandler) noexcept;
    unexpected_handler set_unexpected(unexpected_handler pHandler) noexcept;
    
    void terminate(void) noexcept __attribute__((__noreturn__)); 
    void unexpected(void) noexcept __attribute__((__noreturn__)); 
    bool uncaught_exception() noexcept; 
    
    enum xmf_t {
        NoException,
        BadCastException,
        BadTypeID,
        BadAlloc, 
        
        User = 999
    };
    class _exception { 
    public: 
        _exception() ;
        _exception(std::string msg,
                  std::string source = std::string(""),
                  std::string helplink = std::string("https://github.io/")) ;
     
        std::string getMessage()  { return m_strMessage; }
        std::string getHelpLink() { return m_strHelpLink; }
        std::string getSource()   { return m_strSource; }
        std::string getStackTrace();
      
        xmf_t format() { return m_eFormat; }
        virtual const char* what(bool stacktrace = false);
    protected:
        virtual void set_format(xmf_t format) { m_eFormat = format; }
    
        std::string m_strMessage;
        std::string m_strHelpLink;
        std::string m_strSource;
        xmf_t m_eFormat;
    }; 
    class exception : public _exception {
    public:
        exception() : _exception() {}
        exception(std::string msg,
                  std::string source = std::string(""),
                  std::string helplink = std::string("https://github.io/"))
            : _exception(msg, source, helplink)  {}
        
        _exception getInnerException() { return m_innerException; } 
        void setInnerException(_exception ex) { m_innerException = ex; }
        
        virtual const char* what(bool stacktrace = false);
    private:
        _exception m_innerException;
    };
    class NoException : public exception {
    public:
        NoException() : exception(std::string("No Exception")) {
            set_format(xmf_t::NoException); 
        }
    };
    class BadCastException : public exception {
    public:
        BadCastException() : exception(std::string("Bad Cast"))  {
            set_format(xmf_t::BadCastException); 
        }
    };
    class BadTypeID : public exception {
    public:
        BadTypeID() : exception(std::string("Bad Type ID"))  {
            set_format(xmf_t::BadTypeID); 
        }
    };
    class BadAlloc : public exception {
    public:
        BadAlloc(int byteRequest) : exception(std::string("Bad Alloc")),
            m_byteRequest(byteRequest)  {
            set_format(xmf_t::BadAlloc); 
        }
        int getByteRequest() { return m_byteRequest; }
    private:
        int m_byteRequest;
    };
    

}

#endif /* EXCEPTION_HPP */

