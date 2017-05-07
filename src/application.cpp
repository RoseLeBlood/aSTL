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
 * File:   application.cpp
 * Author: annas
 * 
 * Created on 5. Dezember 2016, 04:34
 */

#include "../include/application.hpp"
#include "../include/iostream.hpp"


extern std::auto_ptr<std::Program> mainPrg;

void __new_handler()
{
    std::application::get().newHandler();
}
namespace std {
    void application::setup(int argc, char** argv) {
        std::set_new_handler(__new_handler);
        
        m_strName = std::string(argv[0]);
        for(int i = 1; i < argc; i++)
            m_args.push_back(std::string(argv[i]));
    }
    int application::run(auto_ptr<Program> prg) {
        try {
            onStart();
            m_iExitCode = prg->Main();
            onExit();
        } catch(...) {
            m_iExitCode = -1;
        }
               
        return m_iExitCode;
    }
}

int main( int argc, char **argv )
{
    std::application::get().setup(argc, argv);
    return std::application::get().run(mainPrg);
}

