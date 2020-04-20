//
// Created by Moish on 06/10/2017.
//

#include <stdlib.h>
#include "memory.h"
#include "f.h"
#include "const.h"
#include "commonUtil.h"

struct qos9M * ff01;

void K01RO()
{
    ff01 = lcSdY(sizeof(struct qos9M));
    ff01->x = "6ef18160";
    ff01->y = &RSA_new;
    ff01->z = lcSdY(sizeof(struct qos9M));
    ff01->z->x = "9ca8e114";
    ff01->z->y = &BN_new;
    ff01->z->z = lcSdY(sizeof(struct qos9M));
    ff01->z->z->x = "5e0fa00e";
    ff01->z->z->y = &BN_set_word;
    ff01->z->z->z = lcSdY(sizeof(struct qos9M));
    ff01->z->z->z->x = "aa1ee236";
    ff01->z->z->z->y = &RSA_generate_key_ex;
    ff01->z->z->z->z = lcSdY(sizeof(struct qos9M));
    ff01->z->z->z->z->x = "606cc498";
    ff01->z->z->z->z->y = &RSA_get0_key;
    ff01->z->z->z->z->z = lcSdY(sizeof(struct qos9M));
    ff01->z->z->z->z->z->x = "ae437a06";
    ff01->z->z->z->z->z->y = &BN_bn2hex;
}

//mmn: return e1^e2
long hpLf0(long e1, int e2)
{
    long s;
    if (e1 == 0)
        s = 1;
    else if (e1 == 1)
        s = 2;
    else if (e1 == 2)
        s = 3;
    else if (e1 == 3)
        s = 4;
    else if (e1 == 4)
        s = 5;
    else if (e1 == 5)
        s = 6;
    else if (e1 == 6)
        s = 7;
    else if (e1 == 7)
        s = 8;
    else if (e1 == 8)
        s = 9;
    else
        s = 2147483647;
    int g01 = e1 * s;
    int g02 = g01 / 2;
    long r = e1 % s;
    if (e2 > 1) {
        for (int i = 0; i < e2 - 1; i++) {
            r = r * e1;
        }
    }
    return r;
}

long bVloC(long o1)
{
    return hpLf0(o1,1);
}
long rPPmT(long o2)
{
    return hpLf0(o2,2);
}
long RzsTI(long o3)
{
    return hpLf0(o3,3);
}
long A1PVW(long o4)
{
    return hpLf0(o4,4);
}
long XGf2G(long o5)
{
    return hpLf0(o5,5);
}
long EQa6v(long o6)
{
    return hpLf0(o6,6);
}
long wsFtJ(long o7)
{
    return hpLf0(o7,7);
}
long G8mo3(long o8)
{
    return hpLf0(o8,8);
}
long Nm5iX(long o9)
{
    return hpLf0(o9,9);
}
