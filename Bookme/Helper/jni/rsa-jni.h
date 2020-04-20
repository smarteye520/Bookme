//
//  rsa-jni.h
//  Bookme
//
//  Created by Nguyen Chi Dung on 10/21/17.
//  Copyright © 2017 Leopard. All rights reserved.
//



#ifdef __cplusplus
extern "C" {
#endif
    
    
    extern long il_co_bookme_bookmedigital_NativeBridge_Init(char *);
    
    int il_co_bookme_bookmedigital_NativeBridge_DownloadBook(char *, char *, long, char *);
    
#ifdef __cplusplus
}
#endif
