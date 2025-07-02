#include "s21_case.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void case_c(char **str, param *param) {
    param->width -= 1;
    if (param->flag_minus == 1&& param->width > 0) {
        (*str)[param->count++] = param->c;
        s21_alignment(&str, param);
    }
    else if (param->flag_zero == 1 || param->flag_plus == 1 || param->width > 0) {
        s21_alignment(&str, param);
        (*str)[param->count++] = param->c;
    }
    else (*str)[param->count++] = param->c;
}

void case_u(char **str, param *param) {
    printf("param->width1: %d\n", param->width);
    char *str_du = NULL;
    int dont_print = 0;
    printf("STR0: %s\n", *str);
    if (param->length == 'l' && param->va_int == LLONG_MIN) {
        (*str)[param->count++] = '-';
        const char str_llmin[] = "9223372036854775808";
        str_du = calloc(20, sizeof(char));
        for (int i = 0; i < 19; i++) str_du[i] = str_llmin[i];
    }
    else str_du = s21_atoi_new(param);
    int strlen = s21_strlen(str_du);
    if (param->accuracy == 0 && param->va_int == 0) strlen = 0; //%20.0d - 0
    printf("STR: %s * %d\n", str_du, strlen);
    //s21_width_accuracy(strlen, param);
    if (param->flag_space == 1 && param->type != 'u' && param->flag_plus == 0 && str_du[0] != '-' && param->va_int >= 0) {
        (*str)[param->count++] = ' ';
        param->width = (param->width > 0) ? param->width - 1: param->width;
    }
    else if (param->flag_plus == 1 && param->va_int >= 0 && (param->flag_minus == 1 || param->flag_space == 1 || param->flag_zero == 1)) param->width = (param->width > 0) ? param->width - 1: param->width;    
    if (param->flag_hash == 1 && param->flag_space == 0) param->width += 2;
    printf("param->width2: %d * %d\n", param->width, param->accuracy);
    s21_width_accuracy(strlen, param);
    printf("param->width3: %d * %d * %lld\n", param->width, param->accuracy, param->va_int);
    //printf("STR00: %s\n", *str);
    if ((param->width < strlen && param->accuracy < 0 && param->va_int < 0 && param->type == 'd') || (param->flag_minus == 1 && param->va_int < 0 && param->type == 'd')) {
        if (param->va_int != LLONG_MIN) (*str)[param->count++] = '-';
        param->width--;
        param->flag_zero = 0;
    }
    else if (param->va_int < 0 && param->type == 'd') param->width--;
    if (param->flag_minus == 1) {
        dont_print = 1;
        if (param->type != 'u' && param->flag_plus == 1 && param->va_int > 0) {
            (*str)[param->count++] = '+';
            param->flag_plus = 0;
        }
        for (int i = 0; i < param->accuracy; i++)
            (*str)[param->count++] = '0';
        param->accuracy = 0;
        for (int j = 0; str_du[j] != '\0'; j++) (*str)[param->count++] = str_du[j];
        for (int i = 0; i < param->width; i++)
            (*str)[param->count++] = ' ';
    }
    else if (param->width > 0 && param->accuracy > 0) {
        dont_print = 1;
        if (param->flag_plus == 1) param->width--;
        for (int i = 0; i < param->width; i++)
            (*str)[param->count++] = ' ';
        if (param->flag_plus == 1) (*str)[param->count++] = '+';
        for (int i = 0; i < param->accuracy; i++)
            (*str)[param->count++] = '0';
        for (int j = 0; str_du[j] != '\0'; j++) (*str)[param->count++] = str_du[j];
    }
    else if (param->flag_zero == 1 || (param->accuracy > 0 && param->width <= 0)) {
        if (param->va_int < 0) (*str)[param->count++] = '-';
        else if (param->flag_plus == 1 && param->type != 'u' && param->va_int > 0) {
            (*str)[param->count++] = '+';
            param->flag_plus = 0;
        }
        s21_alignment(&str, param);
    }
    else if (param->width > 0) {
        s21_alignment(&str, param);
        if (param->flag_plus == 1 && param->va_int > 0) {
            if (param->flag_space == 0) param->count--;
            (*str)[param->count++] = '+';
            param->flag_plus = 0;
        }
    }/*
    else if (param->accuracy > 0) {
        if (param->va_int < 0) (*str)[param->count++] = '-';
        else if (param->flag_plus == 1 && param->va_int >= 0) {
            (*str)[param->count++] = '+';
            param->flag_plus = 0;
        }
        s21_alignment(&str, param);
    }*/
    else if (param->length == 'h') {
        while (param->va_int >= 65536) param->va_int -= 65536;
        //param->va_int = s21_to_binary(param);
        str_du = s21_atoi_new(param);
    }
    //else if (param->length == 'l' && param->va_int != LLONG_MIN) {
        //while ((unsigned long long)param->va_int > 18446744073709551615UL) param->va_int -= 18446744073709551614UL;
        //param->va_int = s21_to_binary(param);
        //str_du = s21_atoi_new(param);
    //}
    printf("STR!!!: %s \n", *str);
    if (param->type != 'u' && param->flag_plus == 1 && param->va_int > 0 && dont_print == 0) (*str)[param->count++] = '+';
    if ((param->flag_minus == 0) && !(param->flag_dot == 1 && param->accuracy == 0 && param->va_int == 0) && dont_print == 0)
        //for (int j = (param->va_int < 0 && (param->flag_zero == 1 || param->accuracy > 0)) ? 1 : 0; str_du[j] != '\0'; j++)
        //    (*str)[param->count++] = str_du[j];
        for (int j = 0; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
    printf("STR!!!: %s \n", *str);
    free(str_du);
}

void case_f(char **str, param *param) {
    char *str_int;
    str_int = s21_atoi_new(param);
    int strlen = s21_strlen(str_int);
    if (param->va_f == 0.0 && param->type == 'f') s21_width_accuracy_f_0(strlen, param);
    else s21_width_accuracy(strlen, param);
    if (param->flag_plus == 1 && param->width > 0) param->width--;
    if (param->flag_space == 1 && param->va_f >= 0) (*str)[param->count++] = ' ';
    if (param->va_f < 0 && param->width <= 0 && param->accuracy <= 0) (*str)[param->count++] = '-';
    if (param->width > 0)
        s21_alignment(&str, param);
    if (param->flag_plus == 1 && param->va_f >= 0)
        (*str)[param->count++] = '+';
    printf("str_int: %s\n", str_int);
    for (int j = 0 ; str_int[j] != '\0'; j++) {
        (*str)[param->count++] = str_int[j];
    }
    printf("str: %s\n", *str);
    //"%1.0f", 0.0
    if (param->type == 'f' && param->va_f == 0.0 && param->flag_space == 0 && param->length == 'x' && param->accuracy == 0) {
        while ((*str)[param->count - 1] == '0') param->count--;
        if ((*str)[param->count - 1] == '.') param->count--;
    }
    else if (param->type == 'f' && param->va_f == 0.0 && param->accuracy > 0) {
        while(param->accuracy-- > 1) (*str)[param->count++] = '0';
    }
    /*
    else if (param->type == 'f' && param->va_f == 0.0 && param->flag_space == 0 && param->length == 'x' && param->accuracy > 0) {
        while(param->accuracy-- > 1) (*str)[param->count++] = '0';
    }
    */
    free(str_int);
}

void case_g(char **str, param *param) {
    char *str_int;
    int count = 0, less_zero = 0;
    long double param_va_f = param->va_f;
    if (param->flag_plus == 1 && param->va_f >= 0) (*str)[param->count++] = '+';
    else if (param->flag_space == 1 && param->va_f >= 0) (*str)[param->count++] = ' ';
    if (param_va_f < 0) {
        param_va_f *= (-1.0);
        less_zero = 1;
    }
    if (param->va_f == 0.0 && (param->type == 'g' || param->type == 'G')) {
        printf("0!!!\n");
        (*str)[param->count++] = '0';
    }
    //else if ((param->va_f >= pow(10, 6) || param_va_f >= pow(10, 6)) || ((param->type == 'e' || param->type == 'E') && param->va_f >= 1)) {
    else if ((param->va_f >= pow(10, 6) || param_va_f >= pow(10, 6)) || ((param->type == 'e' || param->type == 'E') && (param->va_f >= 1 || param_va_f >= 1))) {
        printf("1!!!\n");
        if (less_zero == 1) param->va_f *= -1;
        while (param->va_f >= 10.0) {
            param->va_f = param->va_f / 10;
            count++;
        }
        if (less_zero == 1) param->va_f *= -1;
        printf("param->va_f: %.20Lf\n", param->va_f);
        //if (less_zero == 1) {
        //    param->width--;
        //    param->va_f *= (-1.0);
        //}
        str_int = s21_atoi_new(param);
        printf("str_int: %s\n", str_int);
        param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) - 4 : -1;
        printf("param->width: %d\n", param->width);
        if (param->flag_zero == 1 || param->width >= 0) s21_alignment(&str, param);
        else if (param->va_f < 0) (*str)[param->count++] = '-';
        //else if (!(param->flag_zero == 1 || param->width >= 0) && less_zero == 1) (*str)[param->count++] = '-';
        //if (less_zero == 1) {
        //    (*str)[param->count++] = '-';
        //    param->va_f *= (-1.0);
        //}
        //if (param->va_f < 0 && param->width <= 0 && param->accuracy <= 0) (*str)[param->count++] = '-';
        for (int j = 0 ; str_int[j] != '\0'; j++ ) (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
        (*str)[param->count++] = '+';
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else if ((param->va_f < pow(10, -4) || param_va_f < pow(10, -4)) || ((param->type == 'e' || param->type == 'E') && (param->va_f < 1 || param->va_f < 1))) {
        printf("2!!!\n");
        if (less_zero == 1) param->va_f *= -1;
        while ((param->va_f + 0.000001) < 1.0 && param->va_f != 0.0) {
            param->va_f *= 10;
            count++;
        }
        if (less_zero == 1) param->va_f *= -1;
        if (param->accuracy == 0) param->va_f = round(param->va_f);
        str_int = s21_atoi_new(param);
        printf("str_int: %s\n", str_int);
        param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) - 4 : -1;
        //if (less_zero == 1) {
        //    (*str)[param->count++] = '-';
        //    param->va_f *= (-1.0);
        //}
        printf("param->width: %d\n", param->width);
        if (param->flag_zero == 1 || param->width >= 0) s21_alignment(&str, param);
        else if (param->va_f < 0) (*str)[param->count++] = '-';
        //else if (!(param->flag_zero == 1 || param->width >= 0) && less_zero == 1) (*str)[param->count++] = '-';
        //if (less_zero == 1) param->va_f *= (-1.0);
        printf("str1: %s\n", *str);
        for (int i = s21_strlen(str_int) - 1; i >= 0 && (param->type == 'g' || param->type == 'G'); i--) {
            if (str_int[i] == '0' || str_int[i] == '.' || str_int[i] == '\0') str_int[i] = '\0';
            else break;
        }
        for (int j = 0; str_int[j] != '\0'; j++ ) {
            (*str)[param->count++] = str_int[j];
        }
        (*str)[param->count++] = (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
        (*str)[param->count++] = (param->va_f == 0.0) ? '+' : '-';
        if (count >= 100) (*str)[param->count++] = '0' + ((count / 100) % 10);
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else {
        printf("3!!!\n");
        if (param->va_f < 1.0) param->g = 0;
        else if (param->va_f < 10.0) param->g = 1;
        else if (param->va_f < 100.0) param->g = 2;
        else if (param->va_f < 1000.0) param->g = 3;
        else if (param->va_f < 10000.0) param->g = 4;
        else if (param->va_f < 100000.0) param->g = 5;
        else param->g = 6;
        str_int = s21_atoi_new(param);
        printf("str_int: %s\n", str_int);
        for (int j = 0 ; str_int[j] != '\0'; j++ ) {
            (*str)[param->count++] = str_int[j];
        }
        if (param->flag_hash == 0) {
            param->count--;
            while ((*str)[param->count] == '0') param->count--;
            if ((*str)[param->count] == '.') (*str)[param->count] = '\0';
            param->count++;
        }
        (*str)[param->count] = '\0';
    }
}
/*
void case_g(char **str, param *param) {
    char *str_int;
    int count = 0, less_zero = 0;
    //long double param_va_f = param->va_f;
    if (param->flag_plus == 1 && param->va_f >= 0) (*str)[param->count++] = '+';
    else if (param->flag_space == 1 && param->va_f >= 0) (*str)[param->count++] = ' ';
    if (param->va_f < 0) {
        param->va_f *= (-1.0);
        less_zero = 1;
    }
    if (param->va_f == 0.0 && (param->type == 'g' || param->type == 'G')) {
        (*str)[param->count++] = '0';
    }
    else if (param->va_f >= pow(10, 6) || ((param->type == 'e' || param->type == 'E') && param->va_f >= 1)) {
        printf("1!!!\n");
        while (param->va_f >= 10.0) {
            param->va_f = param->va_f / 10;
            count++;
        }
        printf("param->width: %d\n", param->width);
        str_int = s21_atoi_new(param);
        param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) - 4 : -1;
        if (less_zero == 1) {
            param->width--;
            param->va_f *= (-1.0);
        }
        printf("param->width: %d\n", param->width);
        if (param->flag_zero == 1 || param->width >= 0) s21_alignment(&str, param);
        //else if (!(param->flag_zero == 1 || param->width >= 0) && less_zero == 1) (*str)[param->count++] = '-';
        if (less_zero == 1) {
            (*str)[param->count++] = '-';
            param->va_f *= (-1.0);
        }
        for (int j = 0 ; str_int[j] != '\0'; j++ ) (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
        (*str)[param->count++] = '+';
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else if (param->va_f < pow(10, -4) || ((param->type == 'e' || param->type == 'E') && param->va_f < 1)) {
        printf("2!!!\n");
        while ((param->va_f + 0.000001) < 1 && param->va_f != 0) {
            param->va_f *= 10;
            count++;
        }
        if (param->accuracy == 0) param->va_f = round(param->va_f);
        str_int = s21_atoi_new(param);
        param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) - 4 : -1;
        if (less_zero == 1) {
            (*str)[param->count++] = '-';
            param->va_f *= (-1.0);
        }
        printf("param->width: %d\n", param->width);
        if (param->flag_zero == 1 || param->width >= 0) s21_alignment(&str, param);
        //else if (!(param->flag_zero == 1 || param->width >= 0) && less_zero == 1) (*str)[param->count++] = '-';
        if (less_zero == 1) param->va_f *= (-1.0);
        printf("str1: %s\n", *str);
        for (int i = s21_strlen(str_int) - 1; i >= 0 && (param->type == 'g' || param->type == 'G'); i--) {
            if (str_int[i] == '0' || str_int[i] == '.' || str_int[i] == '\0') str_int[i] = '\0';
            else break;
        }
        for (int j = 0; str_int[j] != '\0'; j++ ) {
            (*str)[param->count++] = str_int[j];
        }
        (*str)[param->count++] = (param->type == 'E' || param->type == 'G') ? 'E' : 'e';
        (*str)[param->count++] = (param->va_f == 0.0) ? '+' : '-';
        if (count >= 100) (*str)[param->count++] = '0' + ((count / 100) % 10);
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else {
        printf("3!!!\n");
        if (param->va_f < 1.0) param->g = 0;
        else if (param->va_f < 10.0) param->g = 1;
        else if (param->va_f < 100.0) param->g = 2;
        else if (param->va_f < 1000.0) param->g = 3;
        else if (param->va_f < 10000.0) param->g = 4;
        else if (param->va_f < 100000.0) param->g = 5;
        else param->g = 6;
        str_int = s21_atoi_new(param);
        printf("str_int: %s\n", str_int);
        for (int j = 0 ; str_int[j] != '\0'; j++ ) {
            (*str)[param->count++] = str_int[j];
        }
        if (param->flag_hash == 0) {
            param->count--;
            while ((*str)[param->count] == '0') param->count--;
            if ((*str)[param->count] == '.') (*str)[param->count] = '\0';
            param->count++;
        }
        (*str)[param->count] = '\0';
    }
}
*/
void case_s(char **str, char *str_d, param *param) {
    int strlen = s21_strlen(str_d);
    if (param->flag_dot == 1 && param->accuracy == -1) param->accuracy = 0;

    if (param->width >= 0 && param->accuracy >= 0) {
        if (param->flag_minus == 1 && param->width >= strlen && param->accuracy >= strlen) param->width -= strlen;
        else if (param->width < strlen && param->accuracy < strlen && param->width >= param->accuracy) param->width -= param->accuracy;
        else if (param->width < strlen && param->accuracy < strlen && param->accuracy > param->width) param->width = 0;//param->accuracy -= param->width;
        else if (param->width > param->accuracy && param->width >= strlen) param->width -= param->accuracy;
        else if (param->width > param->accuracy && param->accuracy > strlen) {
            param->width -= param->accuracy;
            param->accuracy -= strlen;
        }
        else if (param->accuracy >= param->width && param->accuracy >= strlen) {
            param->accuracy = -1;
            param->width -= strlen;
        }
    }
    else if (param->width >= 0) {
        if (param->width > strlen) param->width = (param->width - strlen >= 0) ? param->width - strlen : param->width;
        else param->width = 0;
    }
    else if (param->accuracy >= 0) {
        param->accuracy = (param->accuracy - strlen >= 0) ? param->accuracy - strlen : param->accuracy;
    }

    if (param->flag_minus == 1 && param->flag_dot == 0) {
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
        s21_alignment(&str, param);
    }
    else if (param->flag_zero == 1 || param->flag_plus == 1 || (param->width > 0 && param->accuracy == -1)) {
        s21_alignment(&str, param);
        for (int j = 0 ; str_d[j] != '\0'; j++)
            (*str)[param->count++] = str_d[j];
    }
    else if (param->flag_minus == 0 && param->accuracy == -1)
        for (int j = 0 ; str_d[j] != '\0'; j++) {
            (*str)[param->count++] = str_d[j];
        }
    else if (param->width >= 0 && param->accuracy >= 0) {
        if (param->flag_minus == 0) {
            int par_acc = param->accuracy - s21_strlen(str_d);
            while (param->width-- > 0) (*str)[param->count++] = ' ';
            while (par_acc-- > 0) (*str)[param->count++] = ' ';
        }
        for (int j = 0 ; str_d[j] != '\0'; j++) {
            if (param->accuracy-- > 0)
                (*str)[param->count++] = str_d[j];
            else if (param->accuracy == 0) break;
        }
        while (param->width-- > 0) (*str)[param->count++] = ' ';
    }
    else {
        for (int j = 0 ; str_d[j] != '\0'; j++)
            (*str)[param->count++] = str_d[j];
    }
}

void case_x_plus(char **str, param *param) {
    printf("param->width0: %d * %d\n", param->width, param->flag_zero);
    int count = 0;
    long long int x, temp_va = param->va_int;
    char *str_x;
    str_x = calloc(1024 + 1, sizeof(char));
    if (param->va_int == 0) str_x[count++] = '0';
    while (temp_va > 0) {
        x = temp_va % 16;
        temp_va /= 16;
        if (x > 9) {
            switch (x % 10) {
                case 0:
                    str_x[count++] = (param->type == 'x') ? 'a' : 'A';
                    break;
                case 1:
                    str_x[count++] = (param->type == 'x') ? 'b' : 'B';
                    break;
                case 2:
                    str_x[count++] = (param->type == 'x') ? 'c' : 'C';
                    break;
                case 3:
                    str_x[count++] = (param->type == 'x') ? 'd' : 'D';
                    break;
                case 4:
                    str_x[count++] = (param->type == 'x') ? 'e' : 'E';
                    break;
                case 5:
                    str_x[count++] = (param->type == 'x') ? 'f' : 'F';
                    break;
                default:
                    break;
            }
        }
        else str_x[count++] = '0' + (x % 10);
    }
    str_x[count] = '\0';
    int strlen = s21_strlen(str_x);
    s21_width_accuracy(strlen, param);
    int dont_print = 0;
    if (param->width > 0 && param->flag_minus == 0 && param->flag_zero == 0) {
        s21_alignment(&str, param);
        if ((param->flag_hash == 1) && param->va_int != 0) {
            dont_print = 1;
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
    }
    else if (param->width > 0 && param->flag_zero == 1) {
        if ((param->flag_hash == 1) && param->va_int != 0) {
            dont_print = 1;
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
        s21_alignment(&str, param);
    }
    if (param->accuracy > 0) {
        param->width = 0;
        if (param->flag_hash == 1 && param->va_int != 0 && dont_print == 0) {
            dont_print = 1;
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
        s21_alignment(&str, param);
        param->flag_minus = 0;
    }
    else if ((param->flag_hash == 1) && dont_print == 0 && param->va_int != 0) {
        (*str)[param->count++] = '0';
        (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    for (int i = count - 1; i >= 0; i--)
        (*str)[param->count++] = str_x[i];
    if (param->flag_minus == 1)
        s21_alignment(&str, param);
}

void case_x_minus(char **str, param *param) {
    int count = 0, count_revers = 0, plus = 0;
    long long int result;
    char *binary_str_revers, *binary_str, *str_x;
    str_x = calloc(1024 + 1, sizeof(char));
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    long long int x_va_int = param->va_int * -1;
    while (x_va_int > 0) {
        binary_str_revers[count_revers++] = (x_va_int % 2 == 0) ? '0' : '1';
        x_va_int /= 2;
    }
    int zero = 4 - (count_revers % 4), multi = 0;
    count = 0;
    while (zero-- != 0) binary_str[count++] = '0';
    for (int i = count_revers - 1; i >= 0; i--)
        binary_str[count++] = binary_str_revers[i];
    for (int i = count - 1; i >= 0; i--) {
        if (binary_str[i] == '1' && i == count - 1)
            binary_str[i] = '1';
        else if (binary_str[i] == '0' && i == count - 1)
            plus = 1;
        else if (binary_str[i] == '1' && plus == 1)
            plus = 0;
        else if (binary_str[i] == '0' && plus == 0) 
            binary_str[i] = '1';
        else if (binary_str[i] == '1' && plus == 0) 
            binary_str[i] = '0';
    }
    count_revers = 0;
    for (int j = 0; j < 8 - (count / 4); j++) str_x[count_revers++] = (param->type == 'x') ? 'f' : 'F';
    multi = 3;
    result = 0;
    for (int i = 0; i < count; i++) {
        if (binary_str[i] == '1')
            result += (pow(2, multi));
        multi--;
        if ((i + 1) % 4 == 0 && i != 0) {
            if (result > 9) {
                switch (result % 10) {
                    case 0:
                        str_x[count_revers++] = (param->type == 'x') ? 'a' : 'A';
                        break;
                    case 1:
                        str_x[count_revers++] = (param->type == 'x') ? 'b' : 'B';
                        break;
                    case 2:
                        str_x[count_revers++] = (param->type == 'x') ? 'c' : 'C';
                        break;
                    case 3:
                        str_x[count_revers++] = (param->type == 'x') ? 'd' : 'D';
                        break;
                    case 4:
                        str_x[count_revers++] = (param->type == 'x') ? 'e' : 'E';
                        break;
                    case 5:
                        str_x[count_revers++] = (param->type == 'x') ? 'f' : 'F';
                        break;
                    default:
                        break;
                }
            }
            else str_x[count_revers++] = '0' + (result % 10);
            result = 0;
            plus = 0;
            multi = 3;
        }
    }
    str_x[count_revers] = '\0';
    int strlen = s21_strlen(str_x);
    s21_width_accuracy(strlen, param);
    int dont_print = 0;
    if (param->width > 0 && param->flag_minus == 0) {
        s21_alignment(&str, param);
        if ((param->flag_hash == 1) && param->va_int != 0) {
            dont_print = 1;
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
    }
    if (param->accuracy > 0) {
        param->width = 0;
        if (param->flag_hash == 1 && dont_print == 0) {
            dont_print = 1;
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
        s21_alignment(&str, param);
    }
    else if ((param->flag_hash == 1) && dont_print == 0) {
        (*str)[param->count++] = '0';
        (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    for (int i = 0; i < count_revers; i++) {
        if (param->length != 'h' || i > count_revers - 5) 
            (*str)[param->count++] = str_x[i];
    }
    free(str_x);
}

void case_o_plus(char **str, param *param) {
    int count = 0;
    char *str_o;
    str_o = calloc(1024 + 1, sizeof(char));
    if (param->va_int == 0) str_o[count++] = '0';
    while (param->va_int > 0) {
        str_o[count++] = '0' + param->va_int % 8;
        param->va_int /= 8;
    }
    printf("STR: %s\n", str_o);
    int strlen = s21_strlen(str_o);
    s21_width_accuracy(strlen, param);
    if (param->flag_minus == 1 && param->flag_dot == 0) {
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
        s21_alignment(&str, param);
    }
    else if (param->width > 0) {
        s21_alignment(&str, param);
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
    }
    else if (param->accuracy > 0) {
        s21_alignment(&str, param);
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
    }
    //l here
    else for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
}

void case_o_minus(char **str, param *param) {
    printf("TUT!\n");
    int count = 0, count_revers = 0, plus = 1, three = 0;
    char *binary_str_revers, *binary_str, *str_x8, *str3;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    str_x8 = calloc(100 + 1, sizeof(char));
    str3 = calloc(4 + 1, sizeof(char));
    param->va_int *= -1;
    while (param->va_int > 0) {
        binary_str_revers[count_revers++] = (param->va_int % 2 == 0) ? '0' : '1';
        param->va_int /= 2;
    }
    binary_str[count++] = '1';
    printf("STR0: %s\n", binary_str_revers);
    for (int i = 0; i < 32 - count_revers; i++) binary_str[count++] = '0';
    for (int i = count_revers - 1; i >= 0; i--) binary_str[count++] = binary_str_revers[i];
    for (int i = 0; binary_str[i] != '\0'; i++) {
        if (binary_str[i] == '0') binary_str[i] = '1';
        else binary_str[i] = '0';
    }
    for (int i = count - 1; i >= 0; i--) {
        if (binary_str[i] == '1' && plus == 1) binary_str[i] = '0';
        else if (binary_str[i] == '0' && plus == 1) {
            binary_str[i] = '1';
            plus = 0;
        }
    }
    count = 0;
    for (int i = 0; binary_str[i] != '\0'; i++) {
        str3[three++] = binary_str[i];
        if (three == 3) {
            str3[three] = '\0';
            str_x8[count++] = x8(&str3);
            three = 0;
        }
    }
    str_x8[count] = '\0';
    int strlen = s21_strlen(str_x8);
    s21_width_accuracy(strlen, param);
    if (param->width > 0) {
        s21_alignment(&str, param);
        for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
    }
    else if (param->accuracy > 0) {
        s21_alignment(&str, param);
        for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
    }
    else for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
    free(binary_str_revers);
    free(binary_str);
    free(str_x8);
    free(str3);
}

char x8(char **str) {
    char x8;
    if ((*str)[0] == '0' && (*str)[1] == '0' && (*str)[2] == '0') x8 = '0';
    else if ((*str)[0] == '0' && (*str)[1] == '0' && (*str)[2] == '1') x8 = '1';
    else if ((*str)[0] == '0' && (*str)[1] == '1' && (*str)[2] == '0') x8 = '2';
    else if ((*str)[0] == '0' && (*str)[1] == '1' && (*str)[2] == '1') x8 = '3';
    else if ((*str)[0] == '1' && (*str)[1] == '0' && (*str)[2] == '0') x8 = '4';
    else if ((*str)[0] == '1' && (*str)[1] == '0' && (*str)[2] == '1') x8 = '5';
    else if ((*str)[0] == '1' && (*str)[1] == '1' && (*str)[2] == '0') x8 = '6';
    else if ((*str)[0] == '1' && (*str)[1] == '1' && (*str)[2] == '1') x8 = '7';
    return x8;
}

void case_p(char **str, char *str_d, param *param) {
    param->length = 0;
    char *hex_addr, *hex_addr_2;
    hex_addr = calloc(1024 + 1, sizeof(char));
    hex_addr_2 = calloc(1024 + 1, sizeof(char));
    uintptr_t address = (uintptr_t) str_d;
    int first = 1, count = 2;
    if (str_d != NULL) {
        for(int i = sizeof(void*) * 2 - 1; i >= 0; --i) 
            hex_addr[i] = "0123456789abcdef"[((address >> (i * 4)) & 0xf)];
        hex_addr[sizeof(void *) * 2 + 1] = '\0';
        hex_addr_2[0] = '0';
        hex_addr_2[1] = 'x';
        while (param->accuracy - 12 > 0) {
            hex_addr_2[count++] = '0';
            param->accuracy--;
        }
        for (int i = sizeof(void*) * 2 - 1; i >= 0; --i) {
            if (first == 0) hex_addr_2[count++] = hex_addr[i];
            else if (hex_addr[i] != 'x' && hex_addr[i] != '0') {
                hex_addr_2[count++] = hex_addr[i];
                first = 0;
            }
        }
    }
    else {
        count = 0;
        hex_addr_2[count++] = '(';
        hex_addr_2[count++] = 'n';
        hex_addr_2[count++] = 'i';
        hex_addr_2[count++] = 'l';
        hex_addr_2[count++] = ')';
    }
    hex_addr_2[count] = '\0';
    int strlen = s21_strlen(hex_addr_2);
    s21_width_accuracy(strlen, param);
    if (param->flag_plus == 1 || param->flag_space == 1) param->width--;
    if (param->flag_zero == 1 && param->flag_dot == 0) {
        if (param->flag_plus == 1) (*str)[param->count++] = '+';
        else if (param->flag_space == 1) (*str)[param->count++] = ' ';
        for (int i = 0; i < 2; i++) (*str)[param->count++] = hex_addr_2[i];
        if (param->width > 0 &&  param->flag_minus == 0) s21_alignment(&str, param);
        for (int i = 2; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
        if (param->width > 0 &&  param->flag_minus == 1) s21_alignment(&str, param);
    }
    else if (param->flag_dot == 1) {
        printf("width: %d\n", param->width);
        if (param->flag_plus == 1 && param->width <= 0) (*str)[param->count++] = '+';
        else if (param->flag_space == 1) (*str)[param->count++] = ' ';
        if (param->width > 0 &&  param->flag_minus == 0) s21_alignment(&str, param);
        if (param->flag_plus == 1 && param->width > 0) (*str)[param->count++] = '+';
        for (int i = 0; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
        if (param->width > 0 &&  param->flag_minus == 1) s21_alignment(&str, param);
    }
    else {
        if (param->width > 0 &&  param->flag_minus == 0) s21_alignment(&str, param);
        if (param->flag_plus == 1) (*str)[param->count++] = '+';
        else if (param->flag_space == 1) (*str)[param->count++] = ' ';
        for (int i = 0; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
        if (param->width > 0 &&  param->flag_minus == 1) s21_alignment(&str, param);
    }
    free(hex_addr);
    free(hex_addr_2);
}

void s21_width_accuracy(int strlen, param *param) {
    printf("s21_width_accuracy: %d * %d * %d\n", param->width, param->accuracy, strlen);
    //if (param->va_f == 0.0 && param->type == 'f' && param->accuracy <= 0) param->width--;
    //else if (param->va_f == 0.0 && param->type == 'f' ) param->width -= strlen;
    if (param->width > 0 && param->accuracy >= 0) {
        if (param->width == strlen && param->accuracy == strlen) {
            param->width = 0;
            param->accuracy = 0;
            if (param->va_int < 0) param->accuracy++;
        }
        else if (param->width > param->accuracy && param->accuracy > strlen) {
            param->width -= param->accuracy;
            param->accuracy -= strlen;
            if (param->va_int < 0) {
                param->width--;
                param->accuracy++;
            }
        }
        else if (param->width >= param->accuracy && param->width >= strlen) {
            if (param->width > param->accuracy) {
                param->width -= strlen;
                param->accuracy = 0;
            }
            else if (param->width == param->accuracy) {
                param->accuracy -= strlen;
                param->width = 0;
            }
            //if (param->accuracy <= strlen) param->accuracy = 1;
            //param->accuracy = 0;
        }
        else if (param->accuracy >= param->width && param->accuracy >= strlen) {
            param->accuracy -= strlen;
            if (param->va_int < 0) param->accuracy++;
            param->width = 0;
        }
        else if (param->accuracy < strlen && param->width < strlen) {
            param->accuracy = 0;
            param->width = 0;
        }
    }
    else if (param->width > 0) {
        if ((param->flag_hash == 1) && param->va_int != 0) param->width -= 2;
        param->width -= strlen;
    }
    else if (param->accuracy > 0) {
        param->accuracy = (param->va_int >= 0) ? param->accuracy - strlen: param->accuracy - strlen + 1;
    }
    printf("s21_width_accuracy: %d * %d\n", param->width, param->accuracy);
}

void s21_width_accuracy_f_0(int strlen, param *param) {
    printf("s21_width_accuracy: %d * %d * %d\n", param->width, param->accuracy, strlen);
    //if (param->va_f == 0.0 && param->type == 'f' && param->accuracy <= 0) param->width--;
    //else if (param->va_f == 0.0 && param->type == 'f' ) param->width -= strlen;
    if (param->width > 0 && param->accuracy >= 0) {
        if (param->width == strlen && param->accuracy == strlen) {
            param->width = 0;
        }
        //else if (param->width > param->accuracy && param->accuracy > strlen) {
        //    param->width -= param->accuracy;
        //    param->accuracy -= strlen;
        //    }
        //}
        else if (param->width >= param->accuracy && param->width >= strlen) {
            if (param->accuracy == 0)
                param->width--;
            else if (param->width > strlen && param->accuracy <= strlen) {
                param->width -= (strlen + param->accuracy - 1);
                //strlen = (param->accuracy >= strlen) ? param->accuracy + strlen - 1 : strlen + 1;
                //param->width -= strlen;
            }
            else if (param->accuracy > strlen) param->width -= (param->accuracy + 2);
            else if (param->width >= param->accuracy && param->width >= strlen)
                param->width = 0;
            else if (param->width == strlen)
                param->width -= strlen;
            else {
                param->width -= strlen;
                param->accuracy = 0;
            }
        }
        else if (param->width >= param->accuracy) {
            if (param->accuracy == 0) param->width--;
            else param->width = 0;
        }
        else if (param->accuracy >= param->width && param->accuracy >= strlen) {
            param->width = 0;
        }
        else if (param->accuracy < strlen && param->width < strlen) {
            param->width = 0;
        }
    }
    printf("s21_width_accuracy: %d * %d\n", param->width, param->accuracy);
}
