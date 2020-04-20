//
// Created by Moish on 06/09/2017.
//

#ifndef BOOKMEDIGITALANDROID_DAL_H
#define BOOKMEDIGITALANDROID_DAL_H
#endif //BOOKMEDIGITALANDROID_DAL_H

#include <jni.h>
#include <nhr/cJSON/cJSON.h>

int set_product(const unsigned char *, const unsigned char *,
            const unsigned char * , const unsigned char *, const int ,
            const unsigned char * , const unsigned char *,
            const unsigned char *, const unsigned char * ,
            const unsigned char * , const unsigned char * ,
            const unsigned char * );

int set_sections(const unsigned char *, cJSON *);

char * get_product_details(char *, int *, char **, char **, char **, char **, char **,
                           char **, char **, char **, char **, char **,char **, char **,
                           char **, char **,char **, char **);

char * get_product_content(char * , int, char ** );

char * get_all_products();

void update_product_chapter(char * , int );

void update_product_chapter_by_shift(char *, int);

void update_chapter_position(char *, int);

char * get_product_toc(char *);

int delete_product(const unsigned char * );