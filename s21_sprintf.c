#include "s21_case.h"
#include "s21_sprintf.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *str_format, ...) {
    param param = {0, 0, 0, 0, 0, 0, 'x', 'x', 'x', 0, 0.01, 0, 0, 0, 0, 0, 0, 0};
    va_list args;
    va_start(args, str_format);
    char *str_d, *str_sing, *str_ready;
    str_sing = calloc(10024 + 1, sizeof(char));
    str_ready = calloc(10024 + 1, sizeof(char));
    for (int i = 0; str_format[i] != '\0' && param.error == 0; i++) {
        if (str_format[i] == '%') {
            s21_update_param(&param);
            i++;
            while (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || 
                str_format[i] == ' ' || str_format[i] == '.' || str_format[i] == '#' ||
                str_format[i] == '*' || (str_format[i] >= '0' && str_format[i] <= '9') ||
                str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L') {
                int next_с = 0;
                if (str_format[i] == '+') param.flag_plus = 1;
                else if (str_format[i] == ' ') param.flag_space = 1;
                else if (str_format[i] == '-') param.flag_minus = 1;
                else if (str_format[i] == '#') param.flag_hash = 1;
                else if (str_format[i] == '.') param.flag_dot = 1;
                else if (str_format[i] == '0' && str_format[i - 1] != '.') param.flag_zero = 1;
                else if (str_format[i] == '*' && param.flag_dot == 1) param.accuracy = va_arg(args, int);
                else if (str_format[i] == '*') param.width = va_arg(args, int);
                //точность
                else if (str_format[i] >= '0' && str_format[i] <= '9' && param.flag_dot == 1) {
                    while (str_format[i] >= '0' && str_format[i] <= '9')
                        str_sing[param.count_sign++] = str_format[i++];
                    str_sing[param.count_sign] = '\0';
                    param.accuracy = s21_str_to_number(str_sing);
                    next_с = 1;
                }
                //ширина
                else if (str_format[i] >= '0' && str_format[i] <= '9') {
                    while (str_format[i] >= '0' && str_format[i] <= '9')
                        str_sing[param.count_sign++] = str_format[i++];
                    str_sing[param.count_sign] = '\0';
                    param.width = s21_str_to_number(str_sing);
                    next_с = 1;
                }
                //длина
                else if (str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L')
                    param.length = str_format[i];
                //если была запись ширины или точности
                if (param.count_sign > 0) {
                    free(str_sing);
                    str_sing = calloc(1024 + 1, sizeof(char));
                    param.count_sign = 0;
                }
                //если была запись ширины или точности, то там уже был сдвиг, 
                //иначе переходим на следующий символ
                if (next_с == 0) i++;
            }
            //сохраняем спецификатор
            param.type = str_format[i];
            /*
            va_list copy_args;
            va_copy(copy_args, args);
            s21_switch(str_format[i], str_ready, copy_args, &param);
            va_end(copy_args);
            va_arg(args, int);
            */
            switch (str_format[i]) {
                case 'c':
                    param.c = va_arg(args, int);
                    case_c(&str_ready, &param);
                    break;
                case 'd':
                    param.va_int = type(va_arg(args, long long int), &param);
                    if (param.va_int == LLONG_MIN) printf("param.va_int0: %lld\n", param.va_int);
                    printf("param.va_int1: %lld\n", param.va_int);
                    case_u(&str_ready, &param);
                    break;
                case 'e':
                case 'E':
                case 'g':
                case 'G':
                    if (param.length == 'L') param.va_f = va_arg(args, long double);
                    else {
                        long double temp = va_arg(args, double);
                        param.va_f = (long double)temp;
                    }
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
                    //printf("long double: %Lf\n", param.va_f);
                    case_f(&str_ready, &param);
                    break;
                case 's':
                    str_d = va_arg(args, char*);
                    case_s(&str_ready, str_d, &param);
                    break;
                case 'x':
                case 'X':
                    if (param.length == 'l') param.va_int = va_arg(args, long int);
                    else { 
                        int temp_x = va_arg(args, int);
                        param.va_int = (long long int)temp_x;
                    }
                    if (param.va_int == -2147483648) param.va_int *= -1;
                    if (param.va_int >= 0) case_x_plus(&str_ready, &param);
                    else case_x_minus(&str_ready, &param);
                    break;
                case 'o':
                    if (param.length == 'l') param.va_int = va_arg(args, long int);
                    else if (param.length == 'h'){ 
                        long long int temp_o = va_arg(args, long long int);
                        param.va_int = (long long int)temp_o;
                        param.va_int = type(param.va_int, &param);
                    }
                    else {
                        long long int temp_o = va_arg(args, long long int);
                        param.va_int = (long long int)temp_o;
                    }
                    if (param.flag_hash == 1) str_ready[param.count++] = '0';
                    if (param.va_int >= 0) case_o_plus(&str_ready, &param);
                    else case_o_minus(&str_ready, &param);
                    break;
                case 'p':
                    case_p(&str_ready, va_arg(args, char*), &param);
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
    va_end(args);
    str_ready[param.count] = '\0';
    if (param.error == 0)
        for (int i = 0; str_ready[i] != '\0'; i++)
            str[i] = str_ready[i];
    return param.count;
}

//функция подсчета длины строки
int s21_strlen(char *str_du) {
    int i = 0;
    for (; str_du[i] != '\0'; i++);
    return i;
}

//выравнивание строки относительно ширины и точности
void s21_alignment(char ***str, param *param) {
    printf("%d ** %d\n", param->width, param->flag_zero);
    if (param->flag_minus == 1 && param->flag_zero == 1) param->flag_zero = 0;
    if (param->width == -1) param->width = 0;
    if (param->accuracy == -1) param->accuracy = 0;
    if (param->type == 'x' || param->type == 'X') {
        if (param->width > 0 && param->flag_zero == 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        else if (param->width > 0 && param->flag_zero == 1)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = '0';
        else if (param->accuracy > 0)
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
    else if (param->type == 'u' || param->type == 'd' || param->type == 'f' || param->type == 'E' || param->type == 'e') {
        printf("%d ** %d\n", param->width, param->accuracy);
        if (param->width > 0 && param->flag_zero == 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        if (param->va_int < 0 && param->width > 0 && param->accuracy > 0) (**str)[param->count++] = '-';
        //else if (param->va_f < 0 && param->width >= 0 && (param->type == 'e' || param->type == 'E')) (**str)[param->count++] = '-';
        if (param->width > 0 && param->flag_zero == 1)
            for (int i = 0; i < param->width - param->accuracy; i++)
                (**str)[param->count++] = '0';
        if (param->accuracy > 0 && param->va_f != 0.0 && param->type != 'E' && param->type != 'e')
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
    else if (param->type == 'c' || param->type == 's' || param->type == 'p') {
        if (param->width > 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        else if (param->accuracy > 0)
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
    else if (param->type == 'o') {
        if (param->width > 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        if (param->accuracy > 0)
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
    else {
        if (param->width > 0 && param->flag_zero == 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = '0';
        else if (param->width > 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        else if (param->width > 0)
            for (int i = 0; i < param->width - param->accuracy; i++)
                (**str)[param->count++] = ' ';
        if (param->accuracy > 0)
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
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

void s21_update_param(param *param) {
    param->count_sign = 0;
    param->width = 0;
    param->accuracy = -1;
    param->length = 'x';
    param->flag_hash = 0;
    param->flag_minus = 0;
    param->flag_plus = 0;
    param->flag_space = 0;
    param->flag_zero = 0;
    param->flag_dot = 0;
    param->va_int = 0;
    param->va_f = 0.01;
}

void s21_switch(char c, char *str_ready, va_list args, param *param) {
    switch (c) {
        case 'c':
            param->c = va_arg(args, int);
            case_c(&str_ready, param);
            break;
        case 'd':
            param->va_int = type(va_arg(args, long long int), param);
            case_u(&str_ready, param);
            break;
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (param->length == 'L') param->va_f = va_arg(args, long double);
            else {
                long double temp = va_arg(args, double);
                param->va_f = (long double)temp;
            }
            case_g(&str_ready, param);
            break;
        case 'u':
            param->va_int = va_arg(args, long long int);
            case_u(&str_ready, param);
            break;
        case 'f':
            if (param->length == 'L') param->va_f = va_arg(args, long double);
            else {
                double temp = va_arg(args, double);
                param->va_f = (long double)temp;
            }
            case_f(&str_ready, param);
            break;
        case 's':
            char *str_d = va_arg(args, char*);
            case_s(&str_ready, str_d, param);
            break;
        case 'x':
        case 'X':
            if (param->length == 'l') param->va_int = va_arg(args, long int);
            else { 
                int temp_x = va_arg(args, int);
                param->va_int = (long long int)temp_x;
            }
            if (param->va_int == -2147483648) param->va_int *= -1;
            if (param->va_int >= 0) case_x_plus(&str_ready, param);
            else case_x_minus(&str_ready, param);
            break;
        case 'o':
            if (param->length == 'l') param->va_int = va_arg(args, long int);
            else if (param->length == 'h'){ 
                long long int temp_o = va_arg(args, long long int);
                param->va_int = (long long int)temp_o;
                param->va_int = type(param->va_int, param);
            }
            else {
                long long int temp_o = va_arg(args, long long int);
                param->va_int = (long long int)temp_o;
            }
            if (param->flag_hash == 1) str_ready[param->count++] = '0';
            if (param->va_int >= 0) case_o_plus(&str_ready, param);
            else case_o_minus(&str_ready, param);
            break;
        case 'p':
            case_p(&str_ready, va_arg(args, char*), param);
            break;
        default:
            param->error = 1;
            break;
        }
}