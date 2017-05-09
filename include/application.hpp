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
 * File:   application.hpp
 * Author: annas
 *
 * Created on 5. Dezember 2016, 04:34
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "list.hpp"
#include "string.hpp"
#include "singleton.hpp"
#include "unknown.hpp"
#include "event.hpp"
#include "applications_events.hpp"


namespace std {
    class Program : public object {
    public:
        Program();
        
        virtual int Main() {
            return 0;
        }
    protected:
        virtual void OnAppExit(const std::object* sender, 
                               const std::exitEventArgs p);
        virtual void OnAppStart(const std::object* sender, 
                                const std::startEventArgs p);
        virtual void OnAppException(const std::object* sender, 
                                const std::exceptionEventArgs p);
        virtual void OnNewHandler(const std::object* sender, 
                                  const std::handlerEventsArgs p);
    };
    
    
    
    class application : public singleton<application>, 
        public object 
    {
        friend class singleton<application>;
    public:
        using ExitApp = event<exitEventArgs>;
        using StartApp = event<startEventArgs>;
        using Exception = event<exceptionEventArgs>;
        using NewHandler = event<handlerEventsArgs>;
        
        ExitApp                ExitAppEvent;
        StartApp               StartAppEvent;
        Exception              ExceptionEvent;
        NewHandler             NewHandlerEvent;
        
        void setup(int argc, char** argv);
        
        list<string> getArgumente() {
            return m_args;
        }
        string       getAppName() {
            return m_strName;
        }
        int          getExitCode() {
            return m_iExitCode;
        }
        auto_ptr<Program>   getProgram() {
            return m_iMainPrg;
        }
        int run(auto_ptr<Program> prg);
        void newHandler();
        
        
    protected:
        application() { }
        
        void onExit();
        void onStart();
        void onException();
        
    private:
        list<string>           m_args;
        string                 m_strName;
        auto_ptr<Program>     m_iMainPrg;
        int                    m_iExitCode;
        
        
    };
}

#ifndef SET_PROGRAM
#define SET_PROGRAM(P) \
std::auto_ptr<std::Program> __astl_startabi() { return std::auto_ptr<std::Program>(new (P)); }
//std::auto_ptr<std::Program> mainPrg = std::auto_ptr<std::Program>(new (P)());

#endif



#endif /* APPLICATION_HPP */

