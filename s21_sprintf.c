#include "s21_case.h"
#include "s21_sprintf.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// %[флаги][ширина][.точность][длина]спецификатор

int s21_sprintf(char *str, const char *str_format, ...) {
    param param = {0, 0, 0, 0, 0, 0, 'x', 'x', 'x', 'x', 'x','\0', 'x', 0, 0.0, 0, -1};
    va_list args;
    va_start(args, str_format);
    char *str_d, *str_sing, *str_ready;
    str_sing = calloc(10024 + 1, sizeof(char));
    str_ready = calloc(10024 + 1, sizeof(char));
    for (int i = 0; str_format[i] != '\0' && param.error == 0; i++) {
        param.count_sign = 0;
        if (str_format[i] == '%') {
            param.flag = 'x';
            param.flag2 = 'x';
            param.width = 0;
            param.accuracy = 0;
            param.length = 'x';
            param.star = -1;
            i++;
            //test
            printf("param->width0: %d %d %c %c\n", param.width, param.accuracy, param.flag, param.flag2);
            while (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || 
                str_format[i] == ' ' || str_format[i] == '.' || str_format[i] == '#' ||
                str_format[i] == '*' || (str_format[i] >= '0' && str_format[i] <= '9') ||
                str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L') {
                int next_i = 0;
                //printf("PARAM: %c\n", str_format[i]);
                //printf("param.flag0: %c\n", param.flag);
                printf("param->width1: %d %d %c %c\n", param.width, param.accuracy, param.flag, param.flag2);
                if (str_format[i] == '+') param.sign = '+';
                //
                else if (str_format[i] == '*') param.star = va_arg(args, int);
                else if (param.flag == '-' && param.flag2 == '#' && str_format[i] == '.') {
                    printf("TUT1\n");
                    param.flag = '.';
                    param.accuracy -= param.width;
                    param.width = 0;
                }
                else if ((param.flag == '#' || param.flag == '-') && str_format[i] == '.') {
                    printf("TUT11\n");
                    param.flag2 = '.';
                }
                else if ((param.flag == '#' && str_format[i] == '*') ||
                        ((param.flag == '-' && str_format[i] == '*'))) {
                            printf("TUT12\n");
                            param.width = (va_arg(args, int) - param.width > 0) ? va_arg(args, int) - param.width : param.width;
                        }
                else if (param.flag == ' ' && param.width == 0 && str_format[i] == '.') {
                    printf("TUT13\n");
                    param.flag2 = '.';
                }
                //
                else if (param.flag == '#' && str_format[i] == '-') {
                    printf("TUT2\n");
                    param.flag = '-';
                    param.flag2 = '#';
                }
                //else if (str_format[i] == '*' && param.flag == '.') param.accuracy = va_arg(args, int) - param.accuracy;
                else if (str_format[i] == '*' && param.flag == '.') {
                    printf("TUT3\n");
                    param.accuracy = param.width;
                    param.width = 0;
                }
                else if (str_format[i] == '.' && param.flag == '*') {
                    printf("TUT4\n");
                    param.flag = '.';
                    //param.accuracy = param.width;
                }
                else if (str_format[i] == '*') {
                    //param.width = va_arg(args, int) - param.width;
                    printf("TUT5\n");
                    int z = va_arg(args, int);
                    param.width = (z - param.width > 0) ? z - param.width : param.width;
                    param.flag = '*';
                }
                else if (str_format[i] == '-' || str_format[i] == ' ' || 
                    str_format[i] == '.' || str_format[i] == '#' || 
                    (str_format[i] == '0' && param.flag == 'x')) {
                        printf("TUT51\n");
                        param.flag = str_format[i];
                    }
                else if (str_format[i] >= '0' && str_format[i] <= '9' && (param.flag == '.' || param.flag2 == '.')) {
                    printf("TUT6\n");
                    while (str_format[i] >= '0' && str_format[i] <= '9')
                        str_sing[param.count_sign++] = str_format[i++];
                    str_sing[param.count_sign] = '\0';
                    param.accuracy = s21_str_to_number(str_sing);
                    next_i = 1;
                }
                else if (str_format[i] >= '0' && str_format[i] <= '9') {
                    printf("TUT7\n");
                    while (str_format[i] >= '0' && str_format[i] <= '9')
                        str_sing[param.count_sign++] = str_format[i++];
                    str_sing[param.count_sign] = '\0';
                    param.width = s21_str_to_number(str_sing);
                    //printf("param.width1: %d\n", param.width);
                    next_i = 1;
                }
                else if (str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L')
                    param.length = str_format[i];
                //if (str_format[i] == '*') 
                //    param.width = va_arg(args, int) - param.width;
                //printf("param.length: %c\n", param.length);
                if (param.count_sign > 0) {
                    free(str_sing);
                    str_sing = calloc(1024 + 1, sizeof(char));
                    param.count_sign = 0;
                }
                if (next_i == 0) i++;
                if (param.star != -1 && (param.flag == '0' || param.flag == 'x')) {
                    param.width = (param.star - param.width > 0) ? param.star - param.width : param.width;
                    param.star = -1;
                }
                else if (param.star != -1 && (param.flag == '.' || param.flag2 == '.')) {
                    param.accuracy = param.star;
                    param.star = -1;
                }
                //printf("param.flag: %c\n", param.flag);
                //printf("param.width: %d\n", param.width);
            }
            //test
            /*
            //flag
            if (str_format[i] == '-' || str_format[i] == '+' || str_format[i] == '0' || str_format[i] == ' ' || str_format[i] == '.' || str_format[i] == '#')
                param.flag = str_format[i++];
            //
            if (str_format[i] == '.') param.flag = str_format[i++];
            //
            if (str_format[i] == '*') {
                //printf("TUT111\n");
                param.width = va_arg(args, int);
                i++;
            }
            if (str_format[i] == '+' || str_format[i] == '-') i++;
            //flag
            //wigth
            while (str_format[i] >= '0' && str_format[i] <= '9') {
                str_sing[param.count_sign++] = str_format[i++];
            }
            str_sing[param.count_sign] = '\0';
            if (param.width == 0) param.width = s21_str_to_number(str_sing);
            //printf("PARAM: %d\n", param.width);
            str_sing[0] = '\0';
            param.count_sign = 0;
            //wigth
            //accuracy
            if (str_format[i] == '.') {
                //
                param.flag = '.';
                //param.acc = '.';
                //
                i++;
                while (str_format[i] >= '0' && str_format[i] <= '9')
                    str_sing[param.count_sign++] = str_format[i++];
                str_sing[param.count_sign] = '\0';
                //
                param.accuracy = s21_str_to_number(str_sing);
                //param.width = s21_str_to_number(str_sing);
                param.width = (param.width == 0) ? s21_str_to_number(str_sing) : param.width;
                //
            }
            if (str_format[i] == '*') {
                //printf("TUT222\n");
                param.width = va_arg(args, int) - param.width;
                i++;
            }
            //accuracy
            //length
            if (str_format[i] == 'h' || str_format[i] == 'l'|| str_format[i] == 'L')
                param.length = str_format[i++];
            //length
            */
            param.type = str_format[i];
            //printf("STR: %s\n", str_ready);
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
                    if (param.length == 'L') param.va_f = va_arg(args, long double);
                    else {
                        double temp = va_arg(args, double);
                        param.va_f = (long double)temp;
                    }
                    if (param.va_f == (long long int)param.va_f) param.its_float = 1;
                    //if (param.va_f == 0) str_ready[param.count++] = '0';
                    //else case_g(&str_ready, &param);
                    //printf("VA1: %Lf\n", param.va_f);
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
                    //printf("PARAM: %Lf\n", param.va_f);
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
                    if (param.length == 'l') param.va_int = va_arg(args, long int);
                    else { 
                        int temp_x = va_arg(args, int);
                        param.va_int = (long long int)temp_x;
                    }
                    if (param.va_int == -2147483648) param.va_int *= -1;
                    //if ((param.flag == '#' || param.flag2 == '#') && param.va_int != 0) {
                    //    str_ready[param.count++] = '0';
                    //    str_ready[param.count++] = (param.type == 'x') ? 'x' : 'X';
                    //    param.width -= 2;
                    //}
                    printf("main: %lld\n", param.va_int);
                    if (param.va_int >= 0) case_x_plus(&str_ready, &param);
                    else case_x_minus(&str_ready, &param);
                    break;
                case 'o':
                    if (param.length == 'l') param.va_int = va_arg(args, long int);
                    else { 
                        int temp_o = va_arg(args, int);
                        param.va_int = (long long int)temp_o;
                    }
                    //printf("param.va_int: %lld\n", param.va_int);
                    if (param.flag == '#') str_ready[param.count++] = '0';
                    if (param.va_int >= 0) case_o_plus(&str_ready, &param);
                    else case_o_minus(&str_ready, &param);
                    break;
                case 'p':
                    //str_d = va_arg(args, char*);
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
    //printf("param.count: %d\n", param.count);
    if (param.error == 0)
        for (int i = 0; str_ready[i] != '\0'; i++)
            str[i] = str_ready[i];
    //printf("STR_END: %s\n", str);
    return param.count;
}

int s21_strlen(char *str_du) {
    int i = 0;
    for (; str_du[i] != '\0'; i++);
    return i;
}

void s21_alignment(char ***str, param *param) {
    /*
    if (param->flag == '-' || param->flag == '+' || param->width > 0 || (param->flag != '0' && param->flag != '.'))
        for (int i = 0; i < param->width; i++)
            (**str)[param->count++] = ' ';
    else if (param->flag == '0' || param->flag == '.' || param->accuracy > 0)
        for (int i = 0; i < param->width; i++)
            (**str)[param->count++] = '0';
    */
    printf("s21_alignment: %d ** %d ** %c ** %c ** %lld\n", param->width, param->accuracy, param->flag, param->flag2, param->va_int);
    printf("param->type: %c\n", param->type);
    if ((param->type == 'x' || param->type == 'X') && param->va_int < 0) {
        if (param->width > 0)
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
    }
    else if (param->type == 'u' || param->type == 'd' || param->type == 'f') {
        if (param->width > 0 && param->flag != '0')
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        else if (param->width > 0)
            for (int i = 0; i < param->width - param->accuracy; i++)
                (**str)[param->count++] = '0';
        else if (param->accuracy > 0)
            for (int i = 0; i < param->accuracy; i++)
                (**str)[param->count++] = '0';
    }
    else {
        if (param->width > 0 && param->flag == '0')
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = '0';
        else if (param->width > 0 && param->type == 'c')
            for (int i = 0; i < param->width; i++)
                (**str)[param->count++] = ' ';
        else if (param->width > 0)
            for (int i = 0; i < param->width - param->accuracy; i++)
                (**str)[param->count++] = ' ';
        if (param->accuracy > 0 && param->type != 'c')
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