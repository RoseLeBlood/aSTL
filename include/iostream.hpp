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
 * File:   iostream.hpp
 * Author: annas
 *
 * Created on 24. November 2016, 21:53
 */

#ifndef IOSTREAM_HPP
#define IOSTREAM_HPP

#include "iofstream.hpp"
#include "property.hpp"
#include "singleton.hpp"
namespace std 
{
    class Console 
    {
    public: 
        static void write(const char* cstr);
        static void write (std::string str);
        static void writeline(const char* cstr);
        static void writeline(std::string str);
    
        static char read();
        static std::string readline();
        
        static void reset();
        
        static void setio(ofstream out, ifstream in);
        
        static auto_ptr<ofstream> getout();
        static auto_ptr<ifstream> getin();
    };
}


#endif /* IOSTREAM_HPP */

