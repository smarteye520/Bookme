//
// Created by Moish on 06/09/2017.
//

#include "request.h"
#include <string.h>
#include <stdlib.h>
#include "libnhr.h"
#include "const.h"


nhr_request _request  = NULL;
int nhr_is_error = 0;
nhr_bool nhr_is_working = 0;
unsigned char * _request_body;
int is_download_book_now_boolean = 0;

void test_get_on_error(nhr_request request, nhr_error_code error_code) {
    nhr_is_error = error_code;
    nhr_is_working = nhr_false;
    is_download_book_now_boolean = 0;
}

void test_get_on_response(nhr_request request, nhr_response responce) {

    _request = NULL;
    _request_body = nhr_response_get_body(responce);
    unsigned int body_len = nhr_response_get_body_length(responce);

    nhr_is_error = 1;

    if (nhr_response_get_status_code(responce) != 200) {
        nhr_is_error = 15;
        nhr_is_working = nhr_false;
        is_download_book_now_boolean = 0;
        return;
    }

    if (_request_body && body_len) {
        nhr_is_error = 12;
        char *tmp = malloc(body_len);
        memcpy(tmp, _request_body, body_len);
        _request_body = tmp;
        nhr_is_working = nhr_false;
        is_download_book_now_boolean = 0;
    } else {
        nhr_is_error = 5;
    }

}

unsigned char * get_book_from_server(const char * danacode, const char * user, const char * n, const char * e, int * status) {

    if (is_download_book_now_boolean == 1) {
        *status = WHnSO;
        return "";
    }
    else {
        is_download_book_now_boolean = 1;
        *status = WcPls;
    }

    _request = nhr_request_create();
    char * path2 = "/";
    char * path3 = malloc(strlen(GET_BOOK_PATH) + strlen(danacode) + strlen(path2) + strlen(user));
    strcpy(path3, GET_BOOK_PATH);
    strcat(path3, danacode);
    strcat(path3, path2);
    strcat(path3, user);

    nhr_request_set_url(_request, GET_BOOK_PATH_PROTOCOL, GET_BOOK_PATH_DOMAIN, path3, 80);
    nhr_request_set_method(_request, nhr_method_POST);
    //nhr_request_set_timeout(_request, 10000);
    nhr_request_add_header_field(_request, "Cache-control", "no-cache");
    nhr_request_add_header_field(_request, "Accept-Charset", "utf-8");
    nhr_request_add_header_field(_request, "Accept", "application/json");
    nhr_request_add_parameter(_request, "n", n);
    nhr_request_add_parameter(_request, "e", e);
    nhr_request_set_on_recvd_responce(_request, &test_get_on_response);
    nhr_request_set_on_error(_request, &test_get_on_error);
    nhr_is_working = nhr_request_send(_request);

    if (nhr_is_working)
        nhr_is_error = 0;
    else
        nhr_is_error = 4;

    while (nhr_is_working) {
        nhr_thread_sleep(20);
    }

    free(path3);

    if (nhr_is_error == 12) {
        *status = umElA;
    }
    else {
        *status = LcnX5;
    }

    return _request_body;
}
