#include "s21_case.h"

#include <stdio.h>
#include <stdlib.h>

void case_c(char **str, param *param) {
    param->width -= 1;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        (*str)[param->count++] = param->c;
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || param->width > 0) {
        s21_alignment(&str, param);
        (*str)[param->count++] = param->c;
    }
    else (*str)[param->count++] = param->c;
}

void case_u(char **str, param *param) {
    char *str_du = NULL;
    str_du = s21_atoi(param);
    param->width = (param->width > s21_strlen(str_du)) ? param->width - s21_strlen(str_du) : 0;
    if (param->flag == ' ' && str_du[0] != '-') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        for (int j = 0 ; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
        s21_alignment(&str, param);
    }
    else if (param->flag == '0') {
        s21_alignment(&str, param);
    }
    else if (param->flag == '+' || param->width > 0) {
        s21_alignment(&str, param);
        if (param->flag == '+') {
            param->count--;
            (*str)[param->count++] = '+';
        }
    }
    else if (param->accuracy > 0) {
        param->accuracy = (param->accuracy > s21_strlen(str_du)) ? param->accuracy - s21_strlen(str_du) : 0;
        s21_alignment(&str, param);
    }
    else if (param->length == 'h') {
        param->va_int = s21_to_binary(param);
        str_du = s21_atoi(param);
    }
    else if (param->length == 'l') {
        param->va_int = s21_to_binary(param);
        str_du = s21_atoi(param);
    }
    if (param->flag != '-') {
        for (int j = 0 ; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
    }
    free(str_du);
}

void case_f(char **str, param *param) {
    char *str_int, *str_float = NULL;
    str_int = s21_atoi(param);
    for (int j = 0 ; str_int[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_int[j];
    }
    free(str_int);
    str_float = s21_atof(param);
    for (int j = 0 ; str_float[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_float[j];
    }
    free(str_float);
}

void case_s(char **str, char *str_d, param *param) {
    param->width = (param->width > s21_strlen(str_d)) ? param->width - s21_strlen(str_d) : 0;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || param->width > 0)
        s21_alignment(&str, param);
    if (param->flag != '-')
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
}