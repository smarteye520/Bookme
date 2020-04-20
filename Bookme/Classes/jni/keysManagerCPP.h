//
// Created by Moshe on 02/10/2016.
//
#include <jni.h>


#ifndef ANDROID_BOOKME_SECURITY_NATIVE_H
#define ANDROID_BOOKME_SECURITY_NATIVE_H

#ifdef __cplusplus
extern "C" {
#endif


char * getKey(const char *, int);

char * setKey( const char *, char * ,int , int );


char * getE28(const char * , int );

#ifdef __cplusplus
}
#endif

#endif //ANDROID_BOOKME_SECURITY_NATIVE_H