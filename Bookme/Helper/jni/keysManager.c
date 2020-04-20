//
// Created by Moish on 07/09/2017.
//

#include "keysManager.h"
#include <stdlib.h>
#include <string.h>
#include "commonUtil.h"

char * getx(int max)
{
    static char y[100];
    char * x = "abcdefghijklmnopqrstuvwqyz1234567890ABCDEFGHIJKLMNOPQRSTUVWQYZ!@#$%^&*/-+_=~abcdefghijklmnopqrstuvwqyz1234567890ABCDEFGHIJKLMNOPQRSTUVWQYZ!@#$%^&*/-+_=~.:";
    int i;
    for (i = 0; i< max; i++)
    {
        int iSecret = rand() % 100 + 1;
        y[i] = x[iSecret];
    }
    return y;
}


//@need to be free: w
char * danacodeTransformation(const char* dc, int shift)
{
    LogString("dc",dc);
    char * x = "KaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfz";
    int count = strlen(dc);
    LogInt("count",count);
    /*char * w = malloc(count);
    strcpy(w,"");
    for (int i=0; i<count; i++)
    {
        int y = ((int)dc[i])+shift;
        y = y % 310;
        strcat(w,(char*)x[y]);
    }
    return w;*/
    return x;
}



//char * setKey ( const char *danacode, char *key,int shift, int kl)
//{
//    return key;
//}
//
//char * getKey(const char * danacode, int shift)
//{
//    char * x = "x";
//    return  x;
//
//}

