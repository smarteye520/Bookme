//
// Created by USER on 06/10/2017.
//

#include "bm057.h"
#include "bm091.h"
#include <math.h>

void D0XMs(void * c)
{
    n9Dok(c);
}

void * Kv9DQ(size_t c)
{
    return wf0dx(c);
}

size_t fs9Mk(const char * c)
{
    return xGOzg(c);
}

struct HvSn8 * new_8HvSn()
{
    struct HvSn8 *const h = Kv9DQ(sizeof(struct HvSn8));
    h->x = new_fnYDP();
    return h;
}

struct pbMZZ * new_pbMZZ()
{
    struct pbMZZ *const h = Kv9DQ(sizeof(struct pbMZZ));
    h->x = new_AVDvx();
    return h;
}

struct pbMZZ * new_pbMZZ_HelXV()
{
    struct pbMZZ *const h = Kv9DQ(sizeof(struct pbMZZ));
    h->x = new_AVDvx_HelXV();
    return h;
}

void lxwNv(struct pbMZZ * c)
{
    wxKU5(c->x);
}

void pzmdd(struct HvSn8 * a,struct  pbMZZ * b)
{
    Up5rR(a->x,b->x);
}

int z1xBZ(char * d, char * u)
{
    int x = uFJPg(d, u);
    return x;
}

//mmn: garbage, find sqrt
double oD6Wk(int d)
{
    if (d <= 0)
        return 0;
    int exp = 0;
    d = frexp(d, &exp);
    if (exp & 1) {
        exp--;
        d *= 2;
    }
    double y = (1+d)/2;
    double z = 0;
    while (y != z) {
        z = y;
        y = (y + d/y) / 2;
    }
    return ldexp(y, exp/2);
}


//garbage, is prime...
void * zwT6G(int n)
{
    int i, flag = 0;
    for(i=2; i<=n/2; ++i)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    return flag == 0;
}
