#include "sprintf.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *str_format, ...) {
    param param = {0, 0, 0, 0, 'x', 'x'};
    va_list args;
    va_start(args, str_format);
    char *str_d, *str_sing;
    str_sing = calloc(1024 + 1, sizeof(char));
    for (int i = 0; str_format[i] != '\0'; i++) {
        param.count_sign = 0;
        if (str_format[i] == '%') {
            param.flag = 'x';
            param.width = 0;
            param.accuracy = 0;
            param.length = 'x';
            i++;
            //flag
            if (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || str_format[i] == ' ')
                param.flag = str_format[i++];
            //flag
            //wigth
            while (str_format[i] >= '0' && str_format[i] <= '9') {
                str_sing[param.count_sign++] = str_format[i++];
            }
            str_sing[param.count_sign] = '\0';
            param.width = s21_str_to_number(str_sing);
            str_sing[0] = '\0';
            param.count_sign = 0;
            //wigth
            //accuracy
            if (str_format[i] == '.') {
                i++;
                while (str_format[i] >= '0' && str_format[i] <= '9')
                    str_sing[param.count_sign++] = str_format[i++];
                str_sing[param.count_sign] = '\0';
                param.accuracy = s21_str_to_number(str_sing);
            }
            //accuracy
            //length
            if (str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L')
                param.length = str_format[i++];
            //length
            switch (str_format[i]) {
                case 'c':
                    str[param.count++] = va_arg(args, int);
                    break;
                case 'd':
                case 'u':
                    case_u(va_arg(args, long long int), &str, &param);
                    break;
                case 'f':
                    case_f(va_arg(args, double), &str, &param);
                    break;
                case 's':
                    str_d = va_arg(args, char*);
                    for (int j = 0 ; str_d[j] != '\0'; j++ )
                        str[param.count++] = str_d[j];
                    break;
                default:
                    break;
            }
        }
        else {
            str[param.count++] = str_format[i];
        }
    }
    str[param.count] = '\0';
    printf("STR_END: %s\n", str);
    return 0;
}

char *s21_atoi(long long int x) {
    char *digit, *str;
    digit = calloc(1024 + 1, sizeof(char));
    str = calloc(1024 + 1, sizeof(char));
    int count = 0, sign = 0;
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

char *s21_atof(double x) {
    char *str;
    str = calloc(1024 + 1, sizeof(char));
    int count = 0;
    x -= (int)x;
    str[count++] = '.';
    while (count < 7) {
        x *= 10.0;
        str[count++] = '0' + ((int)x % 10);
        x -= (int)x;
    }
    str[count] = '\0';
    return str;
}

void case_u(long long int va, char **str, param *param) {
    char *str_du = NULL;
    str_du = s21_atoi(va);
    param->width = (param->width > s21_strlen(str_du)) ? param->width - s21_strlen(str_du) : 0;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
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
        int len_h = s21_to_binary(va);
        str_du = s21_atoi(len_h);
    }
    if (param->flag != '-') {
        for (int j = 0 ; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
    }
    free(str_du);
}

int s21_strlen(char *str_du) {
    int i = 0;
    for (; str_du[i] != '\0'; i++);
    return i;
}

void case_f(double va, char **str, param *param) {
    char *str_f = NULL;
    str_f = s21_atoi(va);
    for (int j = 0 ; str_f[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_f[j];
    }
    str_f = NULL;
    str_f = s21_atof(va);
    for (int j = 0 ; str_f[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_f[j];
    }
    free(str_f);
}

void s21_alignment(char ***str, param *param) {
    if (param->flag == '-' || param->flag == '+' || (param->flag > 0 && param->flag != '0'))
        for (int i = 0; i < param->width; i++)
            (**str)[param->count++] = ' ';
    if (param->flag == '0')
        for (int i = 0; i < param->width; i++)
            (**str)[param->count++] = '0';
    if (param->accuracy > 0 || param->flag == '0')
        for (int i = 0; i < param->accuracy; i++)
            (**str)[param->count++] = '0';
}

int s21_str_to_number(char *str_sing) {
    int number = 0, multiplier = 1;
    for (int i = 0; str_sing[i] != '\0'; i++) {
        number *= multiplier;
        switch (str_sing[i]) {
            case '0':
                break;
            case '1':
                number += 1;
                break;
            case '2':
                number += 2;
                break;
            case '3':
                number += 3;
                break;
            case '4':
                number += 4;
                break;
            case '5':
                number += 5;
                break;
            case '6':
                number += 6;
                break;
            case '7':
                number += 7;
                break;
            case '8':
                number += 8;
                break;
            case '9':
                number += 9;
                break;
            default:
                break;
        }
        multiplier = 10;
    }
    return number;
}

int s21_to_binary(long long int x) {
    char *binary_str_revers, *binary_str;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    int count = 0, count_revers = 0;
    while (x > 0) {
        binary_str_revers[count_revers++] = (x % 2 == 0) ? '0' : '1';
        x /= 2;
    }
    for (int i = count_revers - 1; i >= 0; i--)
        binary_str[count++] = binary_str_revers[i];
    int multi = 0, result = 0, h = 1, plus = 0;
    //printf("BIN: %s\n", binary_str);
    if (h) {
        for (int i = count - 1; i >= count - 16; i--) {
            if (binary_str[i] == '1' && i == count - 1) {
                result += (pow(2, multi));
            }
            else if (binary_str[i] == '0' && i == count - 1) {
                plus = 1;
            }
            else if (binary_str[i] == '1' && plus == 1) {
                result += (pow(2, multi));
                plus = 0;
            }
            else if (plus == 1)
                break;
            else if (binary_str[i] == '0') result += (pow(2, multi));
            multi++;
        }
    }
    if (binary_str[count - 16] == '1') result *= -1;
    return result;
}