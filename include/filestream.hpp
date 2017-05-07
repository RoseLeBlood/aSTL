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
 * File:   filestream.hpp
 * Author: annas
 *
 * Created on 22. November 2016, 00:16
 */

#ifndef FILESTREAM_HPP
#define FILESTREAM_HPP

#include "stream.hpp"
#include "string.hpp"
#include "auto_ptr.hpp"

namespace std
{
       typedef enum class filemode
        {
            read,
            write,
            rw,
        } filemode_t;
   
    class filestream : public stream
    {
    public:
        filestream() {}
        filestream(string file, filemode_t mode, bool binary);
        filestream(const filestream& fs);
        
        virtual ~filestream();
        
        virtual bool close();
        virtual size_t seek(size_t off, seek_t org);
        virtual size_t read(void *data, size_t offset, size_t size);
	virtual size_t write(const void *data, size_t offset, size_t size);
        
        virtual filestream& reopen(filemode_t mode, bool binary);
	virtual void clear();
        
	virtual void write(char c);
	virtual char read();
        
        virtual long position();
        virtual long size();
        virtual bool iseof();
        virtual void flush();
        
        static bool isfile(string file);
        static bool canread(string file);
        static bool canwrite(string file);
        
        virtual string filename() { return m_strFile; }
        virtual bool isbinary() { return m_binary; }
        virtual filemode_t mode() { return m_mode;}
        
        operator bool() { return m_fFile.get() == 0; }
        filestream& operator = (const filestream& fs);
    protected:
        filestream(FILE* f, filemode_t mode,bool b);
    protected:
        filemode_t m_mode;
        auto_ptr<FILE> m_fFile;
        string m_strFile;
        bool m_binary;
    };
    
 

}


#endif /* FILESTREAM_HPP */

