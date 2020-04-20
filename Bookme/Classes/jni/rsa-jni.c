#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <stdlib.h>

#include <openssl/rsa.h>
#include <nhr/cJSON/cJSON.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

#include <const.h>
#include "dal.h"
#include "request.h"
#include "commonUtil.h"
#include "keysManagerCPP.h"

struct JniContext {
    RSA *rsa;
    BIGNUM *bn;
};

struct BookReader {
    char * position;
};


#define RSA_BITS 2048

JNIEXPORT jlong JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_Init(JNIEnv *env, jclass clazz) {
    struct JniContext *const context = malloc(sizeof(struct JniContext));
    context->rsa = RSA_new();
    context->bn = BN_new();
    BN_set_word(context->bn, RSA_F4);
    PATH_BASE = get_path_base(env, clazz);
    return (jlong) context;

}

JNIEXPORT int JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_DownloadBook(JNIEnv *env, jclass clazz,
                                                          jstring _bookID, jstring _user) {

    PATH_BASE = get_path_base(env, clazz);

    RSA *rsa = RSA_new();
    BIGNUM *bn = BN_new();
    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, RSA_BITS, bn, NULL);
    const BIGNUM *n = NULL;
    const BIGNUM *e = NULL;
    RSA_get0_key(rsa, &n, &e, NULL);
    char *rsa_n_hex = BN_bn2hex(n);
    char *rsa_e_hex = BN_bn2hex(e);

    char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
    char *u = (*env)->GetStringUTFChars(env, _user, 0);
    int download_status;
    unsigned char * book_json = get_book_from_server(d, u, rsa_n_hex, rsa_e_hex, &download_status);
    if (download_status == DOWNLOAD_BOOK_BUSY_TRY_LATER)
    {
        return -999;
    }
    else if (download_status != DOWNLOAD_BOOK_SUCCESS)
    {
        return 2;
    }
    cJSON *json = cJSON_Parse(book_json);
    free(book_json);
    if (json == NULL) {
        return 1;
    }

    cJSON *aesKeyJson = cJSON_GetObjectItem(json, "serverAuthNextVersion");
    unsigned char *aesKey = aesKeyJson->valuestring;

    unsigned char *aesKeybase64D;
    size_t aesKeybase64Dsize;
    Base64Decode(aesKey, &aesKeybase64D, &aesKeybase64Dsize);
    unsigned char aesKeyBuffer[RSA_BITS / 8 + 1];
    const int aesKeyBufferFilled = RSA_private_decrypt(aesKeybase64Dsize, aesKeybase64D,
                                                       aesKeyBuffer, rsa, RSA_NO_PADDING);
    const int aeskeyContentLength =
            (aesKeyBuffer[aesKeyBufferFilled - 2] << 8) + aesKeyBuffer[aesKeyBufferFilled - 1] + 1;
    jbyteArray aesKeyResult = (*env)->NewByteArray(env, aeskeyContentLength + 1);
    (*env)->SetByteArrayRegion(env, aesKeyResult, 0, aeskeyContentLength,
                               (jbyte *) ((sizeof(aesKeyBuffer) - aeskeyContentLength - 2) +
                                          aesKeyBuffer));
    jboolean isCopy;
    jbyte *ak = (*env)->GetByteArrayElements(env, aesKeyResult, &isCopy);

    cJSON *aesIvJson = cJSON_GetObjectItem(json, "appUserIdentity");
    unsigned char *aesIv = aesIvJson->valuestring;

    unsigned char *aesIvbase64D;
    size_t aesIvbase64Dsize;
    Base64Decode(aesIv, &aesIvbase64D, &aesIvbase64Dsize);
    unsigned char aesIvBuffer[RSA_BITS / 8 + 1];
    const int aesIvBufferFilled = RSA_private_decrypt(aesIvbase64Dsize, aesIvbase64D, aesIvBuffer,
                                                      rsa, RSA_NO_PADDING);
    const int aesIvContentLength =
            (aesIvBuffer[aesIvBufferFilled - 2] << 8) + aesIvBuffer[aesIvBufferFilled - 1] + 1;
    jbyteArray aesIvResult = (*env)->NewByteArray(env, aesIvContentLength + 1);
    (*env)->SetByteArrayRegion(env, aesIvResult, 0, aesIvContentLength,
                               (jbyte *) ((sizeof(aesIvBuffer) - aesIvContentLength - 2) +
                                          aesIvBuffer));
    jbyte *aiv = (*env)->GetByteArrayElements(env, aesIvResult, &isCopy);

    RSA_free(rsa);
    BN_free(bn);

    cJSON *bookName = cJSON_GetObjectItem(json, "bookName");
    cJSON *cover = cJSON_GetObjectItem(json, "cover");
    cJSON *author = cJSON_GetObjectItem(json, "authors");
    cJSON *manufacturer = cJSON_GetObjectItem(json, "manufacturer");
    cJSON *language = cJSON_GetObjectItem(json, "language");
    cJSON *description = cJSON_GetObjectItem(json, "description");
    cJSON *subject = cJSON_GetObjectItem(json, "subject");
    cJSON *contributor = cJSON_GetObjectItem(json, "contributor");
    cJSON *numOfCharacters = cJSON_GetObjectItem(json, "numOfCharacters");


    unsigned char * rbookName = "";
    unsigned char * rcover = "";
    unsigned char * rauthor = "";
    unsigned char * rmanufacturer = "";
    unsigned char * rlanguage = "";
    unsigned char * rdescription = "";
    unsigned char * rsubject = "";
    unsigned char * rcontributor = "";
    unsigned char * rnumOfCharacters = "";
    int bookNameAllocated = 0;
    int coverAllocated = 0;
    int authorAllocated = 0;
    int manufacturerAllocated = 0;
    int languageAllocated = 0;
    int descriptionAllocated = 0;
    int subjectAllocated = 0;
    int conrtibutorAllocated = 0;
    int numOfCharactersAllocated = 0;

    if (bookName != NULL && bookName->valuestring != NULL) {
        unsigned char * val = bookName->valuestring;
        int val_length = strlen(val);
        rbookName = malloc(val_length + 1);
        strcpy(rbookName, val);
        rbookName[val_length] = '\0';
        bookNameAllocated = 1;
    }
    if (cover != NULL && cover->valuestring != NULL) {
        unsigned char * val = cover->valuestring;
        int val_length = strlen(val);
        rcover = malloc(val_length + 1);
        strcpy(rcover, val);
        rcover[val_length] = '\0';
        coverAllocated = 1;
    }
    if (author != NULL && author->valuestring != NULL) {
        unsigned char * val = author->valuestring;
        int val_length = strlen(val);
        rauthor = malloc(val_length + 1);
        strcpy(rauthor, val);
        rauthor[val_length] = '\0';
        authorAllocated = 1;
    }
    if (manufacturer != NULL && manufacturer->valuestring != NULL) {
        unsigned char * val = manufacturer->valuestring;
        int val_length = strlen(val);
        rmanufacturer = malloc(val_length + 1);
        strcpy(rmanufacturer, val);
        rmanufacturer[val_length] = '\0';
        manufacturerAllocated = 1;
    }
    if (language != NULL && language->valuestring != NULL) {
        unsigned char * val = language->valuestring;
        int val_length = strlen(val);
        rlanguage = malloc(val_length + 1);
        strcpy(rlanguage, val);
        rlanguage[val_length] = '\0';
        languageAllocated = 1;
    }
    if (description != NULL && description->valuestring != NULL) {
        unsigned char * val = description->valuestring;
        int val_length = strlen(val);
        rdescription = malloc(val_length + 1);
        strcpy(rdescription, val);
        rdescription[val_length] = '\0';
        descriptionAllocated = 1;
    }
    if (subject != NULL && subject->valuestring != NULL) {
        unsigned char * val = subject->valuestring;
        int val_length = strlen(val);
        LogInt("val_length",val_length);
        rsubject = malloc(val_length + 1);
        strcpy(rsubject, val);
        rsubject[val_length] = '\0';
        subjectAllocated = 1;
    }
    if (contributor != NULL && contributor->valuestring != NULL) {
        unsigned char * val = contributor->valuestring;
        int val_length = strlen(val);
        rcontributor = malloc(val_length + 1);
        strcpy(rcontributor, val);
        rcontributor[val_length] = '\0';
        conrtibutorAllocated = 1;
    }
    if (numOfCharacters != NULL && numOfCharacters->valuestring != NULL) {
        unsigned char * val = numOfCharacters->valuestring;
        int val_length = strlen(val);
        rnumOfCharacters = malloc(val_length + 1);
        strcpy(rnumOfCharacters, val);
        rnumOfCharacters[val_length] = '\0';
        numOfCharactersAllocated = 1;
    }

    srand(time(NULL));
    int shift = rand() % 1000;
    int status =
            set_product(d, rbookName, rcover, aiv, shift,rauthor,
            rmanufacturer,rlanguage,rdescription,rsubject,rcontributor,rnumOfCharacters);

    if (bookNameAllocated==1)
        free(rbookName);
    if(coverAllocated == 1)
        free(rcover);
    if (authorAllocated == 1)
        free(rauthor);
    if (manufacturerAllocated == 1)
        free(rmanufacturer);
    if (languageAllocated == 1)
        free(rlanguage);
    if (descriptionAllocated == 1)
        free(rdescription);
    if (subjectAllocated == 1)
        free(rsubject);
    if (conrtibutorAllocated == 1)
        free(rcontributor);
    if (numOfCharactersAllocated == 1)
        free(rnumOfCharacters);

    if (status == 0) {
        setKey(d, ak, shift, aesKeybase64Dsize); //TODO: add to status
        status = set_sections(d, json);
    }

    cJSON_Delete(json);

    (*env)->ReleaseStringUTFChars(env, _bookID, d);
    (*env)->ReleaseStringUTFChars(env, _user, u);

    return (status);
}


JNIEXPORT void JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_setposition(JNIEnv *env, jclass clazz,jstring _bookID, int position)
{
    PATH_BASE = get_path_base(env, clazz);
    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
    update_chapter_position(d, position);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);
}

JNIEXPORT void JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_setchapter(JNIEnv *env, jclass clazz, jstring _bookID,
                                                        int chapter) {

    PATH_BASE = get_path_base(env, clazz);
    char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
    update_product_chapter(d, chapter);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);
}

JNIEXPORT void JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_setchapterbyshift(JNIEnv *env, jclass clazz,
                                                               jstring _bookID, int shift)
{
    PATH_BASE = get_path_base(env, clazz);

    char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
    update_product_chapter_by_shift(d, shift);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);
}

JNIEXPORT jlong  JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_OpenBookInit(JNIEnv *env, jclass clazz) {
    struct BookReader * const bookReader = malloc(sizeof(struct BookReader));
    bookReader->position=0;
    return (jlong)bookReader;
}

JNIEXPORT jbyteArray  JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_OpenBook(JNIEnv *env, jclass clazz, jlong nativePtr,
                                                      jstring _bookID, int block,
                                                      jlong jniReaderBook) {

    PATH_BASE = get_path_base(env, clazz);

    struct BookReader * const readBook = (struct BookReader*)jniReaderBook;

    int blockLength = 2048;
    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
    LogString("open book bookID",d);



    int *bookNum = 1;
    char *bookName = "1";
    char *bookCover = "0";
    char *bookKt = "1";
    char *bookSaveChapter = "1";
    char *bookSavaFontSize = "0";
    char *saveColumnPixel = "0";
    char *shift = "1";
    char *param2 = "0";
    char *param3 = "0";
    char *param4 = "0";
    char *param5 = "0";
    char *param6 = "0";
    char *param7 = "0";
    char *param8 = "0";
    char *param9 = "0";
    char *param10 = "0";

    get_product_details(d, &bookNum, &bookName, &bookCover,
                        &bookKt, &bookSaveChapter, &bookSavaFontSize, &saveColumnPixel,
                        &shift, &param2, &param3, &param4, &param5, &param6, &param7, &param8,
                        &param9, &param10);

    LogString("open book bookName ", bookName);
    LogString("open book bookKt ", bookKt);
    LogString("open book bookSaveChapter ", bookSaveChapter);

    int i_shift = StringToInt(shift);
    LogInt("i_shift", i_shift);

    char *ak = getKey(d, i_shift);

    int copyFrom = block * blockLength;
    int copyCount = blockLength;
    int contentCount = blockLength + 1;
    if (block > 0) {
        copyFrom = copyFrom - 128;
        copyCount = copyCount + 128;
    }

    LogInt("copyFrom", copyFrom);
    LogInt("copyCount", copyCount);
    int i_bookSaveChapter = StringToInt(bookSaveChapter);
    char * chapterTitle;
    unsigned char * chapterContentFull = get_product_content(d, i_bookSaveChapter, &chapterTitle);
    unsigned char *chapterContent = malloc(contentCount);
    int chapterContentFullCount = strlen(chapterContentFull);
    LogInt("block", block);
    LogInt("chapterContentFull", chapterContentFullCount);
    LogString("chapterContentFull", chapterContentFull);
    memcpy(chapterContent, &chapterContentFull[copyFrom], copyCount);
    chapterContent[contentCount] = '\0';
    LogString("chapterContent", chapterContent);

    LogInt("copyFrom", copyFrom);
    LogInt("chapterContentFullCount", chapterContentFullCount);
    if (copyFrom >= chapterContentFullCount) {
        LogString("eqq", "1");
        jbyteArray ret = (*env)->NewByteArray(env, strlen(END_OF_CHAPTER));
        (*env)->SetByteArrayRegion(env, ret, 0, strlen(END_OF_CHAPTER), END_OF_CHAPTER);
        return ret;
    }
    LogString("eqq", "0");

    unsigned char *key64d;
    unsigned char *iv64d;
    size_t key64dsize;
    size_t iv64dsize;
    Base64Decode(ak, &key64d, &key64dsize);
    Base64Decode(bookKt, &iv64d, &iv64dsize);
    free(ak);

    unsigned char *in64d;
    size_t in64dsize;
    Base64Decode(chapterContent, &in64d, &in64dsize);
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "in64d 401 ccc %s\n", in64d);
    //return (*env)->NewStringUTF(env, chapterContent);
    unsigned char dec_out[in64dsize + 1];
    AES_KEY dec_key;
    AES_set_decrypt_key(key64d, key64dsize * 8, &dec_key); // Size of key is in bits
    memset(dec_out, 0, sizeof(dec_out));
    AES_cbc_encrypt(in64d, dec_out, in64dsize, &dec_key, iv64d, AES_DECRYPT);
    dec_out[sizeof(dec_out) - 1] = '\0';
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "dec_out %s\n", dec_out);

    free(bookName);
    free(bookKt);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);

    /*LogString("dec_out bits:","");
    for(int i=0;i<in64dsize;i++) {
        int * bits = get_bits((char)dec_out[i], 8);
        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "%d: %d%d%d%d%d%d%d%d %c %d", i,
                            bits[7],
                            bits[6],bits[5],bits[4],bits[3],bits[2],bits[1],bits[0],
                            (char)dec_out[i], dec_out[i] );
    }*/

    //
    int outFrom = 0;
    if (block > 0) {
        outFrom = 128;
    }
    int is_start_of_valid_utf8 = is_start_of_valid_utf_8_byte(dec_out, outFrom);
    while (is_start_of_valid_utf8 == 0) {
        outFrom = outFrom + 1;
        is_start_of_valid_utf8 = is_start_of_valid_utf_8_byte(dec_out, outFrom);
    }
    /*int * bits = get_bits(dec_out[128], 8);
    if (bits[7] == 0) { //ascii

    }
    else if (bits[6] == 1) { //utf-8, first byte of 2 or 3 or 4 bytes

    }
    else //utf-8, 2th or 3th or 4th of collection of bytes
    {
        //need to move until the end of collection of bytes
        for (int i=1; i<=3; i++) { //this byte can maximum the 2th byte of 4 bytes, so max 3 bytes
            int * bits2 = get_bits(dec_out[128+i], 2);
            if (bits2[6] != 0) { //end of bytes
                outFrom += i;
                break;
            }
        }
    }*/
    LogInt("outFrom", outFrom);
    int outTo = in64dsize - 1;
    int is_end_of_valid_utf8 = is_end_of_valid_utf_8_byte(dec_out, outTo);
    while (is_end_of_valid_utf8 == 0) {
        outTo = outTo - 1;
        is_end_of_valid_utf8 = is_end_of_valid_utf_8_byte(dec_out, outTo);
    }
    /*int * bits3 = get_bits(dec_out[outTo], 8);
    LogInt("outToChar", dec_out[outTo]);
    if (bits3[7] == 0) { //ascii
        LogString("outTo","case1");
    }
    else if (bits3[6] == 1) { //first byte of 2/3/4 bytes, any way, can move 1 backwards to the last byte
        outTo = outTo -1;
        LogString("outTo","case2");
    }
    else { //2th or 3th or 4th from 2/3/4 bytes, go backwards
        LogString("outTo","case3");
        for (int i = 1; i<=3; i++) {
            int * bits4 = get_bits(dec_out[outTo - i], 2);
            if (bits4[6] != 0) {
                outTo = outTo - i;
                LogInt("outTo case3:",i);
                break;
            }
        }
    }*/
    LogInt("outTo", outTo);
    int finallContentCount = outTo - outFrom;
    if (finallContentCount <= 0) {
        jbyteArray ret = (*env)->NewByteArray(env, strlen(END_OF_CHAPTER));
        (*env)->SetByteArrayRegion(env, ret, 0, strlen(END_OF_CHAPTER), END_OF_CHAPTER);
        return ret;
    }
    LogInt("finallContentCount", finallContentCount);
    unsigned char *dec_out_2 = malloc(finallContentCount + 1);
    memcpy(dec_out_2, &dec_out[outFrom], finallContentCount);
    dec_out_2[finallContentCount - 1] = '\0';
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "dec_out_2 %s\n", dec_out_2);
    for (int i = 0; i < finallContentCount; i++) {
        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "%d : %c (%d)", i, (char) dec_out_2[i],
                            (int) dec_out_2[i]);
    }

    /*int residuesLen;
    unsigned char *dec_out_3;
    if (readBook->residues != NULL) {
        residuesLen = strlen(readBook->residues);
        dec_out_3 = malloc(contentCount + residuesLen + 1);
        strcpy(dec_out_3, readBook->residues);
        strcat(dec_out_3, dec_out_2);
        dec_out_3[contentCount + residuesLen] = '\0';
    }
    else {
        dec_out_3 = malloc(contentCount + 1);
        strcpy(dec_out_3, dec_out_2);
        dec_out_3[contentCount] = '\0';
    }

    residuesLen = in64dsize - outTo;
    LogInt("residuesLen",residuesLen);
    if (residuesLen == 0) {
        readBook->residues = NULL;
    }
    else {
        readBook->residues = malloc(residuesLen + 1);
        memcpy(readBook->residues, &dec_out[outTo], residuesLen);
    }
    LogString("residuesLen", readBook->residues);
    __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "dec_out_3 %s\n", dec_out_3);
*/

    int dec_out_2_len = strlen(dec_out_2);
    int numOfPackages = dec_out_2_len / 800;
    for (int i = 0; i < numOfPackages; i++) {
        unsigned char *x = malloc(800);
        memcpy(x, &dec_out_2[i * 800], 800);
        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "pck %d : %s\n", i, x);
    }

    jbyteArray ret = (*env)->NewByteArray(env, blockLength);
    (*env)->SetByteArrayRegion(env, ret, 0, blockLength, dec_out_2);
    return ret;

    //return (*env)->NewStringUTF(env, "asdf");


    jstring result = (*env)->NewStringUTF(env, dec_out_2);
    return result;
}


JNIEXPORT jbyteArray  JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_OpenBookFullChapter(JNIEnv *env, jclass clazz,jlong nativePtr,
                                                                 jstring _bookID, jlong jniReaderBook)
{

    PATH_BASE = get_path_base(env, clazz);

    char * d = (*env)->GetStringUTFChars(env,_bookID,0);

    int * bookNum = 1;
    char * bookName = "1";
    char * bookCover = "0";
    char * bookKt = "1";
    char * bookSaveChapter = "1";
    char * bookSavaFontSize = "0";
    char * saveColumnPixel = "0";
    char * shift = "1";
    char * param2 = "1";
    char * param3 = "0";
    char * param4 = "0";
    char * param5 = "0";
    char * param6 = "0";
    char * param7 = "0";
    char * param8 = "0";
    char * param9 = "0";
    char * param10 = "0";

    get_product_details(d, &bookNum, &bookName, &bookCover,
                        &bookKt, &bookSaveChapter, &bookSavaFontSize, &saveColumnPixel,
                        &shift, &param2, &param3, &param4, &param5, &param6, &param7, &param8, &param9, &param10);

    int i_shift = StringToInt(shift);

    char * ak = getKey(d, i_shift);
    int i_bookSaveChapter = StringToInt(bookSaveChapter);
    char * chapterTitle;
    unsigned char * chapterContentFull = get_product_content(d, i_bookSaveChapter, &chapterTitle);

    unsigned char * key64d;
    unsigned char * iv64d ;
    size_t key64dsize;
    size_t iv64dsize;
    Base64Decode(ak, &key64d, &key64dsize);
    Base64Decode(bookKt, &iv64d, &iv64dsize);
    free(ak);
    free(bookKt);

    unsigned char *in64d;
    size_t in64dsize;
    Base64Decode(chapterContentFull, &in64d, &in64dsize);
    unsigned char dec_out[in64dsize + 1];
    AES_KEY dec_key;
    AES_set_decrypt_key(key64d, key64dsize * 8, &dec_key);
    memset(dec_out, 0, sizeof(dec_out));
    AES_cbc_encrypt(in64d, dec_out, in64dsize, &dec_key, iv64d, AES_DECRYPT);
    dec_out[sizeof(dec_out) - 1] = '\0';

    int dec_out_2_len = in64dsize + strlen(HTML_TAG_SETTINGS_START)
                        + strlen(HTML_TAG_POSITION_START)
                        + strlen(param2)
                        + strlen(HTML_TAG_POSITION_END)
                        + strlen(HTML_TAG_TITLE_START)
                        + strlen(chapterTitle)
                        + strlen(HTML_TAG_TITLE_END)
                        + strlen(HTML_TAG_SETTINGS_END);

    unsigned char dec_out_2[dec_out_2_len + 1];
    strcpy(dec_out_2, dec_out);
    strcat(dec_out_2, HTML_TAG_SETTINGS_START);
    strcat(dec_out_2, HTML_TAG_POSITION_START);
    strcat(dec_out_2, param2);
    strcat(dec_out_2, HTML_TAG_POSITION_END);
    strcat(dec_out_2, HTML_TAG_TITLE_START);
    strcat(dec_out_2, chapterTitle);
    strcat(dec_out_2, HTML_TAG_TITLE_END);
    strcat(dec_out_2, HTML_TAG_SETTINGS_END);
    dec_out_2[dec_out_2_len] = '\0';

    if (bookSaveChapter != NULL)
        free(bookSaveChapter);
    if (shift != NULL)
        free(shift);
    if (param2 != "0")
        free(param2);
    if (chapterTitle != NULL)
        free(chapterTitle);
    if (chapterContentFull != NULL)
        free(chapterContentFull);
    if (bookName != NULL)
        free(bookName);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);

    jbyteArray ret = (*env)->NewByteArray(env, dec_out_2_len);
    (*env)->SetByteArrayRegion (env, ret, 0, dec_out_2_len, dec_out_2);
    return ret;

}

JNIEXPORT jbyteArray JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_getcurrentreaderposition(JNIEnv * env, jobject this, jlong jniReaderBook)
{

    PATH_BASE = get_path_base(env, this);

    struct BookReader * const readBook = (struct BookReader*)jniReaderBook;
    LogString("BookReader", readBook->position);

    char * position = "abc";
    int positionlen = strlen(position);
    jbyteArray ret = (*env)->NewByteArray(env, positionlen);
    (*env)->SetByteArrayRegion (env, ret, 0, positionlen, position);
    return ret;
}

JNIEXPORT jstring JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_GetLocalBook(JNIEnv *env, jobject this) {

    PATH_BASE = get_path_base(env, this);

    char *result = get_all_products();
    jstring jresult = (*env)->NewStringUTF(env, result);
    return jresult;
}


JNIEXPORT jstring JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_getbooktoc(JNIEnv *env, jclass clazz, jstring _bookID) {
    PATH_BASE = get_path_base(env, clazz);
    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
    char * chapters = get_product_toc(d);
    jstring jchapters = (*env)->NewStringUTF(env, chapters);
    return jchapters;
}


JNIEXPORT int JNICALL
Java_il_co_bookme_bookmedigital_NativeBridge_deleteproductfromproductstable(JNIEnv *env, jclass clazz,jstring _bookID)
{
    PATH_BASE = get_path_base(env, clazz);
    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
    int status = delete_product(d);
    (*env)->ReleaseStringUTFChars(env, _bookID, d);
    return status;
}