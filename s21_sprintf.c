#include "s21_case.h"
#include "s21_sprintf.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *str_format, ...) {
    param param = {0, 0, 0, 0, 'x', 'x', 'x', '\0', 0, 0.0};
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
            if (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || str_format[i] == ' ' || str_format[i] == '.')
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
            param.type = str_format[i];
            switch (str_format[i]) {
                case 'c':
                    param.c = va_arg(args, int);
                    case_c(&str, &param);
                    //str[param.count++] = va_arg(args, int);
                    break;
                case 'd':
                    if (param.length == 'l') {
                        long int temp = va_arg(args, long int);
                        param.va_int = (long long int)temp;
                    }
                    else if (param.length == 'L')
                        param.va_int = va_arg(args, long long int);
                    else {
                        int temp = va_arg(args, int);
                        param.va_int = (long long int)temp;
                    }
                    case_u(&str, &param);
                    break;
                case 'u':
                    param.va_int = va_arg(args, long long int);
                    case_u(&str, &param);
                    break;
                case 'f':
                    param.va_f = va_arg(args, double);
                    case_f(&str, &param);
                    break;
                case 's':
                    str_d = va_arg(args, char*);
                    case_s(&str, str_d, &param);
                    //for (int j = 0 ; str_d[j] != '\0'; j++ )
                    //    str[param.count++] = str_d[j];
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