//
// Created by Moish on 06/09/2017.
//

#ifndef BOOKMEDIGITALANDROID_COMMONUTIL_H
#define BOOKMEDIGITALANDROID_COMMONUTIL_H


#include <openssl/evp.h>
#include <jni.h>


void LogInt(const char *, int);

void LogString(const char * , const char *);

int Base64Decode(char* , unsigned char** , size_t* );

int Base64Encode(const unsigned char* , size_t , char** );

char * intToString(int);

int StringToInt(const char * );

int * get_bits(char , int );

int is_start_of_valid_utf_8_byte(char *, int);

int is_end_of_valid_utf_8_byte(char *, int );

char * get_path_base(JNIEnv *env, jclass obj);

#endif //BOOKMEDIGITALANDROID_COMMONUTIL_H