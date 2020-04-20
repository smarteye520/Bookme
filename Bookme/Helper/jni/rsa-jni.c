
#include "rsa-jni.h"
#include "f.h"
//#include <jni.h>
#include <string.h>
#include <stdlib.h>

#include "openssl/rsa.h"
#include "nhr/cJSON/cJSON.h"
#include "openssl/evp.h"
#include "openssl/aes.h"

#include "const.h"
#include "dal.h"
#include "request.h"
#include "commonUtil.h"
#include "keysManagerCPP.h"
#include "bm013.h"


struct NativeSession {
    char * dataPath;
};

//void il_co_bookme_bookmedigital_NativeBridge_StaticInit(/*JNIEnv *env, jclass clazz*/) {
//    LogString("static","init");
//    K01RO();
//}

//JNIEXPORT jlong JNICALL
long il_co_bookme_bookmedigital_NativeBridge_Init(char *path) {
    //char* path = (*env)->GetStringUTFChars(env,(jstring) jpath, NULL);
//    int pathlen = (int)strlen(path);
//
//    char a[pathlen+1];
//
//    struct NativeSession * nativeSession;
//    nativeSession->dataPath = a;
//    strcpy(nativeSession->dataPath,path);
//    nativeSession->dataPath[pathlen] = '\0';

    //(*env)->ReleaseStringUTFChars(env, jpath, path);
    PATH_BASE = path;
    
    LogString("static","init");
    K01RO();

    return (long) 1;
}

//JNIEXPORT void JNICALL
//void il_co_bookme_bookmedigital_NativeBridge_Dispose(/*JNIEnv *env, jclass clazz,*/long ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    free(nativeSession);
//}

//JNIEXPORT int JNICALL
//jstring _bookID, jstring _user,jlong ns
int il_co_bookme_bookmedigital_NativeBridge_DownloadBook(/*JNIEnv *env, jclass clazz,*/
                                                          char *d, char *u, long ns, char *path) {

    //struct NativeSession *const nativeSession = (struct NativeSession *) ns;
    PATH_BASE = path;
//    char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
//    char *u = (*env)->GetStringUTFChars(env, _user, 0);
    int status =  KKkLM(d,u);
    LogInt("status",status);
    return status;
}


//JNIEXPORT void JNICALL
//jstring _bookID
//void il_co_bookme_bookmedigital_NativeBridge_setposition(/*JNIEnv *env, jclass clazz,*/char *d, int position,long ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//    //char * d = (*env)->GetStringUTFChars(env,_bookID,0);
//    update_chapter_position(d, position);
//    //(*env)->ReleaseStringUTFChars(env, _bookID, d);
//    free(PATH_BASE);
//}

//JNIEXPORT void JNICALL
//void il_co_bookme_bookmedigital_NativeBridge_setchapter(/*JNIEnv *env, jclass clazz, */char *d,
//                                                        int chapter,long ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//    //char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
//    update_product_chapter(d, chapter);
//    //(*env)->ReleaseStringUTFChars(env, _bookID, d);
//    free(PATH_BASE);
//}

//JNIEXPORT void JNICALL
//void il_co_bookme_bookmedigital_NativeBridge_setchapterbyshift(/*JNIEnv *env, jclass clazz,*/
//                                                               char *d, int shift,long ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//    //char *d = (*env)->GetStringUTFChars(env, _bookID, 0);
//    update_product_chapter_by_shift(d, shift);
//    //(*env)->ReleaseStringUTFChars(env, _bookID, d);
//    free(PATH_BASE);
//}

//JNIEXPORT jbyteArray  JNICALL
//void il_co_bookme_bookmedigital_NativeBridge_OpenBookFullChapter(/*JNIEnv *env, jclass clazz,*/
//                                                                 char *d,long ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//
//    //char * d = (*env)->GetStringUTFChars(env,_bookID,0);
//
//    int * bookNum = 1;
//    char * bookName = "1";
//    char * bookCover = "0";
//    char * bookKt = "1";
//    char * bookSaveChapter = "1";
//    char * bookSavaFontSize = "0";
//    char * saveColumnPixel = "0";
//    char * shift = "1";
//    char * param2 = "1";
//    char * param3 = "0";
//    char * param4 = "0";
//    char * param5 = "0";
//    char * param6 = "0";
//    char * param7 = "0";
//    char * param8 = "0";
//    char * param9 = "0";
//    char * param10 = "0";
//
//    get_product_details(d, &bookNum, &bookName, &bookCover,
//                        &bookKt, &bookSaveChapter, &bookSavaFontSize, &saveColumnPixel,
//                        &shift, &param2, &param3, &param4, &param5, &param6, &param7, &param8, &param9, &param10);
//
//    int i_shift = StringToInt(shift);
//
//    char * ak = getKey(d, i_shift);
//    int i_bookSaveChapter = StringToInt(bookSaveChapter);
//    char * chapterTitle = ""; //!!
//    unsigned char * chapterContentFull = get_product_content(d, i_bookSaveChapter, &chapterTitle);
//
//    unsigned char * key64d;
//    unsigned char * iv64d ;
//    size_t key64dsize;
//    size_t iv64dsize;
//    Base64Decode(ak, &key64d, &key64dsize);
//    Base64Decode(bookKt, &iv64d, &iv64dsize);
//    free(ak);
//    free(bookKt);
//
//    unsigned char *in64d;
//    size_t in64dsize;
//    Base64Decode(chapterContentFull, &in64d, &in64dsize);
//    unsigned char dec_out[in64dsize + 1];
//    AES_KEY dec_key;
//    AES_set_decrypt_key(key64d, key64dsize * 8, &dec_key);
//    memset(dec_out, 0, sizeof(dec_out));
//    AES_cbc_encrypt(in64d, dec_out, in64dsize, &dec_key, iv64d, AES_DECRYPT);
//    dec_out[sizeof(dec_out) - 1] = '\0';
//
//    int dec_out_2_len = in64dsize + strlen(HTML_TAG_SETTINGS_START) + strlen(HTML_TAG_POSITION_START);
//    if (param2 != NULL) {
//        dec_out_2_len = dec_out_2_len + strlen(param2);
//    }
//    dec_out_2_len = dec_out_2_len + strlen(HTML_TAG_POSITION_END) + strlen(HTML_TAG_TITLE_START);
//
//    if (chapterTitle != NULL) {
//        dec_out_2_len = dec_out_2_len + strlen(chapterTitle);
//    }
//    dec_out_2_len = dec_out_2_len + + strlen(HTML_TAG_TITLE_END) + strlen(HTML_TAG_SETTINGS_END);
//
//    unsigned char dec_out_2[dec_out_2_len + 1];
//    strcpy(dec_out_2, dec_out);
//    strcat(dec_out_2, HTML_TAG_SETTINGS_START);
//    strcat(dec_out_2, HTML_TAG_POSITION_START);
//    if (param2 != NULL) {
//        strcat(dec_out_2, param2);
//    }
//    strcat(dec_out_2, HTML_TAG_POSITION_END);
//    strcat(dec_out_2, HTML_TAG_TITLE_START);
//    if (chapterTitle != NULL) {
//        strcat(dec_out_2, chapterTitle);
//    }
//    strcat(dec_out_2, HTML_TAG_TITLE_END);
//    strcat(dec_out_2, HTML_TAG_SETTINGS_END);
//    dec_out_2[dec_out_2_len] = '\0';
//
//    if (bookSaveChapter != NULL)
//        free(bookSaveChapter);
//    if (shift != NULL)
//        free(shift);
//    if (param2 != "0")
//        free(param2);
//    if (chapterTitle != NULL)
//        free(chapterTitle);
//    if (chapterContentFull != NULL)
//        free(chapterContentFull);
//    if (bookName != NULL)
//        free(bookName);
//    //(*env)->ReleaseStringUTFChars(env, _bookID, d);
//    free(key64d);
//    free(iv64d);
//    free(in64d);
//    free(PATH_BASE);

//    jbyteArray ret = (*env)->NewByteArray(env, dec_out_2_len);
//    (*env)->SetByteArrayRegion (env, ret, 0, dec_out_2_len, dec_out_2);
//    return ret;

//}

//JNIEXPORT jstring JNICALL
//Java_il_co_bookme_bookmedigital_NativeBridge_GetLocalBook(JNIEnv *env, jobject this, jlong ns) {
//
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;// get_path_base(env, this);
//    char *result = get_all_products();
//    jstring jresult = (*env)->NewStringUTF(env, result);
//
//    if (result != NULL && result != "" && strlen(result) > 1) {
//        free(result);
//    }
//    free(PATH_BASE);
//
//    return jresult;
//}


//JNIEXPORT jstring JNICALL
//Java_il_co_bookme_bookmedigital_NativeBridge_getbooktoc(JNIEnv *env, jclass clazz, jstring _bookID,jlong ns) {
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
//    char * chapters = get_product_toc(d);
//    jstring jchapters = (*env)->NewStringUTF(env, chapters);
//
//    free(PATH_BASE);
//    free(chapters);
//    return jchapters;
//}
//
//
//JNIEXPORT int JNICALL
//Java_il_co_bookme_bookmedigital_NativeBridge_deleteproductfromproductstable(JNIEnv *env, jclass clazz,jstring _bookID,jlong ns)
//{
//    struct NativeSession *const nativeSession = (struct NativeSession *) ns;
//    PATH_BASE = nativeSession->dataPath;
//    char * d = (*env)->GetStringUTFChars(env,_bookID,0);
//    int status = delete_product(d);
//    (*env)->ReleaseStringUTFChars(env, _bookID, d);
//    free(PATH_BASE);
//    return status;
//}

