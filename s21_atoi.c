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
    else if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') {
        //printf("param->accuracy: %d\n", param->accuracy);
        //if (param->flag == '.' || param->acc == '.') {
        if (param->flag == '.') {
            if (param->accuracy > 0) max = param->accuracy;
            else max = param->width;
        }
        else if (param->g != 0) max -= param->g;
        //printf("max2: %d\n", max);
        if ((param->type == 'g' || param->type == 'G') && param->flag != '#') max -= 1;
        //printf("PARAM2: %d\n", max);
        x = s21_atoi_int(str, digit, (long long int)param->va_f, param);
        //printf("STR20: %s\n", str);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        //printf("PARAM: %Lf %d %d\n", param->va_f, count, max);
        while (count < max) {
            y *= pow(10, max);
            y = round(y);
            y /= pow(10, max - 1);
            str[x++] = '0' + ((int)y % 10);
            //printf("STR100: %s\n", str);
            y -= (int)y;
            count++;
        }
        //while (count++ < max) str[x++] = '0';
        //printf("STR10: %s\n", str);
        if (str[--x] == '.') str[x] = '\0';
        else str[++x] = '\0';
        //printf("STR:11 %s\n", str);
    }
    //printf("STR: %s\n", str);
    free(digit);
    return str;
}

int s21_atoi_int(char *str, char *digit, long long int x, param *param) {
    //printf("X: %lld\n", x);
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
    if (x == 0) str[x++] = '0';
    if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') str[x++] = '.';
    //printf("STR1111111: %s\n", str);
    //printf("X: %lld\n", x);
    return x;
}