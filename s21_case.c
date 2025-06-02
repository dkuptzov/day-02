#include "s21_case.h"

#include <math.h>
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

void case_g(char **str, param *param) {
    char *str_int;
    int count = 0;
    if (param->va_f >= pow(10, 6)) {
        while (param->va_f > 2.0) {
            param->va_f = param->va_f / 1e1;
            count++;
        }
        param->va_f *= pow(10, count - 1);
        param->va_f = round(param->va_f);
        param->va_f -= pow(10, count - 1);
        (*str)[param->count++] = '1';
        (*str)[param->count++] = '.';
        str_int = s21_atoi(param);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = 'e';
        (*str)[param->count++] = '+';
        (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else if (param->va_f < pow(10, -4)) {
        while (param->va_f < 1.0) {
            param->va_f = param->va_f * 1e1;
            count++;
        }
        param->va_f *= pow(10, 5);
        param->va_f = round(param->va_f);
        param->va_f -= pow(10, 5);
        (*str)[param->count++] = '1';
        (*str)[param->count++] = '.';
        str_int = s21_atoi(param);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = 'e';
        (*str)[param->count++] = '-';
        (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else {
        if (param->va_f < 10.0) param->g = 1;
        else if (param->va_f < 100.0) param->g = 2;
        else if (param->va_f < 1000.0) param->g = 3;
        else if (param->va_f < 10000.0) param->g = 4;
        else if (param->va_f < 100000.0) param->g = 5;
        else param->g = 6;
        param->va_f *= pow(10, param->g - 1);
        param->va_f = round(param->va_f);
        str_int = s21_atoi(param);
        for (int j = 0 ; str_int[j] != '\0'; j++ ) {
            if (j == param->g) (*str)[param->count++] = '.';
            (*str)[param->count++] = str_int[j];
        }
    }
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