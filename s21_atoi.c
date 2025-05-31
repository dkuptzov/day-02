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
    if (param->length == 'h') x = param->va_int;
    else if (param->type == 'd') x = param->va_int;
    else if (param->type == 'u') x = param->va_int;
    else if (param->type == 'f') x = param->va_f;
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
    int count = 0, max = 7;
    long double x = param->va_f;
    x -= (long long int)x;
    str[count++] = '.';
    if (param->flag == '.') {
        max = param->width + 1;
        x = round(x * pow(10, param->width)) / pow(10, param->width);
    }
    while (count < max) {
        x *= 10.0;
        str[count++] = '0' + ((int)x % 10);
        x -= (int)x;
    }
    str[count] = '\0';
    return str;
}