//
// Created by Moish on 06/09/2017.
//

#include <android/log.h>
#include "const.h"
#include "commonUtil.h"


#include <openssl-1.1.0f/include/openssl/rsa.h>
#include <openssl-1.1.0f/include/openssl/evp.h>
#include <assert.h>
#include <openssl/buffer.h>
#include <jni.h>

void LogInt(const char * key, int value)
{
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "%s: %d", key, value);
}

void LogString(const char * key, const char * value)
{
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "%s: %s", key, value);
}


size_t calcDecodeLength(const char* b64input) { //Calculates the length of a decoded string
    size_t len = strlen(b64input),
            padding = 0;

    if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
        padding = 2;
    else if (b64input[len-1] == '=') //last char is =
        padding = 1;

    return (len*3)/4 - padding;
}

int Base64Decode(char* b64message, unsigned char** buffer, size_t* length) { //Decodes a base64 encoded string
    BIO *bio, *b64;

    int decodeLen = calcDecodeLength(b64message);
    *buffer = (unsigned char*)malloc(decodeLen + 1);
    (*buffer)[decodeLen] = '\0';

    bio = BIO_new_mem_buf(b64message, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
    *length = BIO_read(bio, *buffer, strlen(b64message));
    assert(*length == decodeLen); //length should equal decodeLen, else something went horribly wrong
    BIO_free_all(bio);

    return (0); //success
}

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text) { //Encodes a binary safe base 64 string
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    *b64text=(*bufferPtr).data;

    return (0); //success
}

int StringToInt(const char * str_number)
{
    int number = 0;
    int str_len = strlen(str_number);
    LogString("string2int str_number",str_number);
    LogInt("string2int str_len",str_len);
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
        LogInt("string2int digit ",digit);
        number = number + (digit * unit);
        LogInt("string2int number ",number);
        unit = unit * 10;
    }
    return number;
}

char * intToString(int number)
{
    char digits[101]; //until the Googol number
    int i=0;
    while (number > 0)
    {
        int dig = number % 10;
        digits[i] = dig;
        i = i + 1;
        number = (int)(number / 10);
    }

    char * str_number = malloc(i); //i-1, but 0 at first char
    strcpy(str_number, "0");
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

int * get_bits(char n, int bitswanted){
    int *bits = malloc(sizeof(int) * bitswanted);

    int k;
    for(k=0; k<bitswanted; k++){
        int mask =  1 << k;
        int masked_n = n & mask;
        int thebit = masked_n >> k;
        bits[k] = thebit;
    }

    return bits;
}

int is_start_of_valid_utf_8_byte(char * bytes, int index)
{
    int * bits1 = get_bits(bytes[index], 8);
    if (is_ascii_byte(bits1) == 1) {
        return 1;
    }
    else {
        // check if start of 2 or 3 or 4 bytes
        int * bits2 = get_bits(bytes[index+1],8);
        int * bits3 = get_bits(bytes[index+2],8);
        int * bits4 = get_bits(bytes[index+3],8);
        int * bits5 = get_bits(bytes[index+4],8);

        int is_bits2_middle = is_middle_byte_of_bytes_utf8(bits2);
        int is_bits3_middle = is_middle_byte_of_bytes_utf8(bits3);
        int is_bits4_middle = is_middle_byte_of_bytes_utf8(bits4);
        int is_bits5_middle = is_middle_byte_of_bytes_utf8(bits5);

        if (is_first_byte_of_4_bytes_utf8(bits1) == 1
            && is_bits2_middle == 1
            && is_bits3_middle == 1
            && is_bits4_middle == 1
            && is_bits5_middle == 0) {
            return 1;
        }
        else if (is_first_byte_of_3_bytes_utf8(bits1) == 1
                && is_bits2_middle == 1
                && is_bits3_middle == 1
                && is_bits4_middle == 0) {
            return 1;
        }
        else if (is_first_byte_of_2_bytes_utf8(bits1) == 1
                && is_bits2_middle == 1
                && is_bits3_middle == 0){
            return 1;
        }
        return 0;
    }
}

int is_ascii_byte(int * firstBits) {
    if (firstBits[7] == 0)
        return 1;
    return 0;
}

int is_first_byte_of_2_bytes_utf8(int * firstBits) {
    if (firstBits[7] == 1 && firstBits[6] == 1 && firstBits[5] == 0)
        return 1;
    return 0;
}

int is_first_byte_of_3_bytes_utf8(int * firstBits) {
    if (firstBits[7] == 1 && firstBits[6] == 1 && firstBits[5] == 1 && firstBits[4] == 0)
        return 1;
    return 0;
}

int is_first_byte_of_4_bytes_utf8(int * firstBits) {
    if (firstBits[7] == 1 && firstBits[6] == 1 && firstBits[5] == 1 && firstBits[4] == 1)
        return 1;
    return 0;
}

int is_middle_byte_of_bytes_utf8(int * bits) {
    if (bits[7] == 1 && bits[6] == 0)
        return  1;
    return 0;
}

int is_end_of_valid_utf_8_byte(char * bytes, int index)
{
    int * bits1 = get_bits(bytes[index], 8);
    if (is_ascii_byte(bits1) == 1) {
        return 1;
    }
    else {
        int * bits2 = get_bits(bytes[index-1],8);
        int * bits3 = get_bits(bytes[index-2],8);
        int * bits4 = get_bits(bytes[index-3],8);
        int * bits5 = get_bits(bytes[index-4],8);

        if (is_middle_byte_of_bytes_utf8(bits1)
            && is_first_byte_of_2_bytes_utf8(bits2)
            && (is_middle_byte_of_bytes_utf8(bits3) || is_ascii_byte(bits3))) {
            return 1;
        }
        else if (is_middle_byte_of_bytes_utf8(bits1)
                && is_middle_byte_of_bytes_utf8(bits2)
                && is_first_byte_of_3_bytes_utf8(bits3)
                && (is_middle_byte_of_bytes_utf8(bits4) || is_ascii_byte(bits4))) {
            return 1;
        }
        else if (is_middle_byte_of_bytes_utf8(bits1)
                && is_middle_byte_of_bytes_utf8(bits2)
                && is_middle_byte_of_bytes_utf8(bits3)
                && is_first_byte_of_4_bytes_utf8(bits4)
                && (is_middle_byte_of_bytes_utf8(bits5) || is_ascii_byte(bits5))) {
            return 1;
        }
        return 0;
    }
}

char * get_path_base(JNIEnv *env, jclass obj)
{
    jstring jstr = (*env)->NewStringUTF(env, "This comes from jni.");

    //jclass clazz = (*env)->GetObjectClass(env, "il/co/bookme/bookmedigital/NativeBridge");
    jclass clazz = (*env)->FindClass(env, "il/co/bookme/bookmedigital/NativeBridge");
    jmethodID messageMe = (*env)->GetStaticMethodID(env, clazz, "GetPathBase", "(Ljava/lang/String;)Ljava/lang/String;");
    jobject result = (*env)->CallStaticObjectMethod(env, obj, messageMe, jstr);

    const char* str = (*env)->GetStringUTFChars(env,(jstring) result, NULL);
    return str;
}