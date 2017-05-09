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
 * File:   applications_events.hpp
 * Author: annas
 *
 * Created on 9. Mai 2017, 00:55
 */

#ifndef APPLICATIONS_EVENTS_HPP
#define APPLICATIONS_EVENTS_HPP

#include "eventargs.hpp"

namespace std {
    class exitEventArgs : public eventArgs {
    public:
        exitEventArgs(int exitcode) : eventArgs() {
            m_iExitCode = exitcode; 
        }
        exitEventArgs(const exitEventArgs& o) {
            m_iExitCode = o.m_iExitCode;
        }
        int getExitCode() {
            return m_iExitCode;
        }
    private:
        int m_iExitCode;
    };
    class startEventArgs : public eventArgs {
    public:
        startEventArgs( list<string> args, string name) {
            m_lstArgumente = args;
            m_prgName = name;
        }
        list<string> getArgs() {
            return m_lstArgumente;
        }
        string getName() {
            return m_prgName;
        }
    private:
        list<string> m_lstArgumente;
        string       m_prgName;
    };
    class exceptionEventArgs : public eventArgs {
        
    };
    class handlerEventsArgs : public eventArgs {
        
    };
}


#endif /* APPLICATIONS_EVENTS_HPP */

