//
// Created by Moish on 06/09/2017.
//

#ifndef BOOKMEDIGITALANDROID_COMMONUTIL_H
#define BOOKMEDIGITALANDROID_COMMONUTIL_H


#include "openssl/evp.h"
//#include <jni.h>
#include "openssl/ossl_typ.h"
#include "openssl/rsa.h"
#include "nhr/cJSON/cJSON.h"


void LogInt(const char *, int);

void LogString(const char * , const char *);

int Base64Decode(char* , unsigned char** , size_t* );

int Base64Encode(const unsigned char* , size_t , char** );

char * intToString(int);

int StringToInt(const char * );

char * get_path_base(/*JNIEnv *env, jclass obj*/);



struct hDfOm{struct HvSn8 * x;};
struct HvSn8{struct fnYDP * x;};
struct sOHBI {RSA * x;};
struct fnYDP {struct sOHBI * x;};


struct yju1J {BIGNUM * x;};
struct AVDvx {struct yju1J * x;};
struct pbMZZ{struct AVDvx * x;};
struct m4XKt{struct pbMZZ * x;};

struct hMXAu {cJSON * x;};

void * lcSdY(size_t);

#endif //BOOKMEDIGITALANDROID_COMMONUTIL_H
