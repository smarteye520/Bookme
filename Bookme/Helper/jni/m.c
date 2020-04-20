//
// Created by Moish on 06/10/2017.
//

#include <stdlib.h>
#include <memory.h>
#include "f.h"
#include "m.h"
#include "const.h"
#include "bm013.h"
#include "cJSON.h"
#include "request.h"

void DILHi(void * a)
{
    free(a);
}

void * bsLCB(size_t a)
{
    return malloc(a);
}

size_t F1Re8(const char *a)
{
    return strlen(a);
}



struct sOHBI * new_sOHBI(int a, int b, int c, int d)
{
    
    //mmn: UUW03 is %s (string format)
    char UUW04[5] = {37,108,108,120,0};
    //mmn: create RSA struct
    struct sOHBI * const s = bsLCB(sizeof(struct sOHBI));
    //mmn: get the functino by the id: 1861321056 (2^5*3*7^3*56527)
    unsigned long long int h = XGf2G(2)*bVloC(3)*RzsTI(7);
    h*=(unsigned long long int)56527;
    //mmn: get the hex value; 6ef18160
    //mmn: zIXH1 = 20
    char x[zIXH1];
    sprintf(x, UUW04, h);
    //mmn: run over the function map, find the RSA_new() function
    struct qos9M ** uf7ue;
    for(uf7ue = &ff01; *uf7ue != NULL && strcmp((*uf7ue)->x,x) != 0; uf7ue = &(*uf7ue)->z);
    //mmn: call RSA_new() function
    s->x = ((*uf7ue)->y)();
    return s;
}

struct yju1J * new_yju1J()
{
    //mmn: UUW04 is %llx (long long hex format)
    char UUW04[5] = {37,108,108,120,0};
    //mmn: create BIGNUM struct
    struct yju1J * const s = bsLCB(sizeof(struct yju1J));
    //mmn: get the functino by the id: 2628313364 ( 2^2*41*16026301)
    unsigned long long int h =  rPPmT(2)*bVloC(41);
    h*=(unsigned long long int)16026301;
    //mmn: get the hex value; 9ca8e114
    //mmn: zIXH1 = 20
    char hex[zIXH1];
    sprintf(hex, UUW04, h);
    //mmn: run over the function map, find the BN_new() function
    struct qos9M ** ff00;
    for(ff00 = &ff01; *ff00 != NULL && strcmp((*ff00)->x,hex) != 0; ff00 = &(*ff00)->z);
    //mmn: call BN_new() function
    s->x = ((*ff00)->y)();
    return s;
}

struct yju1J * new_yju1J_HelXV()
{
    struct yju1J * const s = bsLCB(sizeof(struct yju1J));
    s->x = NULL;
    return s;
}

void aQ8Vd(struct yju1J * a)
{
    //mmn: UUW04 is %llx (long long hex format)
    char UUW04[5] = {37,108,108,120,0};
    //mmn: get the functino by the id: 1578082318
    unsigned long long int h =  bVloC(2)*bVloC(73)*bVloC(89);
    h*=(unsigned long long int)121447;
    //mmn: get the hex value; 5e0fa00e
    //mmn: zIXH1 = 20
    char hex[zIXH1];
    sprintf(hex, UUW04, h);
    //mmn: run over the function map, find the BN_set_word(a->x, RSA_F4) function
    struct qos9M ** ff00;
    for(ff00 = &ff01; *ff00 != NULL && strcmp((*ff00)->x,hex) != 0; ff00 = &(*ff00)->z);
    //mmn: call BN_set_word(a->x, RSA_F4) function (RSA_F4=65537)
    ((*ff00)->y)(a->x, 65537);
}

void LOseI(struct sOHBI * a, struct yju1J * b)
{
    //mmn: UUW04 is %llx (long long hex format)
    char UUW04[5] = {37,108,108,120,0};
    //mmn: get the functino by the id: 2854150710 ( 2*3*5*29*79*131*317)
    unsigned long long int h =  bVloC(2)*bVloC(3)*bVloC(5)*bVloC(29)*bVloC(79)*bVloC(131)*(unsigned long long int)bVloC(317);
    //mmn: get the hex value; aa1ee236
    //mmn: zIXH1 = 20
    char hex[zIXH1];
    sprintf(hex, UUW04, h);
    //mmn: run over the function map, find the RSA_generate_key_ex(a->x, zIyGB, b->x, NULL) function
    struct qos9M ** ff00;
    for(ff00 = &ff01; *ff00 != NULL && strcmp((*ff00)->x,hex) != 0; ff00 = &(*ff00)->z);
    //mmn: call RSA_generate_key_ex(a->x, zIyGB, b->x, NULL)
    ((*ff00)->y)(a->x, zIyGB, b->x, NULL);
}


int x21pDt(char * zj8sm, char * xpqXZ)
{
    //mmn: RSA *rsa = RSA_new();
    struct hDfOm *const h = new_hDfOm();
    //mmn: BIGNUM *bn = BN_new();
    struct m4XKt *const m = new_m4XKt();
    //mmn: BN_set_word(bn, RSA_F4);
    fdlwd(m);
    //mmn: RSA_generate_key_ex(h->x->x->x->x, RSA_BITS, bn, NULL);
    qtcBR(h,m);
    //mmn: const BIGNUM *n = NULL;
    const struct m4XKt *n = new_m4XKt_HelXV();
    //mmn: const BIGNUM *e = NULL;
    const struct m4XKt *e = new_m4XKt_HelXV();

    //mmn: UUW04 is %llx (long long hex format)
    char UUW04[5] = {37,108,108,120,0};
    const BIGNUM *b1 = NULL;
    const BIGNUM *b2 = NULL;
    //mmn: get the functino by the id: 1617740952 (2^3*3*31*2174383)
    unsigned long long int h2 =  RzsTI(2)*bVloC(3)*bVloC(31)*(unsigned long long int)bVloC(2174383);
    //mmn: get the hex value; 606cc498
    //mmn: zIXH1 = 20
    char h3[zIXH1];
    sprintf(h3, UUW04, h2);
    //mmn: run over the function map, find the RSA_get0_key(a->x, &n, &e, NULL) function
    struct qos9M ** ff00;
    for(ff00 = &ff01; *ff00 != NULL && strcmp((*ff00)->x,h3) != 0; ff00 = &(*ff00)->z);
    //mmn: call RSA_get0_key(a->x, &n, &e, NULL)
    ((*ff00)->y)(h->x->x->x->x, &b1, &b2, NULL);
    
    //mmn: get the functino by the id: 2923657734 (2*3*4177*116657)
    unsigned long long int h4 =  bVloC(2)*bVloC(3)*bVloC(4177)*(unsigned long long int)bVloC(116657);
    //mmn: get the hex value; ae437a06
    //mmn: zIXH1 = 20
    char h5[zIXH1];
    sprintf(h5, UUW04, h4);
    //mmn: run over the function map, find the BN_bn2hex(n)/BN_bn2hex(e) function
    struct qos9M ** ff002;
    for(ff002 = &ff01; *ff002 != NULL && strcmp((*ff002)->x,h5) != 0; ff002 = &(*ff002)->z);
    //mmn: char *rsa_n_hex = BN_bn2hex(n);
    char * YLd2f = ((*ff002)->y)(b1);
    //mmn: char *rsa_e_hex = BN_bn2hex(e);
    char * fmDOc = ((*ff002)->y)(b2);
    
    //mmn: int download_status;
    int OHNd9;
    //mmn: unsigned char * book_json = get_book_from_server(d, u, rsa_n_hex, rsa_e_hex, &download_status);
    //mmn: zj8sm=>d, xpqXZ=>u
    unsigned char * r4F1i = get_book_from_server(zj8sm, xpqXZ, YLd2f, fmDOc, &OHNd9);
    if (OHNd9 == WHnSO)
    {
        return -999;
    }
    else if (OHNd9 != umElA)
    {
        return 2;
    }
    //mmn: cJSON *json = cJSON_Parse(json);
    struct hMXAu * const wo8xp = bsLCB(sizeof(struct hMXAu));
    wo8xp->x = txVHV(r4F1i);
    //mmn: free(book_json);
    DILHi(r4F1i);
    //mmn: if (json == NULL) { return 1; }
    if (wo8xp == NULL) {
        return 1;
    }
    return 0;
}
