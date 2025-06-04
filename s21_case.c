#include "s21_case.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void case_c(char **str, param *param) {
    param->width -= 1;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        (*str)[param->count++] = param->c;
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || param->width > 0) {
        s21_alignment(&str, param);
        (*str)[param->count++] = param->c;
    }
    else (*str)[param->count++] = param->c;
}

void case_u(char **str, param *param) {
    char *str_du = NULL;
    //str_du = s21_atoi(param);
    str_du = s21_atoi_new(param);
    param->width = (param->width > s21_strlen(str_du)) ? param->width - s21_strlen(str_du) : 0;
    if (param->flag == ' ' && str_du[0] != '-') (*str)[param->count++] = ' ';
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
        param->va_int = s21_to_binary(param);
        //str_du = s21_atoi(param);
        str_du = s21_atoi_new(param);
    }
    else if (param->length == 'l') {
        param->va_int = s21_to_binary(param);
        //str_du = s21_atoi(param);
        str_du = s21_atoi_new(param);
    }
    if (param->flag != '-') {
        for (int j = 0 ; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
    }
    free(str_du);
}

void case_f(char **str, param *param) {
    //char *str_int, *str_float = NULL;
    char *str_int;
    //str_int = s21_atoi(param);
    str_int = s21_atoi_new(param);
    for (int j = 0 ; str_int[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_int[j];
    }
    free(str_int);
    //str_float = s21_atof(param);
    //for (int j = 0 ; str_float[j] != '\0'; j++ ) {
    //    (*str)[param->count++] = str_float[j];
    //}
    //free(str_float);
}

void case_g(char **str, param *param) {
    char *str_int;
    int count = 0;
    if (param->va_f < 0) {
        (*str)[param->count++] = '-';
        param->va_f *= (-1.0);
    }
    if (param->va_f >= pow(10, 6) || ((param->type == 'e' || param->type == 'E') && param->va_f >= 1)) {
        while (param->va_f > 10.0) {
            param->va_f = param->va_f / 1e1;
            count++;
        }
        //printf("VA: %Lf\n", param->va_f);
        str_int = s21_atoi_new(param);
        //printf("STR: %s\n", str_int);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = (param->type == 'g' || param->type == 'e') ? 'e' : 'E';
        (*str)[param->count++] = '+';
        (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else if (param->va_f < pow(10, -4) || ((param->type == 'e' || param->type == 'E') && param->va_f < 1)) {
        while (param->va_f < 1.0) {
            param->va_f = param->va_f * 1e1;
            count++;
        }
        str_int = s21_atoi_new(param);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = (param->type == 'g' || param->type == 'e') ? 'e' : 'E';
        (*str)[param->count++] = '-';
        (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else {
        if (param->va_f < 10.0) param->g = 2;
        else if (param->va_f < 100.0) param->g = 3;
        else if (param->va_f < 1000.0) param->g = 4;
        else if (param->va_f < 10000.0) param->g = 5;
        else if (param->va_f < 100000.0) param->g = 6;
        else param->g = 7;
        str_int = s21_atoi_new(param);
        for (int j = 0 ; str_int[j] != '\0'; j++ ) {
            //if (j == param->g) (*str)[param->count++] = '.';
            (*str)[param->count++] = str_int[j];
        }
    }
}

void case_s(char **str, char *str_d, param *param) {
    param->width = (param->width > s21_strlen(str_d)) ? param->width - s21_strlen(str_d) : 0;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || param->width > 0)
        s21_alignment(&str, param);
    if (param->flag != '-')
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
}

void case_x(char **str, param *param) {
    int count = 0, count_revers = 0, plus = 0;
    long long int x;
    char *str_x;
    str_x = calloc(1024 + 1, sizeof(char));
    while (param->va_int >= 0) {
        x = param->va_int % 16;
        param->va_int /= 16;
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
                    str_x[count++] = (param->type == 'x') ? 'd' : 'd';
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
    if (param->va_int != 0) str_x[count++] = '0' + (param->va_int % 10);
    str_x[count] = '\0';
    for (int i = count - 1; i >= 0; i--) {
        (*str)[param->count++] = str_x[i];
    }
    // for -
    char *binary_str_revers, *binary_str;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    if (param->va_int < 0) {
        param->va_int *= -1;
        while (param->va_int > 0) {
            binary_str_revers[count_revers++] = (param->va_int % 2 == 0) ? '0' : '1';
            param->va_int /= 2;
        }
        printf("STR: %d\n", count);
        count = 0;
        for (int i = count_revers - 1; i >= 0; i--)
            binary_str[count++] = binary_str_revers[i];
        printf("STR: %s\n", binary_str);
        //count /= 4;
        //if (binary_str[count - 1] == '1') {
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
        printf("STR: %s\n", binary_str);
    }

    free(str_x);
}