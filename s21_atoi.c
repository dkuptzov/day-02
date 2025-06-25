#include "s21_atoi.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *s21_atoi_new(param *param) {
    //max && max2 это точность для чисел
    int max = 6, max2 = 20, count = 0;
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    long long int x = 0;
    long double y = 0.0;
    printf("PAR1: %Lf\n", param->va_f);
    if (param->length == 'h' || param->type == 'd' || param->type == 'u') {
        if (param->type == 'u') x = s21_atoi_int_u(str, digit, (unsigned long long)param->va_int, param);
        else x = s21_atoi_int(str, digit, param->va_int, param);
        str[x] = '\0';
    }
    else if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') {
        printf("PAR2: %Lf\n", param->va_f);
        if (param->flag_dot == 1) {
            printf("PAR21: %Lf\n", param->va_f);
            if (param->accuracy <= 0 && param->width <= 0 && param->type == 'g') max = 1;
            else if (param->accuracy > 0) max = param->accuracy;
            else max = param->width;
        }
        else if (param->g != 0) max -= param->g;
        if (max == 1 && param->va_f < 1 && param->type == 'g') {
            printf("PAR22: %Lf\n", param->va_f);
            long double z = param->va_f;
            z *= 10;
            while (z < 1) {
                z *= 10;
                max++;
            }
        }
        printf("PAR3: %Lf\n", param->va_f);
        x = s21_atoi_int(str, digit, param->va_f, param);
        printf("PAR4: %Lf\n", param->va_f);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        y -= (long long int)y;
        if (param->flag_dot == 1 && param->accuracy >= 0) max2 = param->accuracy;
        else max2 = max;
        while (count < max) {
            int test = 0;
            y -= (long long int)y;
            while (test++ < max2 - count) y *= 10;
            if (param->type == 'e' || param->type == 'E') {
                if (param->flag_dot != 1 || count == max - 1) y = round(y);
                else if (param->flag_dot != 1) y = round(y);
            }
            else if (param->type == 'f' || param->type == 'g' || param->type == 'G') y = round(y);
            y /= pow(10, max2 - count - 1);
            str[x++] = '0' + ((int)y % 10);
            y -= (long long int)y;
            count++;
        }
        if (str[--x] == '.') str[x] = '\0';
        else str[++x] = '\0';
    }
    free(digit);
    return str;
}

int s21_atoi_int(char *str, char *digit, long double x, param *param) {
    int count = 0;
    long long int x_first = x;
    long long int z;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    if (x > 0) z = (long long int)(x + 0.000001);
    else z = (long long int)(x - 0.000001);
    if (z < 0) z *= -1;
    printf("Z: %Lf * %lld\n", x, z);
    while (z > 0) {
        digit[count++] = '0' + (z % 10);
        z /= 10;
    }
    digit[count] = '\0';
    if (x_first < 0) str[z++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[z++] = digit[i];    
    }
    if (z == 0) str[z++] = '0';
    if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') str[z++] = '.';
    return z;
}
/*
int s21_atoi_float(char *str, char *digit, long double x, param *param) {
    int count = 0;
    long double x_first = x;
    long double z;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    if (x > 0) z = x + 0.000001;
    else z = x - 0.000001;
    if (z < 0) z *= -1;
    printf("Z: %Lf * %lld\n", x, z);
    while (z > 0) {
        digit[count++] = '0' + (z % 10);
        z /= 10;
    }
    digit[count] = '\0';
    if (x_first < 0) str[z++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[z++] = digit[i];    
    }
    if (z == 0) str[z++] = '0';
    if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') str[z++] = '.';
    return z;
}
*/
int s21_atoi_int_u(char *str, char *digit, unsigned long long x, param *param) {
    int count = 0;
    unsigned long long z = x;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    while (z > 0) {
        digit[count++] = '0' + (z % 10);
        z /= 10;
    }
    digit[count] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        str[z++] = digit[i];    
    }
    if (z == 0) str[z++] = '0';
    return z;
}