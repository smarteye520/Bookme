//
// Created by USER on 07/09/2017.
//

#include "keysManagerCPP.h"

#include <string.h>
//#include <jni.h>

#include <string>
#include <fstream>
#include <iostream>

#include <sstream>


#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "const.h"

char * PATH_BASE;

void LogStringCpp(char * key, std::string x)
{
    char * x2 = new char[x.size() + 1];
    std::copy(x.begin(), x.end(), x2);
    x2[x.size()] = '\0'; // don't forget the terminating 0
    printf(key , x2);
}

void LogIntCpp(char * key, int x)
{
    printf(key , x);
}

std::string getx(int max)
{
    std::string y;
    y = "";
    char * x = "abcdefghijklmnopqrstuvwqyz1234567890ABCDEFGHIJKLMNOPQRSTUVWQYZ!@#$%^&*-/+_=~abcdefghijklmnopqrstuvwqyz1234567890ABCDEFGHIJKLMNOPQRSTUVWQYZ!@#$%^&*-+_=~./:";
    int i;
    for (i = 0; i< max; i++)
    {
        int iSecret = rand() % 100 + 1;
        y += x[iSecret];
    }
    return y;
}



std::string danacodeTransformation(const char* dc, int shift)
{
    char * x = "KaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfz";
    int count = strlen(dc);
    std::string w;
    w = "";
    for (int i=0; i<count; i++)
    {
        int y = ((int)dc[i])+shift;
        y = y % 310;
        w = w + x[y];
    }
    return w;
}



std::string getCharNotInThatString(std::string str)
{
    std::string x = "KaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfzKaFvM6ngOGApV17wPbWsRqQxohBNS8H2irtcyI9C13dLYmDZj4eJ0ETuX5kUfz";
    std::string y;
    y = "";
    srand (time(NULL));
    while (y == "")
    {
        int iSecret = rand() % 310;
        std::string thisChar = x.substr(iSecret,1) + "";
        if (str.find( thisChar, 0 )  == std::string::npos)
        {
            y = thisChar;
        }
    }
    return y;
}

std::string constCharToStdString(const char* x)
{
    int count = strlen(x);
    std::string y;
    y = "";
    for (int i=0; i < count; i++)
    {
        y += x[i];
    }
    return y;
}

std::string IntToStr(int n)
{
    /*std::ostringstream ntos;
    ntos << n;
    return ntos.str();*/
    if (n==0) return  "0";
    if (n==1) return  "1";
    else if (n==2) return  "2";
    else if (n==3) return  "3";
    else if (n==4) return  "4";
    else if (n==5) return  "5";
    else if (n==6) return  "6";
    else if (n==7) return  "7";
    else if (n==8) return  "8";
    else if (n==9) return  "9";
    else if (n==10) return  "10";
    else if (n==11) return  "11";
    else if (n==12) return  "12";
    else if (n==13) return  "13";
    else if (n==14) return  "14";
    else if (n==15) return  "15";
    else if (n==16) return  "16";
    else if (n==17) return  "17";
    else if (n==18) return  "18";
    else if (n==19) return  "19";
    else if (n==20) return  "20";
    else if (n==21) return  "21";
    else if (n==22) return  "22";
    else if (n==23) return  "23";
    else if (n==24) return  "24";
    else if (n==25) return  "25";
    else if (n==26) return  "26";
    else if (n==27) return  "27";
    else if (n==28) return  "28";
    else if (n==29) return  "29";
    else if (n==30) return  "30";
    else if (n==31) return  "31";
    else if (n==32) return  "32";
    else if (n==33) return  "33";
    else if (n==34) return  "34";
    else if (n==35) return  "35";
    else if (n==36) return  "36";
    else if (n==37) return  "37";
    else if (n==38) return  "38";
    else if (n==39) return  "39";
    else if (n==40) return  "40";
    else if (n==41) return  "41";
    else if (n==42) return  "42";
    else if (n==43) return  "43";
    else if (n==44) return  "44";
    else if (n==45) return  "45";
    else if (n==46) return  "46";
    else if (n==47) return  "47";
    else if (n==48) return  "48";
    else if (n==49) return  "49";
    else if (n==50) return  "50";
    else if (n==51) return  "51";
    else if (n==52) return  "52";
    else if (n==53) return  "53";
    else if (n==54) return  "54";
    else if (n==55) return  "55";
    else if (n==56) return  "56";
    else if (n==57) return  "57";
    else if (n==58) return  "58";
    else if (n==59) return  "59";
    else if (n==60) return  "60";
    else if (n==61) return  "61";
    else if (n==62) return  "62";
    else if (n==63) return  "63";
    else if (n==64) return  "64";
    else if (n==65) return  "65";
    else if (n==66) return  "66";
    else if (n==67) return  "67";
    else if (n==68) return  "68";
    else if (n==69) return  "69";
    else if (n==70) return  "70";
    else if (n==71) return  "71";
    else if (n==72) return  "72";
    else if (n==73) return  "73";
    else if (n==74) return  "74";
    else if (n==75) return  "75";
    else if (n==76) return  "76";
    else if (n==77) return  "77";
    else if (n==78) return  "78";
    else if (n==79) return  "79";
    else if (n==80) return  "80";
    else if (n==81) return  "81";
    else if (n==82) return  "82";
    else if (n==83) return  "83";
    else if (n==84) return  "84";
    else if (n==85) return  "85";
    else if (n==86) return  "86";
    else if (n==87) return  "87";
    else if (n==88) return  "88";
    else if (n==89) return  "89";
    else if (n==90) return  "90";
    else if (n==91) return  "91";
    else if (n==92) return  "92";
    else if (n==93) return  "93";
    else if (n==94) return  "94";
    else if (n==95) return  "95";
    else if (n==96) return  "96";
    else if (n==97) return  "97";
    else if (n==98) return  "98";
    else return  "99";
}

char * getX28ERpath()
{
    char * x28name = "x28.er";
    char * x28path = (char*)malloc(strlen(PATH_BASE) + strlen(x28name));
    strcpy(x28path, PATH_BASE);
    strcat(x28path, x28name);
    return x28path;
}

char * setKey ( const char *danacode, char *key,int shift, int kl)
{
    std::string d = danacodeTransformation(danacode,shift);
    std::string k = key;
    std::size_t found = k.find("=");
    if (found!=std::string::npos)
    {
        k.erase(found);
    }
    kl = k.size();
    std::string str_kl = IntToStr(k.size());

    srand (time(NULL));
    int r = rand() % (kl - 2);
    std::string k1 = k.substr(0,r);
    std::string k2 = k.substr(r);
    std::string k3 = getx(k2.length());
    std::string str_r = IntToStr(r);
    if (r < 10)
        str_r = "0" + str_r;

    std::string vk = k2 + d + str_kl + k1 + k3 + str_r;
    std::string l = getx(25000 - vk.length());

    int r1 = rand() % 9500;
    std::string lines = l.substr(0,r1) + vk + l.substr(r1);

    int dPosition = r1 + k2.length();

    std::string::size_type n = 0;
    while ( ( n = lines.find( d, n ) ) != std::string::npos )
    {
        if (n != dPosition)
        {
            std::string t = getCharNotInThatString(d);
            lines.replace(n, d.size(), t);
            n += t.size();
        }
        else
        {
            n+= 1;
        }
    }

    char * x28path = getX28ERpath();
    FILE* file = fopen(x28path,"r+"); //dont free x28 here
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long lSize = ftell(file);
        rewind(file);
        char *buffer = (char *) malloc(sizeof(char) * lSize);
        fread(buffer, 1, lSize, file);
        fclose(file);
        std::string cs1(buffer);
        free(buffer);
        n = 0;
        while ( ( n = cs1.find( d, n ) ) != std::string::npos )
        {
            std::string t = getCharNotInThatString(d);
            cs1.replace(n, d.size(), t);
            n += t.size();
        }
        lines = cs1 + lines;
    }

    const char* c_lines = lines.c_str();

    file = fopen(x28path,"w+");
    free(x28path);
    if (file != NULL)
    {
        fputs(c_lines, file);
        fflush(file);
        fclose(file);
    }

    const char * jvk = vk.c_str();
    return  (char*)jvk;
}

char * getE28(const char * danacode, int shift)
{
    std::string d = danacodeTransformation(danacode,shift);
    LogStringCpp("ddd %s",d);
    char *buffer;
    char * x28path = getX28ERpath();
    FILE* file = fopen(x28path,"r+");
    free(x28path);
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long lSize = ftell(file);
        rewind(file);
        buffer = (char *) malloc(sizeof(char) * lSize);
        fread(buffer, 1, lSize, file);
        fclose(file);
    }
    return buffer;
}

char * getKey(const char * danacode, int shift)
{
    std::string d = danacodeTransformation(danacode,shift);
    char * x28path = getX28ERpath();
    FILE* file = fopen(x28path,"r+");
    free(x28path);
    if (file != NULL)
    {
        fseek (file , 0 , SEEK_END);
        long lSize = ftell (file);
        rewind (file);
        char* buffer = (char*) malloc (sizeof(char)*lSize + 1);
        fread (buffer,1,lSize,file);
        fclose (file);

        std::string cs1(buffer);
        free(buffer);
        int loc1 = cs1.find(d);
        std::string kl_str = cs1.substr(loc1 + strlen(danacode),2);
        const char * c_kl_str = kl_str.c_str();
        int kl = atoi(c_kl_str);
        std::string r_str = cs1.substr(loc1 + strlen(danacode) + 2 + kl, 2);
        const char * c_r_str = r_str.c_str();
        int r1 = atoi(c_r_str);
        std::string k1 = cs1.substr(loc1 + strlen(danacode) + 2, r1);
        std::string k2 = cs1.substr(loc1 - (kl-r1),kl-r1);

        std::string k3 = k1+k2;
        if (k3.length() % 4 == 0)
            k3 = k3;
        if (k3.length() % 4 == 2)
            k3 = k3 + "==";
        else
            k3 = k3 + "=";

        const char * nk3 = k3.c_str();
        char * nnk3 = (char *) malloc(sizeof(char) * lSize + 1);
        strcpy(nnk3, nk3);
        return nnk3;
    }
    else
        return (char*)"";
}
