#include "s21_case.h"
#include "s21_sprintf.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *str_format, ...) {
    param param = {0, 0, 0, 0, 0, 0, 'x', 'x', 'x', 'x','\0', 0, 0.0};
    va_list args;
    va_start(args, str_format);
    char *str_d, *str_sing, *str_ready;
    str_sing = calloc(1024 + 1, sizeof(char));
    str_ready = calloc(1024 + 1, sizeof(char));
    for (int i = 0; str_format[i] != '\0' && param.error == 0; i++) {
        param.count_sign = 0;
        if (str_format[i] == '%') {
            param.flag = 'x';
            param.acc = 'x';
            param.width = 0;
            param.accuracy = 0;
            param.length = 'x';
            i++;
            //flag
            if (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || str_format[i] == ' ' || str_format[i] == '.')
                param.flag = str_format[i++];
            if (str_format[i] == '+' || str_format[i] == '-') i++;
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
                param.acc = '.';
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
            param.type = str_format[i];
            //printf("CASE: %c\n", str_format[i]);
            switch (str_format[i]) {
                case 'c':
                    param.c = va_arg(args, int);
                    case_c(&str_ready, &param);
                    //str[param.count++] = va_arg(args, int);
                    break;
                case 'd':
                    if (param.length == 'l') {
                        long int temp = va_arg(args, long int);
                        param.va_int = (long long int)temp;
                    }
                    else {
                        int temp = va_arg(args, int);
                        param.va_int = (long long int)temp;
                    }
                    case_u(&str_ready, &param);
                    break;
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    double temp = va_arg(args, double);
                    param.va_f = (long double)temp;
                    case_g(&str_ready, &param);
                    break;
                case 'u':
                    param.va_int = va_arg(args, long long int);
                    case_u(&str_ready, &param);
                    break;
                case 'f':
                    if (param.length == 'L')
                        param.va_f = va_arg(args, long double);
                    else {
                        double temp = va_arg(args, double);
                        param.va_f = (long double)temp;
                    }
                    case_f(&str_ready, &param);
                    break;
                case 's':
                    str_d = va_arg(args, char*);
                    case_s(&str_ready, str_d, &param);
                    //for (int j = 0 ; str_d[j] != '\0'; j++ )
                    //    str[param.count++] = str_d[j];
                    break;
                case 'x':
                case 'X':
                    int temp_x = va_arg(args, int);
                    param.va_int = (long long int)temp_x;
                    if (param.va_int >= 0) case_x_plus(&str_ready, &param);
                    else case_x_minus(&str_ready, &param);
                    break;
                case 'o':
                    int temp_o = va_arg(args, int);
                    param.va_int = (long long int)temp_o;
                    if (param.va_int >= 0) case_o_plus(&str_ready, &param);
                    else case_o_minus(&str_ready, &param);
                    break;
                default:
                    param.error = 1;
                    break;
            }
        }
        else {
            str_ready[param.count++] = str_format[i];
        }
    }
    str_ready[param.count] = '\0';
    printf("STR_END: %s\n", str_ready);
    if (param.error == 0)
    for (int i = 0; str_format[i] != '\0'; i++)
        str[i] = str_ready[i];
    return param.count;
}

int s21_strlen(char *str_du) {
    int i = 0;
    for (; str_du[i] != '\0'; i++);
    return i;
}

void s21_alignment(char ***str, param *param) {
    if (param->flag == '-' || param->flag == '+' || (param->flag != '0' && param->flag != '.'))
        for (int i = 0; i < param->width; i++)
            (**str)[param->count++] = ' ';
    if (param->flag == '0' || param->flag == '.' || param->accuracy > 0)
        for (int i = 0; i < param->width; i++)
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