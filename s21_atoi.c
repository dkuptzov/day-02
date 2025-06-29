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
            else if (param->type == 'f' && param->va_f == 0.0 && param->flag_space == 0 && param->length == 'x') max = 1;
            else if (param->accuracy >= 0) max = param->accuracy;
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
        //y -= (long long int)y;
        //printf("Y1: %Lf\n", y);
        if (param->flag_dot == 1 && param->accuracy > 0) max2 = param->accuracy;
        else max2 = max;
        while (count < max) {
            int test = 0;
            y -= (long long int)y;
            printf("Y2: %Lf %d %d %d\n", y, test, max2, count);
            while (test++ < max2 - count) y *= 10;
            printf("Y3: %Lf\n", y);
            if (param->type == 'e' || param->type == 'E') {
                if (param->flag_dot != 1 || count == max - 1) y = round(y);
                else if (param->flag_dot != 1) y = round(y);
            }
            else if (param->type == 'f' || param->type == 'g' || param->type == 'G') y = round(y);
            printf("Y4: %Lf\n", y);
            y /= pow(10, max2 - count - 1);
            printf("Y5: %Lf\n", y);
            str[x++] = '0' + ((int)y % 10);
            printf("STR: %s\n", str);
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
    int lg = log10l(x);
    int count = 0, count_reverse = 0, max_lg = lg / 2;
    long double temp = 0.0;
    char digit_reverse[100] = {0};
    while (x > 9000000000000000000.0) {
        //printf("LG: %d\n", lg);
        while (lg - max_lg > 0) {
            long double x_temp = x;
            x_temp /= pow(10, lg);
            //printf("X_TEMP: %lld\n", (long long int)x_temp);
            digit_reverse[count_reverse++] = '0' + (((long long int)x_temp) % 10);
            //printf("STR: %s\n", digit_reverse);
            temp = (long long int)x_temp;
            //printf("TEMp: %Lf\n", temp);
            lg--;
        }
        x -= (temp * pow(10, lg + 1));
        lg = log10l(x);
        max_lg = lg / 2;
        //printf("X: %Lf\n", x);
        param->va_f = x;
    }
    digit_reverse[count_reverse] = '\0';
    //printf("STR: %s\n", digit_reverse);
    long long int x_first = x;
    long long int z;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    if (x > 0) z = (long long int)(x + 0.000001);
    else if (param->accuracy == 0) z = round(x);
    else z = (long long int)(x - 0.000001);
    if (z < 0) z *= -1;
    printf("Z: %Lf * %lld\n", x, z);
    while (z > 0) {
        digit[count++] = '0' + (z % 10);
        z /= 10;
        printf("digit: %s\n", digit);
    }
    for (int i = count_reverse - 1; i >= 0; i--) {
        digit[count++] = digit_reverse[i];
    }
    digit[count] = '\0';
    printf("x_first: %lld * %s\n", x_first, digit);
    //if (x_first < 0) str[z++] = '-';
    if (x < 0) str[z++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[z++] = digit[i];    
    }
    if (x_first == 0) str[z++] = '0';
    if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') str[z++] = '.';
    printf("str000: %s\n", str);
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