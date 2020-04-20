//
// Created by Moish on 06/09/2017.
//

#include "const.h"
#include "commonUtil.h"
#include <assert.h>
#include "openssl/buffer.h"
#include <string.h>

void LogInt(const char * key, int value)
{
    printf("%s: %d", key, value);
}

void LogString(const char * key, const char * value)
{
    printf("%s: %s", key, value);
}


size_t calcDecodeLength(const char* b64input) {
    size_t len = strlen(b64input),
            padding = 0;

    if (b64input[len-1] == '=' && b64input[len-2] == '=')
        padding = 2;
    else if (b64input[len-1] == '=')
        padding = 1;

    return (len*3)/4 - padding;
}

//need2free: buffer
int Base64Decode(char* b64message, unsigned char** buffer, size_t* length) {
    BIO *bio, *b64;

    int decodeLen = calcDecodeLength(b64message);
    *buffer = (unsigned char*)malloc(decodeLen + 1);
    (*buffer)[decodeLen] = '\0';

    bio = BIO_new_mem_buf(b64message, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    *length = BIO_read(bio, *buffer, strlen(b64message));
    assert(*length == decodeLen); //length should equal decodeLen, else something went horribly wrong
    BIO_free_all(bio);

    return (0);
}

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    *b64text=(*bufferPtr).data;

    return (0);
}

int StringToInt(const char * str_number)
{
    int number = 0;
    int str_len = strlen(str_number);
    int unit = 1;
    for (int i=str_len-1; i>=0; i--)
    {
        int digit;
        if (str_number[i] == '1')
            digit = 1;
        else if (str_number[i] == '2')
            digit = 2;
        else if (str_number[i] == '3')
            digit = 3;
        else if (str_number[i] == '4')
            digit = 4;
        else if (str_number[i] == '5')
            digit = 5;
        else if (str_number[i] == '6')
            digit = 6;
        else if (str_number[i] == '7')
            digit = 7;
        else if (str_number[i] == '8')
            digit = 8;
        else if (str_number[i] == '9')
            digit = 9;
        else
            digit = 0;
        number = number + (digit * unit);
        unit = unit * 10;
    }
    return number;
}

//need2free: str_number (return_value)
char * intToString(int number)
{
    char digits[101]; //until Googol
    int i=0;
    while (number > 0)
    {
        int dig = number % 10;
        digits[i] = dig;
        i = i + 1;
        number = (int)(number / 10);
    }

    char * str_number = (char*)malloc(i + 2); //0 at the first, \0 at the end
    strcpy(str_number, "0");
    str_number[i+1] = '\0';
    for (int j=0; j <= i-1; j++)
    {
        int cd = digits[i-1-j];
        if (cd == 1)
            strcat(str_number, "1");
        else if (cd == 2)
            strcat(str_number, "2");
        else if (cd == 3)
            strcat(str_number, "3");
        else if (cd == 4)
            strcat(str_number, "4");
        else if (cd == 5)
            strcat(str_number, "5");
        else if (cd == 6)
            strcat(str_number, "6");
        else if (cd == 7)
            strcat(str_number, "7");
        else if (cd == 8)
            strcat(str_number, "8");
        else if (cd == 9)
            strcat(str_number, "9");
        else
            strcat(str_number, "0");
    }
    return str_number;
}


//need2free: path (return value)
char * get_path_base(/*JNIEnv *env, jclass obj*/)
{
//    jstring jstr = (*env)->NewStringUTF(env, "");
//    jclass clazz = (*env)->FindClass(env, NATIVE_BRIDGE_JAVA_PATH);
//    jmethodID messageMe = (*env)->GetStaticMethodID(env, clazz, "GetPathBase", "(Ljava/lang/String;)Ljava/lang/String;");
//    jobject result = (*env)->CallStaticObjectMethod(env, obj, messageMe, jstr);
//
//    char* str = (*env)->GetStringUTFChars(env,(jstring) result, NULL);
//    int str_len = strlen(str);
//    char * path = (char*)malloc(str_len + 1);
//    strcpy(path,str);
//    path[str_len] = '\0';
//
//    (*env)->ReleaseStringUTFChars(env, result, str);
    return "path";
}

void * lcSdY(size_t a)
{
    return malloc(a);
}
