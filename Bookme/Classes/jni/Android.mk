LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libssl
LOCAL_SRC_FILES := $(LOCAL_PATH)/openssl-1.1.0f/lib/$(TARGET_ARCH_ABI)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libcrypto
LOCAL_SRC_FILES := $(LOCAL_PATH)/openssl-1.1.0f/lib/$(TARGET_ARCH_ABI)/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := rsa-jni
LOCAL_C_INCLUDES := $(LOCAL_PATH)/openssl-1.1.0f/include \
                libnhr.h \
                nhr/nhr_common.h \
                nhr/nhr_gz.h \
                nhr/nhr_map.h \
                nhr/nhr_memory.h \
                nhr/nhr_request.h \
                nhr/nhr_response.h \
                nhr/nhr_string.h \
                nhr/nhr_thread.h \
                nhr/cJSON/cJSON.h \
                dal.h \
                const.h \
                commonUtil.h \
                request.h \
                keysManagerCPP.h \
                sqlite3/sqlite3.h

LOCAL_SRC_FILES := rsa-jni.c \
                nhr/nhr_common.c \
                nhr/nhr_gz.c \
                nhr/nhr_map.c \
                nhr/nhr_memory.c \
                nhr/nhr_request_method_common.c \
                nhr/nhr_request_method_get.c \
                nhr/nhr_request_method_post.c \
                nhr/nhr_request_private.c \
                nhr/nhr_request_public.c \
                nhr/nhr_response.c \
                nhr/nhr_string.c \
                nhr/nhr_thread.c \
                nhr/cJSON/cJSON.c \
                dal.c \
                commonUtil.c \
                request.c \
                keysManagerCPP.cpp \
                sqlite3/sqlite3.c


LOCAL_LDLIBS    := -llog -lz
LOCAL_STATIC_LIBRARIES := libssl libcrypto

include $(BUILD_SHARED_LIBRARY)

#/$(TARGET_ARCH_ABI)