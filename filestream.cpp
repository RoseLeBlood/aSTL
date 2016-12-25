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
#include <stddef.h>
#include "include/filestream.hpp"
#include "include/sstream.hpp"



namespace std
{
    inline const char* filemodetostring(filemode_t m, bool a)
    {
        std::string s;
        if(m == filemode::rw) s << "rw";
        else if(m == filemode::read) s << "r";
        else if(m == filemode::write) s << "w";
        s <<( a ? "+b" : "+");
        
        return (s).c_str();
    }
    filestream::filestream(const filestream& fs)
        : stream(fs)
    {
        m_fFile.reset(fs.m_fFile.get());
        m_mode = fs.m_mode;
        m_strFile = fs.m_strFile;
        m_binary = fs.m_binary;
    }
    filestream& filestream::operator = (const filestream& fs)
    {
        m_fFile.reset(fs.m_fFile.get());
        m_mode = fs.m_mode;
        m_strFile = fs.m_strFile;
        m_binary = fs.m_binary;
    }
    filestream::filestream(FILE* f, filemode_t mode,bool b)
    {
        m_fFile.reset(f);
        m_mode = mode;
        m_strFile = "IoFile";
        m_binary = b;
    }
    filestream::filestream(std::string file, filemode_t mode,
            bool a)
            : stream()
        {
            m_mode = mode;
            m_strFile = file;
            m_binary = a;
            m_canSeek = true;
            m_canRead = (mode == filemode::read);
            m_canWrite = (mode == filemode::write);
            
            m_fFile = auto_ptr<FILE>( (FILE*)(Sys::fOpen ( file.c_str() ,
                    filemodetostring(mode, a))) );
 
        }
    filestream::~filestream()
    {
        close();
    }
    bool  filestream::close() {
        if(m_fFile.get() !=0) {
            Sys::fClose(m_fFile.get());
            return true;
        }
        return false;
    }
    size_t  filestream::seek(size_t off, seek_t org) {
        size_t s = EOF;
        if(m_fFile.get() != 0 && m_canSeek) {
            Sys::fSeek(m_fFile.get(), off, 
                    (int)org);
            s = Sys::fTell(m_fFile.get());
        }
        return s;
    }
    size_t  filestream::read(void *data, size_t offset, size_t size) {
        size_t s = EOF;
        if(m_fFile.get() != 0 ) {
            if(offset != 0) seek(offset, SeekOrigin::Current);
            s = Sys::fRead (data, 1, size, m_fFile.get());
        }
        return s;
    }
    size_t  filestream::write(const void *data, size_t offset, size_t size) {
        //fwrite (buffer , sizeof(char), sizeof(buffer), pFile);
        size_t s = EOF;
        if(m_fFile.get() != 0 && m_canWrite) {
             if(offset != 0) seek(offset, SeekOrigin::Current);
            s = Sys::fWrite (data, 1, size, m_fFile.get());
        }
        return s;
    }
        
    void  filestream::clear(){
        if(m_fFile.get() !=0) {
            Sys::fSeek(m_fFile.get(), 0, SEEK_END);
        }
    }
    void  filestream::write(char c) {
        if(m_fFile.get() !=0) {
            Sys::fPutc (c, m_fFile.get());
        }
    }
    char  filestream::read() {
        if(m_fFile.get() == 0)
            return EOF;
        return Sys::fGetc(m_fFile.get());
    }
        
    bool  filestream::isfile(std::string file) {
        return Sys::fIsFile(file.c_str());

    }
    bool  filestream::canread(std::string file) {
        void* f = Sys::fOpen(file.c_str(), "r");
        if(f != 0)
        {
            Sys::fClose(f);
            return true;
        }
        return false;
    }
    bool  filestream::canwrite(std::string file) {
        void* f = Sys::fOpen(file.c_str(), "w");
        if(f != 0)
        {
            Sys::fClose(f);
            return true;
        }
        return false;
    }
    long filestream::size()
    {
        long pos = position();
        long size = seek(0, SeekOrigin::End);
        seek(pos, SeekOrigin::Beginn);
        return size;    
    }
    void filestream::flush()
    {
        Sys::fFlush(m_fFile.get());
    }
    long filestream::position() 
    { 
        return Sys::fTell(m_fFile.get()); 
    } 
    bool filestream::iseof() 
    {
        return Sys::fEOF(m_fFile.get()); 
    }
    filestream& filestream::reopen(filemode_t mode, bool binary)
    {
        if(mode != m_mode || m_binary != binary)
        {
            m_mode = mode;
            m_binary = binary;
            //m_fFile.reset( freopen(m_strFile,filemodetostring(mode, binary), m_fFile.get()) );
        }
        return *this;
    }
   
   
}