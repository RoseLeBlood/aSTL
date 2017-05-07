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

#include "../include/common.hpp"

#ifndef USER_SYSTEM_IMP_
#include <sys/stat.h>
#include <pthread.h>
#include <malloc.h>
#include <ctype.h>
#include <cxxabi.h>

#else

#endif

#ifdef _WIN32 || _WIN64
inline int backtrace(void** p, int s) { return 0; }
inline char** backtrace_symbols(void* const p, int s) { return nullptr; }
#endif
namespace std {
      
#ifndef USER_SYSTEM_IMP_
                void Sys::MemCpy(void* to, const void* from, size_t bytes)
                {
                        memcpy(to, from, bytes);
                }
                void Sys::MemMove(void* to, const void* from, size_t bytes)
                {
                        memmove(to, from, bytes);
                }
                void Sys::MemSet(void* buf, unsigned char value, size_t bytes)
                {
                        memset(buf, value, bytes);
                }
                
                void Sys::wMemCpy(void* to, const void* from, size_t bytes)
                {
                        wmemcpy((wchar_t*)to, (wchar_t*)from, bytes);
                }
                void Sys::wMemMove(void* to, const void* from, size_t bytes)
                {
                        wmemmove((wchar_t*)to, (wchar_t*)from, bytes);
                }
                void Sys::wMemSet(void* buf, unsigned char value, size_t bytes)
                {
                        wmemset((wchar_t*)buf, value, bytes);
                }
                int Sys::vsnPrintf(char *buffer, size_t count, const char *format, va_list argptr) {
                    return _vsnprintf(buffer, count, format, argptr);
                }
          
                void* Sys::fOpen(const char* file, const char* fmt) {
                     return fopen(file, fmt);
                }
                void  Sys::fClose(void* file) {
                    fclose((FILE*)file);
                }
                int Sys::fTell(void* file) {
                    return ftell((FILE*)file);
                }
                int Sys::fPutc(int c, void* file) {
                    return fputc(c, (FILE*)file);
                }
                int Sys::fPuts(const char* str, void* file) {
                    return fputs(str, (FILE*)file);
                }
                int Sys::fGetc(void* file) {
                    return fgetc((FILE*)file);
                }
                int Sys::fPrintf(void* file, const char* str) {
                    return fprintf((FILE*)file, str);
                }
                int Sys::fSeek(void* file, int off, int org) {
                    return fseek((FILE*)file, off, org);
                }
                int Sys::fRead(void* data, const int count, const int size, void* file) {
                    return fread(data, count, size, (FILE*)file);
                }
                int Sys::fWrite(void* data, const int count, const int size, void* file) {
                    return fwrite(data, count, size, (FILE*)file);
                }
                int Sys::fFlush(void* file) {
                    return fflush((FILE*)file);
                }
                int Sys::fEOF(void* file) {
                    return feof((FILE*)file);
                }
                int Sys::fError(void* file) {
                    return ferror((FILE*)file);
                }
                bool Sys::fIsFile(const char* file) {
                    struct stat buffer;   
                    return (stat (file, &buffer) == 0);  
                }
                void* Sys::mAlloc(size_t size) {
                    return malloc(size);
                }
                void* Sys::mReAlloc(void* old, size_t newSize) {
                    return realloc(old, newSize);
                }
                void  Sys::mFree(void* mem) {
                    free(mem);
                }
                
                int Sys::mutexInit(mutex_type* mutex, mutex_init_t type,
                        bool shared, bool robust) {
                    pthread_mutexattr_t attr;
                    pthread_mutexattr_init(&attr);
                    pthread_mutexattr_setpshared(&attr, 
                            (shared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE) );
                    int t = PTHREAD_MUTEX_NORMAL;
                    if(type == mutex_init_t::Recursive)
                        t = PTHREAD_MUTEX_RECURSIVE;
                    else if(type == mutex_init_t::ErrorCheak) 
                        t = PTHREAD_MUTEX_ERRORCHECK;
                    
                    pthread_mutexattr_setrobust(&attr, (robust ? PTHREAD_MUTEX_ROBUST : PTHREAD_MUTEX_STALLED));
                    pthread_mutexattr_settype(&attr, t);
                    
                   int exit =  pthread_mutex_init( (pthread_mutex_t*)&mutex, &attr );
                   pthread_mutexattr_destroy(&attr);
                   return exit;
                }
                    
                int Sys::mutexDestroy(mutex_type* mutex) {
                    return pthread_mutex_destroy( (pthread_mutex_t*)&mutex );
                }
                int Sys::mutexLock(mutex_type* mutex) {
                    return pthread_mutex_lock( (pthread_mutex_t*)&mutex );
                }
                int Sys::mutexUnLock(mutex_type* mutex) {
                    return pthread_mutex_unlock( (pthread_mutex_t*)&mutex );
                }
                int Sys::mutexTryLock(mutex_type* mutex) {
                    return pthread_mutex_trylock( (pthread_mutex_t*)&mutex );
                }
                
                int Sys::spinlockInit(spinlk_type* spin, const void* attr) {
                   return pthread_spin_init( (pthread_spinlock_t*)&spin, 0);
                }
                int Sys::spinlockDestroy(spinlk_type* spin) {
                    return pthread_spin_destroy( (pthread_spinlock_t*)&spin );
                }
                int Sys::spinlockLock(spinlk_type* spin) {
                   return pthread_spin_lock( (pthread_spinlock_t*)&spin );
                }
                int Sys::spinlockUnLock(spinlk_type* spin) {
                    return pthread_spin_unlock( (pthread_spinlock_t*)&spin );
                }
                int Sys::spinlockTryLock(spinlk_type* spin) {
                    return  pthread_spin_trylock( (pthread_spinlock_t*)&spin );
                }
                
#else
                void Sys::MemCpy(void* to, const void* from, size_t bytes) {
                  
                }
                void Sys::MemMove(void* to, const void* from, size_t bytes) {
                      
                }
                void Sys::MemSet(void* buf, unsigned char value, size_t bytes) {
                        
                }
                
                void Sys::wMemCpy(void* to, const void* from, size_t bytes) {
                       
                }
                void Sys::wMemMove(void* to, const void* from, size_t bytes) {
                       
                }
                void Sys::wMemSet(void* buf, unsigned char value, size_t bytes) {
                        
                }
                int Sys::vsnPrintf(char *buffer, size_t count, const char *format, va_list argptr) {
                    
                }
                
                void* Sys::fOpen(const char* file, const char* fmt) {
                    
                }
                void  Sys::fClose(void* file) {
                    
                }
                int Sys::fTell(void* file) {
                    
                }
                int Sys::fPutc(int c, void* file) {
                    
                }
                int Sys::fPuts(const char* str, void* file) {
                    
                }
                int Sys::fGetc(void* file) {
                   
                }
                int Sys::fPrintf(void* file, const char* str) {
                }
                int Sys::fSeek(void* file, int off, int org) {
                    
                }
                int Sys::fRead(void* data, const int count, const int size, void* file) {
                    
                }
                int Sys::fWrite(void* data, const int count, const int size, void* file) {
                    
                }
                int Sys::fFlush(void* file) {
                    
                }
                int Sys::fEOF(void* file) {
                    
                }
                int Sys::fError(void* file) {
                    
                }
                bool Sys::fIsFile(const char* file) {
                    
                }  
                void* Sys::mAlloc(size_t size) {
                    
                }
                void* Sys::mReAlloc(void* old, size_t newSize) {
                    
                }
                void  Sys::mFree(void* mem) {
                    
                }
                int Sys::mutexInit(mutex_type* mutex, mutex_init_t type,
                        bool shared, bool robust) {
                    
                }
                    
                int Sys::mutexDestroy(mutex_type* mutex) {
                    
                }
                int Sys::mutexLock(mutex_type* mutex) {
                    
                }
                int Sys::mutexUnLock(mutex_type* mutex) {
                    
                }
                int Sys::mutexTryLock(mutex_type* mutex) {
                    
                }
                int Sys::spinlockInit(spinlk_type* spin, const void* attr) {
                   
                }
                int spinlockDestroy(spinlk_type* spin) {
                   
                }
                int spinlockLock(spinlk_type* spin) {
                   
                }
                int Sys::spinlockUnLock(spinlk_type* spin) {
                    
                }
                int Sys::spinlockTryLock(spinlk_type* spin) {
                   
                }
                const char* Sys::getStackTrace() {
                }
                int Sys::sPrintf(char* buffer, const char* format) {
                    
                }
            };
#endif
        } 

