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
#include "include/exception.hpp"
#include "include/common.hpp"

namespace std {
    _exception::_exception() {
        
    }
    _exception::_exception(std::string msg,
                         std::string source,
                         std::string helplink)
            : m_strMessage(msg),
              m_strHelpLink(helplink), m_strSource(source)
    {
        
    }
    std::string _exception::getStackTrace() {
        Sys::stacktrace_t* trace = Sys::getStackTrace();
        std::string str = std::frmstring("StackTrace (%s %d)",
                trace->system, trace->version); 
        for(int i=0; i < trace->size; i++) {
            str += std::string(trace->trace[i]);
        }
        return str;
    }
    const char* _exception::what(bool stacktrace) {
        std::string s = m_strMessage ;
        s += std::string("\n");
        if(stacktrace) s += getStackTrace();
        return s.c_str();
    }
    const char* exception::what(bool stacktrace) {
        std::string s = getMessage();
        
        if(m_innerException.format() != xmf_t::NoException) {
            s += std::frmstring(" Inner exception: %s", 
                 std::string(m_innerException.what(false)) );
        }
        
        if(stacktrace) s += getStackTrace();
        return s.c_str();
    }
}


