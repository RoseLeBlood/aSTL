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
#include "../include/iostream.hpp"

namespace std {
 
     class outstream : public ofstream
    {
    public:
        outstream() 
        : ofstream(stdout, false)
        {
             filestream::m_strFile = string("stdout");
        }
        
    };
    class instream : public ifstream
    {
    public:
        instream() 
         : ifstream(stdout, false)
        {
             filestream::m_strFile = string("stdin");
        }
    };
    
   
    outstream _stdout;
    instream _stdin;
    
    ofstream __cout(_stdout);
    ifstream __cin(_stdin); 
    
    void Console::reset()
    {
        __cout = (_stdout);
        __cin = (_stdin);       
    }
    void Console::write(const char* cstr) {
        __cout.write(cstr); 
    }
    void Console::writeline(const char* cstr) {
        __cout.writeline(cstr); 
    }
    void Console::write (string str) { 
        __cout.write(str);
    } 
    void Console::writeline(string str) { 
        __cout.writeline(str); 
    }
    
    char Console::read() { 
        return __cin.read(); 
    }
    string Console::readline() { 
       char buf[256];
       
       size_t len = __cin.readline(buf, 0, 256); 
       return string(buf, len);
    }
    void Console::setio(ofstream out, ifstream in) {
        __cout = (out);
        __cin = (in);   
    }
    auto_ptr<ofstream> Console::getout() {
        ofstream v = __cout;
        return auto_ptr<ofstream>(&v);
    }
    auto_ptr<ifstream> Console::getin() {
        ifstream v = __cin;
        return auto_ptr<ifstream>(&v);
    }
}
}