#include "s21_atoi.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *s21_atoi(param *param) {
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    int count = 0, sign = 0;
    long long int x;
    if (param->length == 'h' || param->type == 'd' || param->type == 'u') x = param->va_int;
    else if (param->type == 'f' || param->type == 'g') x = param->va_f;
    if (x < 0) {
        x *= -1;
        sign = 1;
    }
    while (x > 0) {
        digit[count++] = '0' + (x % 10);
        x /= 10;
    }
    digit[count] = '\0';
    if (sign == 1) str[x++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[x++] = digit[i];
    }
    str[x] = '\0';
    free(digit);
    return str;
}

char *s21_atof(param *param) {
    char *str;
    str = calloc(1024 + 1, sizeof(char));
    int count = 0, max = 6;
    long double x = param->va_f;
    if (x < 0) x *= -1;
    x -= (long long int)x;
    str[count++] = '.';
    if (param->flag == '.' || param->acc == '.') {
        if (param->accuracy > 0) max = param->accuracy;
        else max = param->width;
        x = round(x * pow(10, max)) / pow(10, max);
    }
    else if (param->g != 0) max -= param->g;
    while (count < max + 1) {
        x *= 10.0;
        str[count++] = '0' + ((int)x % 10);
        x -= (int)x;
    }
    //while(str[--count] == '0') str[count] = '\0';
    if (str[--count] == '.') str[count] = '\0';
    else str[++count] = '\0';
    return str;
}

char *s21_atoi_new(param *param) {
    int max = 6, count = 0;
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    int x = 0;
    long double y = 0.0;
    if (param->length == 'h' || param->type == 'd' || param->type == 'u') {
        x = s21_atoi_int(str, digit, param->va_int, param);
        str[x] = '\0';
    }
    else if (param->type == 'f' || param->type == 'g') {
        
        if (param->flag == '.' || param->acc == '.') {
            if (param->accuracy > 0) max = param->accuracy;
            else max = param->width;
        }
        else if (param->g != 0) max -= param->g;
        x = s21_atoi_int(str, digit, (long long int)param->va_f, param);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        while (count < max) {
            long double temp = y - (long long int)y;
            temp *= 10;
            if (count < max - 1) temp = (long long int)temp;
            else temp = round(temp);
            str[x++] = '0' + ((long long int)temp % 10);
            y *= 10;
            y -= (long long int)y;
            count++;
        }
        //while (count++ < max) str[x++] = '0';
        if (str[--x] == '.') str[x] = '\0';
        else str[++x] = '\0';
    }
    //printf("STR: %s\n", str);
    free(digit);
    return str;
}

int s21_atoi_int(char *str, char *digit, long long int x, param *param) {
    int count = 0;
    long long int x_first = x;
    if (x < 0) x *= -1;
    while (x > 0) {
        digit[count++] = '0' + (x % 10);
        x /= 10;
    }
    digit[count] = '\0';
    if (x_first < 0) str[x++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[x++] = digit[i];
    }
    if (param->type == 'f' || param->type == 'g') str[x++] = '.';
    return x;
}