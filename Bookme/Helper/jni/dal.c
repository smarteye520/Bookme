//
// Created by Moish on 06/09/2017.
//

#include "dal.h"
#include "const.h"
#include <string.h>
#include "stdio.h"
#include <stdlib.h>
#include "sqlite3/sqlite3.h"
#include "commonUtil.h"

//need2free: productsPath (return value)
char * get_products_db_path(void)
{
    int length = strlen(PATH_BASE) + strlen(PRODUCTS_DB_NAME);
    char * productsPath = (char*)malloc(length + 1);
    strcpy(productsPath, PATH_BASE);
    strcat(productsPath, PRODUCTS_DB_NAME);
    productsPath[length] = '\0';
    return productsPath;
}

//need2free: productsPath (return value)
char * get_product_db_path(char * danacode)
{
    int length = strlen(PATH_BASE) + strlen(danacode) + strlen(DB_EXT);
    char * productPath = (char*)malloc(length + 1);
    strcpy(productPath, PATH_BASE);
    strcat(productPath, danacode);
    strcat(productPath, DB_EXT);
    productPath[length] = '\0';
    return productPath;
}

static int database_callback1(void *NotUsed, int argc, char **argv, char **azColName) {
    return 0;
}

static int database_callback2(void *data, int argc, char **argv, char **azColName){
    return 0;
}

sqlite3 * open_data_base(const unsigned char * path)
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open_v2(path, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);

    if( rc ) {
        return NULL;
    } else {
        return db;
    }
}

//need2free: csql (return value)
char * get_create_product_table_sql(void)
{
    char *sql1 = "CREATE TABLE if not exists ";
    char *sql2 = " ( ";
    char *sql3 = " INTEGER PRIMARY KEY AUTOINCREMENT, ";
    char *sql4 = " TEXT, ";
    char *sql5 = " TEXT ";
    char *sql6 = " )";
    char *sql7 = " UNIQUE ";
    char *sql8 = " , ";

    int length = strlen(sql1) + strlen(PRODUCTS_TABLE_NAME) + strlen(sql2)
                 + strlen(PRODUCTS_FIELD_NAME_ID) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE)  + strlen(sql5) + strlen(sql7) + strlen(sql8)
                 + strlen(PRODUCTS_FIELD_NAME_BOOKNAME) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_COVER) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_KEYTOKEN) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_FONT_SIZE) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_COLUMN_PIXEL) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM1) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM3) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM4) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM5) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM6) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM7) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM8) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM9) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM10) + strlen(sql5)  + strlen(sql6);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_FIELD_NAME_ID);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql5);
    strcat(csql, sql7);
    strcat(csql, sql8);
    strcat(csql, PRODUCTS_FIELD_NAME_BOOKNAME);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_COVER);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_KEYTOKEN);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_FONT_SIZE);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_COLUMN_PIXEL);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM1);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM3);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM4);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM5);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM6);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM7);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM8);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM9);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM10);
    strcat(csql, sql5);
    strcat(csql, sql6);
    csql[length] = '\0';
    return csql;

}

//need2free: csql (return value)
char * get_create_files_table_sql(void)
{
    char *sql1 = "CREATE TABLE if not exists ";
    char *sql2 = " ( ";
    char *sql3 = " INTEGER PRIMARY KEY AUTOINCREMENT, ";
    char *sql4 = " INTEGER ";
    char *sql5 = " TEXT ";
    char *sql6 = " )";
    char *sql7 = " , ";
    char *sql8 = " TEXT ";

    int length = strlen(sql1) + strlen(FILES_TABLE_NAME) + strlen(sql2)
                 + strlen(FILES_FIELD_NAME_ID) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_TYPE)  + strlen(sql5) + strlen(sql7)
                 + strlen(FILES_FIELD_NAME_TYPE_NUM) + strlen(sql4)+ strlen(sql7)
                 + strlen(FILES_FIELD_NAME_VALUE) + strlen(sql8)+ strlen(sql7)
                 + strlen(FILES_FIELD_NAME_PARAM1) + strlen(sql5)+ strlen(sql7)
                 + strlen(FILES_FIELD_NAME_PARAM2) + strlen(sql5)+ strlen(sql6);
    char* csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, FILES_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, FILES_FIELD_NAME_ID);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_TYPE);
    strcat(csql, sql5);
    strcat(csql, sql7);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM);
    strcat(csql, sql4);
    strcat(csql, sql7);
    strcat(csql, FILES_FIELD_NAME_VALUE);
    strcat(csql, sql8);
    strcat(csql, sql7);
    strcat(csql, FILES_FIELD_NAME_PARAM1);
    strcat(csql, sql5);
    strcat(csql, sql7);
    strcat(csql, FILES_FIELD_NAME_PARAM2);
    strcat(csql, sql5);
    strcat(csql, sql6);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_delete_files_table_sql(void)
{
    char *sql1 = "DELETE FROM ";
    char* csql;
    int length = strlen(sql1) + strlen(FILES_TABLE_NAME);
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, FILES_TABLE_NAME);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_add_new_product_sql(void)
{
    char *sql1 = "INSERT INTO ";
    char *sql2 = "(";
    char *sql3 = ",";
    char *sql4 = " VALUES ";
    char *sql5 = ")";
    char *sql6 = "'";
    char *sql7 = ";";
    char *sql8 = "00";
    int length = strlen(sql1) + strlen(PRODUCTS_TABLE_NAME) + strlen(sql2)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_BOOKNAME) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_COVER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM1) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM3) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM4) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM5) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM6) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM7) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM8) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM9) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM10) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_KEYTOKEN) + strlen(sql5)
                 + strlen(sql4) + strlen(sql2)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_BOOKNAME_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_COVER_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM1_PARAMETER) + strlen(sql3)
                 + strlen(sql6) + strlen(sql8) + strlen(sql6) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM3_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM4_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM5_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM6_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM7_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM8_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM9_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM10_PARAMETER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_KEYTOKEN_PARAMETER) + strlen(sql5) + strlen(sql7);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_BOOKNAME);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_COVER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM1);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM3);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM4);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM5);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM6);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM7);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM8);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM9);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM10);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_KEYTOKEN);
    strcat(csql, sql5);
    strcat(csql, sql4);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_BOOKNAME_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_COVER_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM1_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, sql6);
    strcat(csql, sql8);
    strcat(csql, sql6);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM3_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM4_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM5_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM6_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM7_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM8_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM9_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM10_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_KEYTOKEN_PARAMETER);
    strcat(csql, sql5);
    strcat(csql, sql7);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_add_new_section_sql(void)
{
    char *sql1 = "INSERT INTO ";
    char *sql2 = "(";
    char *sql3 = ",";
    char *sql4 = " VALUES ";
    char *sql5 = ")";
    char *sql7 = ";";
    int length = strlen(sql1) + strlen(FILES_TABLE_NAME) + strlen(sql2)
                 + strlen(FILES_FIELD_NAME_TYPE) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_TYPE_NUM) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_PARAM1) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_PARAM2) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_VALUE) + strlen(sql5)
                 + strlen(sql4) + strlen(sql2)
                 + strlen(FILES_FIELD_NAME_TYPE_PARAMETER) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_TYPE_NUM_PARAMETER) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_PARAM1_PARAMETER) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_PARAM2_PARAMETER) + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_VALUE_PARAMETER) + strlen(sql5) + strlen(sql7);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, FILES_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, FILES_FIELD_NAME_TYPE);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_PARAM1);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_PARAM2);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_VALUE);
    strcat(csql, sql5);
    strcat(csql, sql4);
    strcat(csql, sql2);
    strcat(csql, FILES_FIELD_NAME_TYPE_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_PARAM1_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_PARAM2_PARAMETER);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_VALUE_PARAMETER);
    strcat(csql, sql5);
    strcat(csql, sql7);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_select_product_sql_all_columns(void)
{
    char *sql3 = " , ";
    int length = strlen(PRODUCTS_FIELD_NAME_ID) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_BOOKNAME) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_COVER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_KEYTOKEN) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_FONT_SIZE) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_COLUMN_PIXEL) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM1) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM3) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM4) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM5) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM6) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM7) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM8) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM9) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM10);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, PRODUCTS_FIELD_NAME_ID);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_BOOKNAME);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_COVER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_KEYTOKEN);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_FONT_SIZE);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_COLUMN_PIXEL);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM1);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM3);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM4);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM5);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM6);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM7);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM8);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM9);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM10);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_select_products_sql(int mode)
{
    char *sql1 = "SELECT ";
    char *sql2 = " FROM ";
    char *sql5 = get_select_product_sql_all_columns(); //mode 1, *
    if (mode == 3) {
        char * sql5a = " count(*) AS \"Count Of Product\" ";
        int length = strlen(sql5a);
        sql5 = (char *)malloc(length + 1);
        strcpy(sql5,sql5a);
        sql5[length] = '\0';
    }

    int length = strlen(sql1) + strlen(sql5) + strlen(sql2) + strlen(PRODUCTS_TABLE_NAME);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, sql5);
    free(sql5);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_TABLE_NAME);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_select_product_sql_by_danacode(int mode)
{
    char *sql1 = "SELECT ";
    char *sql2 = " FROM ";
    char *sql3 = " WHERE ";
    char *sql4 = "=";
    char *sql5 = get_select_product_sql_all_columns(); //mode 1, *
    if (mode == 3) {
        char * sql5a = " count(*) AS \"Count Of Product\" ";
        int length = strlen(sql5a);
        sql5 = (char *)malloc(length + 1);
        strcpy(sql5,sql5a);
        sql5[length] = '\0';
    }

    int length = strlen(sql1) + strlen(sql5) + strlen(sql2)
                 + strlen(PRODUCTS_TABLE_NAME) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, sql5);
    free(sql5);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    csql[length] = '\0';

    return csql;
}

//need2free: csql (return value)
char * get_select_save_chapter(void)
{
    char *sql1 = "SELECT ";
    char *sql2 = " FROM ";
    char *sql3 = " WHERE ";
    char *sql4 = "=";

    int length = strlen(sql1) + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER) + strlen(sql2)
                 + strlen(PRODUCTS_TABLE_NAME) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_delete_product_sql_by_danacode(void)
{
    char *sql1 = "DELETE ";
    char *sql2 = " FROM ";
    char *sql3 = " WHERE ";
    char *sql4 = "=";

    int length = strlen(sql1) + strlen(sql2)
                 + strlen(PRODUCTS_TABLE_NAME) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_select_content_sql(void)
{
    char *sql1 = "SELECT ";
    char *sql2 = " FROM ";
    char *sql3 = " WHERE ";
    char *sql4 = "=";
    char *sql5 = " AND ";
    char *sql6 = " , ";

    int length = strlen(sql1) + strlen(FILES_FIELD_NAME_VALUE)
                 + strlen(sql6) + strlen(FILES_FIELD_NAME_PARAM1)
                 + strlen(sql2) + strlen(FILES_TABLE_NAME)
                 + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_TYPE) + strlen(sql4) + strlen(FILES_FIELD_NAME_TYPE_PARAMETER)
                 + strlen(sql5)
                 + strlen(FILES_FIELD_NAME_TYPE_NUM) + strlen(sql4)
                 + strlen(FILES_FIELD_NAME_TYPE_NUM_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, FILES_FIELD_NAME_VALUE);
    strcat(csql, sql6);
    strcat(csql, FILES_FIELD_NAME_PARAM1);
    strcat(csql, sql2);
    strcat(csql, FILES_TABLE_NAME);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_TYPE);
    strcat(csql, sql4);
    strcat(csql, FILES_FIELD_NAME_TYPE_PARAMETER);
    strcat(csql, sql5);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM);
    strcat(csql, sql4);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM_PARAMETER);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_update_save_chapter(void)
{
    char *sql1 = "UPDATE ";
    char *sql2 = " SET ";
    char *sql3 = " = ";
    char *sql4 = " WHERE ";
    char *sql6 = " , ";

    int length = strlen(sql1) + strlen(PRODUCTS_TABLE_NAME) + strlen(sql2)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_SAVE_CHAPTER_PARAMETER) + strlen(sql6)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2)  + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2_PARAMETER) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    char* csql;
    csql = ( char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_SAVE_CHAPTER_PARAMETER);
    strcat(csql, sql6);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2_PARAMETER);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    csql[length] = '\0';
    return csql;
}

//need2free: csql (return value)
char * get_update_save_position_chapter(void)
{
    char *sql1 = "UPDATE ";
    char *sql2 = " SET ";
    char *sql3 = " = ";
    char *sql4 = " WHERE ";

    int length = strlen(sql1) + strlen(PRODUCTS_TABLE_NAME) + strlen(sql2)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_PARAM2_PARAMETER) + strlen(sql4)
                 + strlen(PRODUCTS_FIELD_NAME_DATANCODE) + strlen(sql3)
                 + strlen(PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, PRODUCTS_TABLE_NAME);
    strcat(csql, sql2);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_PARAM2_PARAMETER);
    strcat(csql, sql4);
    strcat(csql, PRODUCTS_FIELD_NAME_DATANCODE);
    strcat(csql, sql3);
    strcat(csql, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    csql[length] = '\0';
    return csql;
}



int set_product(const unsigned char * danacode, const unsigned char * bookname,
                const unsigned char * cover , const unsigned char * keyToken,
                const int shift, const unsigned char * authors, const unsigned char * manufacturer,
                const unsigned char * language, const unsigned char * description,
                const unsigned char * subject, const unsigned char * contributor,
                const unsigned char * numOfCharacters, const unsigned char * numOfSection)
{

    char * productsPath = get_products_db_path();

    char *zErrMsg = 0;
    sqlite3 * db = open_data_base(productsPath);
    if (db == NULL)
    {
        free(productsPath);
        return ERROR_CANNOT_CONNECT_TO_DB;
    }
    free(productsPath);

    char *sql1 = get_create_product_table_sql();
    int rc = sqlite3_exec(db, sql1, database_callback1, 0, &zErrMsg);
    free(sql1);
    if( rc != SQLITE_OK ){
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return (1);
    }

    sqlite3_stmt *res;
    char *sql2 = get_select_product_sql_by_danacode(3);
    rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return (2);
    }
    int idx = sqlite3_bind_parameter_index(res, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res, idx, danacode, strlen(danacode), 0);
    int step = sqlite3_step(res);
    if (step != SQLITE_ROW) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return (3);
    }
    int count = sqlite3_column_int(res, 0);
    sqlite3_finalize(res);

    if (count > 0) {
        sqlite3_stmt *res2;
        char *sql3 =  get_delete_product_sql_by_danacode();
        rc = sqlite3_prepare_v2(db, sql3, -1, &res2, 0);
        free(sql3);
        if (rc != SQLITE_OK) {
            sqlite3_finalize(res2);
            sqlite3_close(db);
            return (4);
        }
        int idx2 = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
        sqlite3_bind_text(res2, idx2, danacode, strlen(danacode), 0);
        sqlite3_step(res2);
        sqlite3_finalize(res2);
    }

    sqlite3_stmt *res3;
    char *sql4 = get_add_new_product_sql();
    rc = sqlite3_prepare_v2(db, sql4, -1, &res3, 0);
    free(sql4);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res3);
        sqlite3_close(db);
        return (5);
    }
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res3, idx, danacode, strlen(danacode), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_BOOKNAME_PARAMETER);
    sqlite3_bind_text(res3, idx, bookname, strlen(bookname), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_COVER_PARAMETER);
    sqlite3_bind_text(res3, idx, cover, strlen(cover), 0);
    char * str_shift = intToString(shift);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM1_PARAMETER);
    sqlite3_bind_text(res3, idx, str_shift, strlen(str_shift), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM3_PARAMETER);
    sqlite3_bind_text(res3, idx, authors, strlen(authors), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM4_PARAMETER);
    sqlite3_bind_text(res3, idx, manufacturer, strlen(manufacturer), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM5_PARAMETER);
    sqlite3_bind_text(res3, idx, language, strlen(language), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_KEYTOKEN_PARAMETER);
    sqlite3_bind_text(res3, idx, keyToken, strlen(keyToken), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM6_PARAMETER);
    sqlite3_bind_text(res3, idx, description, strlen(description), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM7_PARAMETER);
    sqlite3_bind_text(res3, idx, subject, strlen(subject), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM8_PARAMETER);
    sqlite3_bind_text(res3, idx, contributor, strlen(contributor), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM9_PARAMETER);
    sqlite3_bind_text(res3, idx, numOfCharacters, strlen(numOfCharacters), 0);
    idx = sqlite3_bind_parameter_index(res3, PRODUCTS_FIELD_NAME_PARAM10_PARAMETER);
    sqlite3_bind_text(res3, idx, numOfSection, strlen(numOfSection), 0);

    step = sqlite3_step(res3);
    if( step != SQLITE_DONE ){
        sqlite3_finalize(res3);
        sqlite3_close(db);
        return (6);
    }
    sqlite3_free(zErrMsg);
    sqlite3_finalize(res3);
    sqlite3_close(db);
    free(str_shift);
    return (0);
}

int set_sections(const unsigned char * danacode, cJSON * json)
{
    char *zErrMsg = 0;
    char * pathFiles = get_product_db_path(danacode);
    sqlite3 * db = open_data_base(pathFiles);
    free(pathFiles);
    if (db == NULL)
    {
        return ERROR_CANNOT_CONNECT_TO_DB;
    }
    char *sql5 = get_create_files_table_sql();
    int rc = sqlite3_exec(db, sql5, database_callback1, 0, &zErrMsg);
    free(sql5);
    if( rc != SQLITE_OK ){
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 8;
    }
    char *sql6 = get_delete_files_table_sql();
    rc = sqlite3_exec(db, sql6, database_callback1, 0, &zErrMsg);
    free(sql6);
    if( rc != SQLITE_OK ){
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 9;
    }
    cJSON * numOfSection = cJSON_GetObjectItem(json, "numOfSection");
    char * s_numOfSection = numOfSection->valuestring;
    int i_numOfSection = StringToInt(s_numOfSection);

    for (int iii=0; iii<i_numOfSection; iii++) {
        sqlite3_stmt *res3;
        char * sql7 = get_add_new_section_sql();
        int rc3 = sqlite3_prepare_v2(db, sql7, -1, &res3, 0);
        if (rc3 != SQLITE_OK) {
            free(sql7);
            sqlite3_finalize(res3);
            sqlite3_close(db);
            return 10;
        }
        free(sql7);
        int chapterTitleKeyLength = 15;
        if (iii > 9)
            chapterTitleKeyLength = 16;
        if (iii > 99)
            chapterTitleKeyLength = 17;
        char chapterTitleKey[chapterTitleKeyLength];
        sprintf(chapterTitleKey, "section_%d_title", iii);
        cJSON * jChapterTitle = cJSON_GetObjectItem(json, chapterTitleKey);
        unsigned char * chapterTitle = jChapterTitle->valuestring;

        int chapterNameKeyLength = 18;
        if (iii > 9)
            chapterNameKeyLength = 19;
        if (iii > 99)
            chapterNameKeyLength = 20;
        char chapterNameKey[chapterNameKeyLength];
        sprintf(chapterNameKey, "section_%d_fileName", iii);
        cJSON * jChapterName = cJSON_GetObjectItem(json, chapterNameKey);
        unsigned char * chapterName = jChapterName->valuestring;

        int chapterContentKeyLength = 17;
        if (iii > 9)
            chapterContentKeyLength = 18;
        if (iii > 99)
            chapterContentKeyLength = 19;
        char chapterContentKey[chapterContentKeyLength];
        sprintf(chapterContentKey, "section_%d_content", iii);
        cJSON * jChapterContent = cJSON_GetObjectItem(json, chapterContentKey);
        unsigned char * chapterContent = jChapterContent->valuestring;

        int idx3 = sqlite3_bind_parameter_index(res3, FILES_FIELD_NAME_TYPE_PARAMETER);
        sqlite3_bind_text(res3, idx3, FILES_TYPE_CHAPTER, strlen(FILES_TYPE_CHAPTER), 0);
        int idx4 = sqlite3_bind_parameter_index(res3, FILES_FIELD_NAME_TYPE_NUM_PARAMETER);
        sqlite3_bind_int(res3, idx4, iii);
        int idx5 = sqlite3_bind_parameter_index(res3, FILES_FIELD_NAME_PARAM1_PARAMETER);
        sqlite3_bind_text(res3, idx5, chapterTitle, strlen(chapterTitle), 0);
        int idx6 = sqlite3_bind_parameter_index(res3, FILES_FIELD_NAME_PARAM2_PARAMETER);
        sqlite3_bind_text(res3, idx6, chapterName, strlen(chapterName), 0);
        int idx7 = sqlite3_bind_parameter_index(res3, FILES_FIELD_NAME_VALUE_PARAMETER);
        sqlite3_bind_text(res3, idx7, chapterContent, strlen(chapterContent), 0);

        sqlite3_step(res3);
        sqlite3_reset(res3);
        //sqlite3_finalize(res3);
    }
    sqlite3_close(db);
    return 0;
}


//need2free: jsonSerialize (return value)
//return error in this function muse be 1 character only
//if more the 1 character the caller know it valid json
char * get_all_products(void)
{
    char * productsPath = get_products_db_path();

    sqlite3 * db = open_data_base(productsPath);
    if (db == NULL)
    {
        free(productsPath);
        return "ERROR_CANNOT_CONNECT_TO_DB";
    }
    free(productsPath);

    sqlite3_stmt *res;
    char *sql2 = get_select_products_sql(1);
    int rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return "3";
    }
    cJSON * json = cJSON_CreateObject();
    int step = sqlite3_step(res);
    int i = 0;
    while (step == SQLITE_ROW) {
        cJSON * bookObj = cJSON_CreateObject();
        unsigned char * rdc = sqlite3_column_text(res,1);
        if (rdc != NULL)
            cJSON_AddStringToObject(bookObj, "danacode", rdc);
        unsigned char * rbn = sqlite3_column_text(res,2);
        if (rbn != NULL)
            cJSON_AddStringToObject(bookObj, "bookName", rbn);
        unsigned char * rc = sqlite3_column_text(res,3);
        if (rc != NULL)
            cJSON_AddStringToObject(bookObj, "cover", rc);
        unsigned char * rauthor = sqlite3_column_text(res,10);
        if (rauthor != NULL)
            cJSON_AddStringToObject(bookObj, "author", rauthor);
        unsigned char * rmanufacturer = sqlite3_column_text(res,11);
        if (rmanufacturer != NULL)
            cJSON_AddStringToObject(bookObj, "manufacturer", rmanufacturer);
        unsigned char * rlanguage = sqlite3_column_text(res,12);
        if (rlanguage != NULL)
            cJSON_AddStringToObject(bookObj, "language", rlanguage);

        unsigned char * rsavechapter = sqlite3_column_text(res,5);
        if (rsavechapter != NULL)
            cJSON_AddStringToObject(bookObj, "saveChapter", rsavechapter);

        unsigned char * rnumofchapters = sqlite3_column_text(res,17);
        if (rnumofchapters != NULL)
            cJSON_AddStringToObject(bookObj, "numOfChapters", rnumofchapters);

        unsigned char * rdescription = sqlite3_column_text(res,13);
        if (rdescription != NULL)
            cJSON_AddStringToObject(bookObj, "description", rdescription);

        int bookObjKeyLength = 3;
        if (i > 9)
            bookObjKeyLength = 4;
        else if (i > 99)
            bookObjKeyLength = 5;
        char bookObjKey[bookObjKeyLength];
        sprintf(bookObjKey, "b_%d", i);
        cJSON_AddItemToObject(json,bookObjKey,bookObj);
        step = sqlite3_step(res); //TODO: find the right way
        i++;
    }
    cJSON_AddNumberToObject(json, "numOfBooks", i);

    sqlite3_finalize(res);
    sqlite3_close(db);

    char * jsonSerialize = cJSON_Print(json);
    cJSON_Delete(json);
    return jsonSerialize;
}

void update_product_chapter_by_shift(char * danacode, int shift)
{
    char * productPath = get_products_db_path();
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
        return;
    }
    free(productPath);

    char *sql2 = get_select_save_chapter();
    sqlite3_stmt *res;
    int rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return;
    }
    int idx = sqlite3_bind_parameter_index(res, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res, idx, danacode, strlen(danacode), 0);
    int step = sqlite3_step(res);

    int i_currentChapter;
    if (step == SQLITE_ROW) {
        unsigned char * currentSaveChapter = sqlite3_column_text(res,0);
        if (currentSaveChapter == NULL) {
            i_currentChapter = 0;
        }
        else {
            i_currentChapter = StringToInt(currentSaveChapter);
        }
    }
    else {
        i_currentChapter = 0;
    }
    sqlite3_finalize(res);
    sqlite3_close(db);

    update_product_chapter(danacode, i_currentChapter + shift);
}

void update_product_chapter(char * danacode, int chapter)
{
    char * productPath = get_products_db_path();
    char *zErrMsg = 0;
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
        return;
    }
    free(productPath);

    char *sql3 = get_update_save_chapter();
    sqlite3_stmt *res2;
    int rc = sqlite3_prepare_v2(db, sql3, -1, &res2, 0);
    free(sql3);
    if( rc != SQLITE_OK ){
        sqlite3_free(zErrMsg);
        sqlite3_finalize(res2);
        sqlite3_close(db);
        return;
    }
    char * s_chapter = intToString(chapter);
    int idx = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_SAVE_CHAPTER_PARAMETER);
    sqlite3_bind_text(res2, idx, s_chapter, strlen(s_chapter), 0);
    idx = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res2, idx, danacode, strlen(danacode), 0);

    char * s_position = "0";
    idx = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_PARAM2_PARAMETER);
    sqlite3_bind_text(res2, idx, s_position, strlen(s_position), 0);

    sqlite3_step(res2);
    sqlite3_finalize(res2);
    sqlite3_close(db);
    free(s_chapter);
}

void update_chapter_position(char * danacode, int position)
{
    char * productPath = get_products_db_path();
    char *zErrMsg = 0;
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
        return;
    }
    free(productPath);

    char *sql3 = get_update_save_position_chapter();
    sqlite3_stmt *res2;
    int rc = sqlite3_prepare_v2(db, sql3, -1, &res2, 0);
    free(sql3);
    if( rc != SQLITE_OK ){
        sqlite3_free(zErrMsg);
        sqlite3_finalize(res2);
        sqlite3_close(db);
        return;
    }
    char * s_position = intToString(position);
    int idx = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_PARAM2_PARAMETER);
    sqlite3_bind_text(res2, idx, s_position, strlen(s_position), 0);
    idx = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res2, idx, danacode, strlen(danacode), 0);
    sqlite3_step(res2);
    sqlite3_finalize(res2);
    sqlite3_close(db);
    free(s_position);
}

//need2free: content (return value), outTitle
char * get_product_content(char * danacode, int chapter, char ** outTitle)
{
    char * productPath = get_product_db_path(danacode);

    char *zErrMsg = 0;
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
    }
    free(productPath);
    sqlite3_stmt *res;

    char *sql2 = get_select_content_sql();
    int rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return "3";
    }
    int idx = sqlite3_bind_parameter_index(res, FILES_FIELD_NAME_TYPE_PARAMETER);
    sqlite3_bind_text(res, idx, FILES_TYPE_CHAPTER, strlen(FILES_TYPE_CHAPTER), 0);
    idx = sqlite3_bind_parameter_index(res, FILES_FIELD_NAME_TYPE_NUM_PARAMETER);
    sqlite3_bind_int(res, idx, chapter);
    int step = sqlite3_step(res);

    char * content = "";
    if (step == SQLITE_ROW) {
        char * content2 = sqlite3_column_text(res,0);
        if (content2 != NULL) {
            int len1 = strlen(content2);
            content = (char *) malloc(len1 + 1);
            strcpy(content, content2);
            content[len1] = '\0';
        }
        else {
            content = NULL;
        }

        unsigned char * title2 = sqlite3_column_text(res,1);
        if (title2 != NULL) {
            int len2 = strlen(title2);
            *outTitle = (unsigned char *)malloc(len2 + 1);
            strcpy(*outTitle, title2);
            outTitle[len2] = '\0';
        } else {
            *outTitle = NULL;
        }
    }
    sqlite3_finalize(res);
    sqlite3_close(db);

    return content;
}

char * get_product_details(char * danacode, int * outBookNum, char ** outBookName, char ** outBookCover,
                            char ** outKt, char ** outSaveChapter, char ** outSaveFontSize,
                            char ** outSaveColumnPixel, char ** outParam1, char ** outParam2,
                           char ** outParam3, char ** outParam4,char ** outParam5, char ** outParam6,
                           char ** outParam7, char ** outParam8,char ** outParam9, char ** outParam10)
{
    char * productPath = get_products_db_path();
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
        return "ERROR_CANNOT_CONNECT_TO_DB";
    }
    free(productPath);
    sqlite3_stmt *res;
    char *sql2 = get_select_product_sql_by_danacode(1);
    int rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return "3";
    }
    int idx = sqlite3_bind_parameter_index(res, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res, idx, danacode, strlen(danacode), 0);
    int step = sqlite3_step(res);
    if (step == SQLITE_ROW) {
        if (*outBookNum == 1) {
            *outBookNum = sqlite3_column_int(res, 0);
        }
        if (*outBookName == "1") {
            unsigned char * bookName2 = sqlite3_column_text(res, 2);
            if (bookName2 != NULL) {
                *outBookName = malloc(sizeof(char) * strlen(bookName2) + 1);
                strcpy(*outBookName, bookName2);
            }
            else {
                *outBookName = NULL;
            }
        }
        if (*outBookName == "1") {
            unsigned char * bookName2 = sqlite3_column_text(res, 2);
            if (bookName2 != NULL) {
                *outBookName = malloc(sizeof(char) * strlen(bookName2) + 1);
                strcpy(*outBookName, bookName2);
            }
            else {
                *outBookName = NULL;
            }
        }
        if (*outBookCover == "1") {
            unsigned char *bookCover2 = sqlite3_column_text(res, 3);
            if (bookCover2 != NULL) {
                *outBookCover = malloc(sizeof(char) * strlen(bookCover2) + 1);
                strcpy(*outBookCover, bookCover2);
            }
            else {
                *outBookCover = NULL;
            }
        }
        if (*outKt == "1") {
            unsigned char *bookKeyToken2 = sqlite3_column_text(res, 4);
            if (bookKeyToken2 != NULL) {
                *outKt = malloc(sizeof(char) * strlen(bookKeyToken2) + 1);
                strcpy(*outKt, bookKeyToken2);
            }
            else {
                *outKt = NULL;
            }
        }
        if (*outSaveChapter == "1") {
            unsigned char *bookSaveChapter2 = sqlite3_column_text(res, 5);
            if (bookSaveChapter2 != NULL) {
                *outSaveChapter = malloc(sizeof(char) * strlen(bookSaveChapter2) + 1);
                strcpy(*outSaveChapter, bookSaveChapter2);
            }
            else {
                *outSaveChapter = NULL;
            }
        }
        if (*outSaveFontSize == "1") {
            unsigned char *bookSaveFontSize2 = sqlite3_column_text(res, 6);
            if (bookSaveFontSize2 != NULL) {
                *outSaveFontSize = malloc(sizeof(char) * strlen(bookSaveFontSize2) + 1);
                strcpy(*outSaveFontSize, bookSaveFontSize2);
            }
            else {
                *outSaveFontSize = NULL;
            }
        }
        if (*outSaveColumnPixel == "1") {
            unsigned char *bookSaveColumnPixel = sqlite3_column_text(res, 7);
            if (bookSaveColumnPixel != NULL) {
                *outSaveColumnPixel = malloc(sizeof(char) * strlen(bookSaveColumnPixel) + 1);
                strcpy(*outSaveColumnPixel, bookSaveColumnPixel);
            }
            else {
                *outSaveColumnPixel = NULL;
            }
        }
        if (*outParam1 == "1") {
            unsigned char *bookParam1 = sqlite3_column_text(res, 8);
            if (bookParam1 != NULL) {
                *outParam1 = malloc(sizeof(char) * strlen(bookParam1) + 1);
                strcpy(*outParam1, bookParam1);
            }
            else {
                *outParam1 = NULL;
            }
        }
        if (*outParam2 == "1") {
            unsigned char *bookParam2 = sqlite3_column_text(res, 9);
            if (bookParam2 != NULL) {
                *outParam2 = malloc(sizeof(char) * strlen(bookParam2) + 1);
                strcpy(*outParam2, bookParam2);
            }
            else {
                *outParam2 = "0";
            }
        }
        if (*outParam3 == "1") {
            unsigned char *bookParam3 = sqlite3_column_text(res, 10);
            if (bookParam3 != NULL) {
                *outParam3 = malloc(sizeof(char) * strlen(bookParam3) + 1);
                strcpy(*outParam3, bookParam3);
            }
            else {
                *outParam3 = NULL;
            }
        }
        if (*outParam4 == "1") {
            unsigned char *bookParam4 = sqlite3_column_text(res, 11);
            if (bookParam4 != NULL) {
                *outParam4 = malloc(sizeof(char) * strlen(bookParam4) + 1);
                strcpy(*outParam4, bookParam4);
            }
            else {
                *outParam4 = NULL;
            }
        }
        if (*outParam5 == "1") {
            unsigned char *bookParam5 = sqlite3_column_text(res, 12);
            if (bookParam5 != NULL) {
                *outParam5 = malloc(sizeof(char) * strlen(bookParam5) + 1);
                strcpy(*outParam5, bookParam5);
            }
            else {
                *outParam5 = NULL;
            }
        }
        if (*outParam6 == "1") {
            unsigned char *bookParam6 = sqlite3_column_text(res, 13);
            if (bookParam6 != NULL) {
                *outParam6 = malloc(sizeof(char) * strlen(bookParam6) + 1);
                strcpy(*outParam6, bookParam6);
            }
            else {
                *outParam6 = NULL;
            }
        }
        if (*outParam7 == "1") {
            unsigned char *bookParam7 = sqlite3_column_text(res, 14);
            if (bookParam7 != NULL) {
                *outParam7 = malloc(sizeof(char) * strlen(bookParam7) + 1);
                strcpy(*outParam7, bookParam7);
            }
            else {
                *outParam7 = NULL;
            }
        }
        if (*outParam8 == "1") {
            unsigned char *bookParam8 = sqlite3_column_text(res, 15);
            if (bookParam8 != NULL) {
                *outParam8 = malloc(sizeof(char) * strlen(bookParam8) + 1);
                strcpy(*outParam8, bookParam8);
            }
            else {
                *outParam8 = NULL;
            }
        }
        if (*outParam9 == "1") {
            unsigned char *bookParam9 = sqlite3_column_text(res, 16);
            if (bookParam9 != NULL) {
                *outParam9 = malloc(sizeof(char) * strlen(bookParam9) + 1);
                strcpy(*outParam9, bookParam9);
            }
            else {
                *outParam9 = NULL;
            }
        }
        if (*outParam10 == "1") {
            unsigned char *bookParam10 = sqlite3_column_text(res, 17);
            if (bookParam10 != NULL) {
                *outParam10 = malloc(sizeof(char) * strlen(bookParam10) + 1);
                strcpy(*outParam10, bookParam10);
            }
            else {
                *outParam10 = NULL;
            }
        }
    }
    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return NULL;
}

//need2free: csql (return value)
char * get_select_toc_sql(void)
{
    char *sql1 = "SELECT ";
    char *sql2 = " FROM ";
    char *sql3 = " WHERE ";
    char *sql4 = "=";
    char *sql6 = " , ";

    int length = strlen(sql1) + strlen(FILES_FIELD_NAME_TYPE_NUM) + strlen(sql6)
                 + strlen(FILES_FIELD_NAME_PARAM1)
                 + strlen(sql2) + strlen(FILES_TABLE_NAME)
                 + strlen(sql3)
                 + strlen(FILES_FIELD_NAME_TYPE) + strlen(sql4) + strlen(FILES_FIELD_NAME_TYPE_PARAMETER);
    char* csql;
    csql = (char*)malloc(length + 1);
    strcpy(csql, sql1);
    strcat(csql, FILES_FIELD_NAME_TYPE_NUM);
    strcat(csql, sql6);
    strcat(csql, FILES_FIELD_NAME_PARAM1);
    strcat(csql, sql2);
    strcat(csql, FILES_TABLE_NAME);
    strcat(csql, sql3);
    strcat(csql, FILES_FIELD_NAME_TYPE);
    strcat(csql, sql4);
    strcat(csql, FILES_FIELD_NAME_TYPE_PARAMETER);
    csql[length] = '\0';
    return csql;
}

//nned2free: jsonSerialize (return value)
char * get_product_toc(char * danacode)
{
    char * productPath = get_product_db_path(danacode);
    sqlite3 * db = open_data_base(productPath);
    if (db == NULL)
    {
        free(productPath);
        return "ERROR_CANNOT_CONNECT_TO_DB";
    }
    free(productPath);
    sqlite3_stmt *res;
    char *sql2 = get_select_toc_sql();
    int rc = sqlite3_prepare_v2(db, sql2, -1, &res, 0);
    free(sql2);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res);
        sqlite3_close(db);
        return "3";
    }
    int idx = sqlite3_bind_parameter_index(res, FILES_FIELD_NAME_TYPE_PARAMETER);
    sqlite3_bind_text(res, idx, FILES_TYPE_CHAPTER, strlen(FILES_TYPE_CHAPTER), 0);

    cJSON * json = cJSON_CreateObject();
    int step = sqlite3_step(res);
    int i = 0;
    while (step == SQLITE_ROW) {
        int type_id = sqlite3_column_int(res,0);
        unsigned char * type_name = sqlite3_column_text(res,1);
        cJSON * bookObj = cJSON_CreateObject();
        cJSON_AddNumberToObject(bookObj, "typeID", type_id);
        if (type_name != NULL) {
            cJSON_AddStringToObject(bookObj, "typeName", type_name);
        }

        int bookObjKeyLength = 3;
        if (i > 9)
            bookObjKeyLength = 4;
        else if (i > 99)
            bookObjKeyLength = 5;
        char bookObjKey[bookObjKeyLength];
        sprintf(bookObjKey, "c_%d", i);
        cJSON_AddItemToObject(json,bookObjKey,bookObj);
        step = sqlite3_step(res); //TODO: how to do it right
        i++;
    }
    cJSON_AddNumberToObject(json, "numOfChapters", i);
    sqlite3_finalize(res);
    sqlite3_close(db);

    char * jsonSerialize = cJSON_Print(json);
    cJSON_Delete(json);
    return jsonSerialize;
}

int delete_product(const unsigned char * danacode) //just from products table
{
    char * productsPath = get_products_db_path();

    sqlite3 * db = open_data_base(productsPath);
    if (db == NULL)
    {
        free(productsPath);
        return ERROR_CANNOT_CONNECT_TO_DB;
    }
    free(productsPath);

    sqlite3_stmt *res2;
    char *sql3 =  get_delete_product_sql_by_danacode();
    int rc = sqlite3_prepare_v2(db, sql3, -1, &res2, 0);
    free(sql3);
    if (rc != SQLITE_OK) {
        sqlite3_finalize(res2);
        sqlite3_close(db);
        return (4);
    }
    int idx2 = sqlite3_bind_parameter_index(res2, PRODUCTS_FIELD_NAME_DANACODE_PARAMETER);
    sqlite3_bind_text(res2, idx2, danacode, strlen(danacode), 0);
    sqlite3_step(res2);
    sqlite3_finalize(res2);
    sqlite3_close(db);
    return (0);
}
