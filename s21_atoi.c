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
    if (param->flag_dot == 1 || param->acc == '.') {
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
    int max = 6, max2 = 20, count = 0;
    //printf("PARAM: %Lf\n", param->va_f);
    //if (param->va_f == 0 && param->flag == '.') max = 0;
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    //str2 = calloc(1024 + 1, sizeof(char));
    long long int x = 0;
    long double y = 0.0;
    if (param->length == 'h' || param->type == 'd' || param->type == 'u') {
        x = s21_atoi_int(str, digit, param->va_int, param);
        str[x] = '\0';
    }
    else if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') {
        /*
        if (param->type == 'g' || param->type == 'G') {
            if (param->va_f < 1) max = 6;
            else if (param->va_f < 10) max = 5;
            else if (param->va_f < 100) max = 4;
            else if (param->va_f < 1000) max = 3;
            else if (param->va_f < 10000) max = 2;
            else if (param->va_f < 100000) max = 1;
            else if (param->va_f < 1000000) max = 0;
        }*/
        //printf("param->accuracy: %d %d\n", param->accuracy, param->width);
        //if (param->flag == '.' || param->acc == '.') {
        //printf("param->flag: %c\n", param->flag);
        //if (param->accuracy == 0 && param->width == 0 && param->type == 'g') max = 1;
        printf("max1: %d %d %d %d %Lf\n", max, param->g, param->accuracy, param->width, param->va_f);
        if (param->flag_dot == 1) {
            if (param->accuracy <= 0 && param->width <= 0 && param->type == 'g') max = 1;
            else if (param->accuracy > 0) max = param->accuracy;
            else max = param->width;
        }
        else if (param->g != 0) max -= param->g;
        if (max == 1 && param->va_f < 1 && param->type == 'g') {
            long double z = param->va_f;
            z *= 10;
            while (z < 1) {
                z *= 10;
                max++;
            }
        }
        printf("max2: %d %d %d\n", max, param->accuracy, param->width);
        //
        //if ((param->type == 'g' || param->type == 'G') && param->flag != '#') max -= 1;
        //
        //printf("PARAM2: %d\n", max);
        //printf("STR100: %s\n", str);
        //////////////////////////////////////////TEST
        //x = s21_atoi_int(str, digit, (long long int)param->va_f, param);
        x = s21_atoi_int(str, digit, param->va_f, param);
        //printf("ATOI_X: %lld\n", x);
        //printf("STR: %s ** %s\n", str, digit);
        //int a;
        //scanf("%d", &a);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        printf("PARAM: %Lf\n", param->va_f);
        //if ((param->type == 'e' || param->type == 'E') && y >= 10) y /= 10;
        //printf("ATOI_Y: %Lf\n", y);
        //printf("PARAM: %Lf %d %d\n", param->va_f, count, max);
        //printf("ATOI_Y1: %Lf\n", y);
        y -= (long long int)y;
        //printf("ATOI_Y2: %Lf\n", y);
        //printf("STR10: %s\n", str);
        //max -= x;
        //printf("MAX_FINAL: %d\n", max);
        //long long int z = 0;
        //
        if (param->flag_dot == 1 && param->accuracy >= 0) max2 = param->accuracy;
        else max2 = max;
        while (count < max) {
        //printf("ATOI_TUT2\n");
            int test = 0;
            y -= (long long int)y;
            while (test++ < max2 - count) {
                y *= 10;
            }
            printf("Y0: %Lf\n", y);
            if (param->type == 'e' || param->type == 'E') {
                if (param->flag_dot != 1 || count == max - 1) y = round(y);
                else if (param->flag_dot != 1) y = round(y);
            }
            else if (param->type == 'f' || param->type == 'g' || param->type == 'G') y = round(y);
            //if (param->accuracy <= 0 || count - 1 == param->accuracy) y = round(y);
            printf("Y1: %Lf\n", y);
            //y = round(y);
            //kkk = round(kkk);
            //printf("Y2: %Lf\n", kkk);
            y /= pow(10, max2 - count - 1);
            printf("Y2: %Lf\n", y);
            //if (count == max - 1) y = round(y);
            //printf("Y3: %Lf\n", y);
            //if (count - 1 == param->accuracy) y = round(y);
            str[x++] = '0' + ((int)y % 10);
            printf("STR: %s\n", str);
            y -= (long long int)y;
            printf("Y3: %Lf\n", y);
            /*
            //printf("ATOI_Y1: %Lf\n", y);
            y = round(y);
            //printf("ATOI_Y2: %Lf\n", y);
            y /= pow(10, max - count - 1);
            //printf("ATOI_Y3: %Lf\n", y);
            if (count == max - 1) z = round(y);
            else z = (long long int)y;
            //printf("ATOI_Z: %lld\n", z);
            str[x++] = '0' + (z % 10);
            //printf("STR: %s\n", str);
            y -= (long long int)y;
            //printf("ATOI_Y4: %Lf\n", y);
            */
            count++;
        }
        //printf("STR2: %s\n", str2);
        //for (int i = 0; i < max; i++) str[x++] = str2[i];

        //
        /*
        if (param->its_float == 0 && param->length == 'L') {
            //
            y -= (long long int)y;
            //
            while (count < max) {
                y *= 10;
                printf("HEX1: %Lf\n", y);
                if (round(y) < 10 && count == max - 1 && param->type != 'e' && param->type != 'E') {
                    z = round(y);
                    str[x++] = '0' + (z % 10);
                    //printf("HEX1: %Lf\n", y);
                }
                else if (round(y) >= 10 && param->type != 'e' && param->type != 'E') str[x++] = '0';
                else if (round(y) >= 10 ) str[x++] = '9';
                else {
                    z = (param->type != 'e' && param->type != 'E') ? (long long int)(y + 0.000001) : (long long int)y;
                    z = (z == 0) ? (long long int)(y + 0.000001) : z;
                    //printf("Z: %lld\n", z);
                    str[x++] = '0' + (z % 10);
                    //printf("HEX2: %Lf\n", y);
                    //printf("STR0: %s\n", str);
                }
                //if (count == max - 1) z = round(y);
                //else z = (long long int)y;
                //str[x++] = '0' + (z % 10);
                y -= (long long int)y;
                count++;
            }
        }
        else {
            y -= (long long int)y;
            while (count < max) {
                //printf("ATOI_TUT2\n");
                int test = count;
                while (test++ < max) y *= 10;
                //printf("ATOI_Y1: %Lf\n", y);
                y = round(y);
                //printf("ATOI_Y2: %Lf\n", y);
                y /= pow(10, max - count - 1);
                //printf("ATOI_Y3: %Lf\n", y);
                if (count == max - 1) z = round(y);
                else z = (long long int)y;
                //printf("ATOI_Z: %lld\n", z);
                str[x++] = '0' + (z % 10);
                //printf("STR: %s\n", str);
                y -= (long long int)y;
                //printf("ATOI_Y4: %Lf\n", y);
                count++;
            }
        }
        */

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

int s21_atoi_int(char *str, char *digit, long double x, param *param) {
    //printf("X: %lld\n", x);
    int count = 0;
    long long int x_first = x;
    //long long int z;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    //if ((param->type == 'g' || param->type == 'e') && param->accuracy == 0) z = round(x);
    //z = (long long int)x;
    //printf("Z: %Lf\n", x);
    long long int z;
    if (x > 0) z = (long long int)(x + 0.000001);
    else z = (long long int)(x - 0.000001);

    //long long int z = (long long int)x;
    //printf("Z: %lld\n", z);
    //printf("STR000: %s\n", str);
    if (z < 0) z *= -1;
    while (z > 0) {
        digit[count++] = '0' + (z % 10);
        z /= 10;
    }
    //printf("X2: %lld\n", z);
    digit[count] = '\0';
    //printf("digit: %s\n", digit);
    if (x_first < 0) str[z++] = '-';
    for (int i = count - 1; i >= 0; i--) {
        str[z++] = digit[i];    
    }
    //printf("str: %s\n", str);
    //printf("X3: %lld\n", z);
    if (z == 0) str[z++] = '0';
    if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') str[z++] = '.';
    //printf("STR000: %s\n", str);
    //printf("X4: %lld\n", z);
    return z;
}


/*
char *s21_atoi_new(param *param) {
    int max = 6, count = 0;
    //printf("PARAM: %Lf\n", param->va_f);
    //if (param->va_f == 0 && param->flag == '.') max = 0;
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    long long int x = 0;
    long double y = 0.0;
    if (param->length == 'h' || param->type == 'd' || param->type == 'u') {
        x = s21_atoi_int(str, digit, param->va_int, param);
        str[x] = '\0';
    }
    else if (param->type == 'f' || param->type == 'g' || param->type == 'G' || param->type == 'e' || param->type == 'E') {
        if (param->type == 'g' && param->va_f >= pow(10, 6)) max = 5;
        //printf("param->accuracy: %d %d\n", param->accuracy, param->width);
        //if (param->flag == '.' || param->acc == '.') {
        //printf("param->flag: %c\n", param->flag);
        if (param->accuracy == 0 && param->width == 0 && param->type == 'g') max = 1;
        printf("max1: %d %d %d\n", max, param->accuracy, param->width);
        if (param->flag == '.' || param->flag2 == '.') {
            if (param->accuracy > 0) max = param->accuracy;
            else max = param->width;
        }
        else if (param->g != 0) max -= param->g;
        printf("max2: %d %d %d\n", max, param->accuracy, param->width);
        //
        //if ((param->type == 'g' || param->type == 'G') && param->flag != '#') max -= 1;
        //
        //printf("PARAM2: %d\n", max);
        //printf("STR100: %s\n", str);
        //////////////////////////////////////////TEST
        //x = s21_atoi_int(str, digit, (long long int)param->va_f, param);
        x = s21_atoi_int(str, digit, param->va_f, param);
        printf("ATOI_X: %lld\n", x);
        //printf("STR: %s\n", str);
        //int a;
        //scanf("%d", &a);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        //if ((param->type == 'e' || param->type == 'E') && y >= 10) y /= 10;
        //printf("ATOI_Y: %Lf\n", y);
        //printf("PARAM: %Lf %d %d\n", param->va_f, count, max);
        //printf("ATOI_Y1: %Lf\n", y);
        y -= (long long int)y;
        //printf("ATOI_Y2: %Lf\n", y);
        //printf("STR10: %s\n", str);
        if (param->type == 'g' && param->va_f < 1.0) {
            long double z = param->va_f;
            while (z < 1) {
                max++;
                z *= 10;
            }
        }
        printf("max3: %d %d %d\n", max, param->accuracy, param->width);
        long long int z = 0;
        if (param->its_float == 0 && param->length == 'L') {
            while (count < max) {
                printf("ATOI_TUT1\n");
                y *= pow(10, max);
                //%.17Le %.17LE
                printf("ATOI_Y1: %Lf\n", y);
                if (param->type != 'e' && param->type != 'E') y = round(y);
                printf("ATOI_Y2: %Lf\n", y);
                y /= pow(10, max - 1);
                printf("ATOI_Y3: %Lf\n", y);
                if (count == max - 1) z = round(y);
                else z = (long long int)y;
                printf("ATOI_Z: %lld\n", z);
                str[x++] = '0' + (z % 10);
                printf("STR!!!: %s\n", str);
                y -= (long long int)y;
                count++;
            }
        }
        else {
            while (count < max) {
                printf("ATOI_TUT2\n");
                int test = count;
                while (test++ < max) y *= 10;
                //printf("ATOI_Y1: %Lf\n", y);
                y = round(y);
                //printf("ATOI_Y2: %Lf\n", y);
                y /= pow(10, max - count - 1);
                //printf("ATOI_Y3: %Lf\n", y);
                if (count == max -1) z = round(y);
                else z = (long long int)y;
                str[x++] = '0' + (z % 10);
                printf("STR: %s\n", str);
                y -= (long long int)y;
                //printf("ATOI_Y4: %Lf\n", y);
                count++;
            }
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
*/