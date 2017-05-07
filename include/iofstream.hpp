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
 * File:   iofstream.hpp
 * Author: annas
 *
 * Created on 24. November 2016, 23:41
 */

#ifndef IOFSTREAM_HPP
#define IOFSTREAM_HPP

#include "filestream.hpp"
#include <stdarg.h>


namespace std {
     class ifstream : public filestream
    {
    public:
        ifstream() {}
        ifstream(string file, bool binary)
                : filestream(file, filemode::read, binary) { }
        ifstream(FILE* file, bool binary)
                : filestream(file, filemode::read, binary) { }
                
        virtual  size_t readline(void *data, size_t offset, size_t size) { 
            size_t r = 0, tobuf = 0; 
            char *buf = data, ch;
            
            for(;;) {
                r = read(&ch, offset, 1);
                if (r == -1) return -1;
                else if(r == 0) if (tobuf == 0) return 0; else break;
                else {
                    if (tobuf < size - 1) {
                        tobuf++;
                        *buf++ = ch;
                    }
                    if (ch == '\n')
                        break;
                }
            }
            *buf = '\0';
            return tobuf;
        } 
    };
    class ofstream : public filestream
    {
    public:
        ofstream() {}
        ofstream(string file, bool binary)
                : filestream(file, filemode::write, binary) { }
        ofstream(FILE* file, bool binary)
                : filestream(file, filemode::write, binary) { }
           
        virtual ofstream& write (const char* str) { 
            if(m_fFile.get() !=0 ) 
                Sys::fPrintf(m_fFile.get(), str); 
        } 
        virtual ofstream& write (string str) { 
            if(m_fFile.get() !=0 ) 
                Sys::fPrintf(m_fFile.get(), str.c_str()); 
        } 
        virtual ofstream& writeline(const char* str) {
            write(string(str) << "\n"); 
        }
        virtual ofstream& writeline(const string str) {
            string d = str;
            write(d << ("\n")); 
        }
    };
    class iofstream : public ofstream, public ifstream
    {
    public:
        iofstream(string file, bool binary)
                : ofstream(file, binary),
                  ifstream(file, binary) { }
    };
    
    
    
}

#endif /* IOFSTREAM_HPP */

