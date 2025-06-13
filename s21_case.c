#include "s21_case.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void case_c(char **str, param *param) {
    param->width -= 1;
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-' || (param->flag == '.' && param->width > 0)) {
        (*str)[param->count++] = param->c;
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || param->width > 0) {
        s21_alignment(&str, param);
        (*str)[param->count++] = param->c;
    }
    else (*str)[param->count++] = param->c;
}

//void param_flag_minus(char ***str, char **str_du, param *param) {
//    for (int j = 0; (*str_du)[j] != '\0'; j++)
//        (**str)[param->count++] = (*str_du)[j];
//}

void case_u(char **str, param *param) {
    char *str_du = NULL;
    //printf("TUT\n");
    //str_du = s21_atoi(param);
    str_du = s21_atoi_new(param);
    //printf("STR_DU: %s %c %d %d\n", str_du, param->flag, param->width, param->accuracy);
    param->width = (param->width > s21_strlen(str_du)) ? param->width - s21_strlen(str_du) : -1;
    if (param->flag == ' ' && str_du[0] != '-') (*str)[param->count++] = ' ';
    //printf("STR_DU: %s %c %d %d\n", str_du, param->flag, param->width, param->accuracy);
    //printf("STR2: %s\n", *str);
    if (param->sign == '+' && param->width > 0) param->width--;
    else if (param->sign == '+' && param->accuracy > 0) param->accuracy--;

    if (param->flag == '-') {
        //param_flag_minus(&str, &str_du, param);
        for (int j = 0; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
        s21_alignment(&str, param);
    }
    else if (param->flag == '0') {
        s21_alignment(&str, param);
    }
    //else if (param->flag == '+' || param->width > 0) {
    else if (param->width > 0) {
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
    //printf("STR1: %s\n", *str);
    if (param->sign == '+' && param->va_int > 0) (*str)[param->count++] = '+';
    else if (param->sign == '+'  && param->va_int < 0) (*str)[param->count++] = '-';

    //printf("STR_DU: %s %c %d %d\n", str_du, param->flag, param->width, param->accuracy);
    //if (param->flag != '-' && !(param->flag == '.' && param->width == 0) && 
    //    !(param->flag == '.' && param->accuracy == 0)) {
    if (param->flag != '-' && !(param->flag == '.' && param->width == 0) && 
        !(param->flag == '.' && param->width == -1 && param->accuracy == 0 && param->va_int == 0)) {
        for (int j = 0 ; str_du[j] != '\0'; j++)
            (*str)[param->count++] = str_du[j];
    }
    //printf("STR0: %s\n", *str);
    free(str_du);
}

void case_f(char **str, param *param) {
    //char *str_int, *str_float = NULL;
    char *str_int;
    //str_int = s21_atoi(param);
    str_int = s21_atoi_new(param);
    //printf("str_int: %s\n", str_int);
    //printf("STR: %d %d\n", param->accuracy, param->width);
    param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) : -1;
    if (param->flag == ' ' && str_int[0] != '-') (*str)[param->count++] = ' ';
    //printf("STR1: %s\n", *str);
    if (param->width > 0)
        s21_alignment(&str, param);
    //printf("STR2: %s\n", str_int);
    for (int j = 0 ; str_int[j] != '\0'; j++ ) {
        (*str)[param->count++] = str_int[j];
    }
    //printf("STR3: %s\n", *str);
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
        //printf("1 %c %c\n", param->flag, param->flag2);
        while (param->va_f >= 10.0) {
            param->va_f = param->va_f / 10;
            count++;
        }
        //printf("VA2: %Lf\n", param->va_f);
        str_int = s21_atoi_new(param);
        //printf("VA3: %Lf\n", param->va_f);
        //printf("str_int: %s\n", str_int);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        //printf("STR0: %s\n", *str);
        (*str)[param->count++] = (param->type == 'g' || param->type == 'e') ? 'e' : 'E';
        (*str)[param->count++] = '+';
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
    }
    else if (param->va_f < pow(10, -4) || ((param->type == 'e' || param->type == 'E') && param->va_f < 1)) {
        //printf("2 %c %c\n", param->flag, param->flag2);
        if (param->flag == ' ') (*str)[param->count++] = ' ';
        while (param->va_f < 1.0 && param->va_f != 0) {
            param->va_f = param->va_f * 10;
            count++;
        }
        str_int = s21_atoi_new(param);
        //printf("STR0: %s\n", str_int);
        param->width = (param->width > s21_strlen(str_int)) ? param->width - s21_strlen(str_int) : -1;
        param->width -= 4;
        if (param->flag == '0' || param->width > 0) s21_alignment(&str, param);
        for (int j = 0 ; str_int[j] != '\0'; j++ )
            (*str)[param->count++] = str_int[j];
        (*str)[param->count++] = (param->type == 'g' || param->type == 'e') ? 'e' : 'E';
        (*str)[param->count++] = (param->va_f == 0.0) ? '+' : '-';
        if (count >= 100) (*str)[param->count++] = '0' + ((count / 100) % 10);
        if (count >= 10) (*str)[param->count++] = '0' + ((count / 10) % 10);
        else (*str)[param->count++] = '0';
        (*str)[param->count++] = '0' + (count % 10);
        //printf("STR1: %s\n", *str);
    }
    else {
        //printf("3 %c %c\n", param->flag, param->flag2);
        if (param->va_f < 10.0) param->g = 1;
        else if (param->va_f < 100.0) param->g = 2;
        else if (param->va_f < 1000.0) param->g = 3;
        else if (param->va_f < 10000.0) param->g = 4;
        else if (param->va_f < 100000.0) param->g = 5;
        else param->g = 6;
        str_int = s21_atoi_new(param);
        //printf("STR_INT: %s\n", str_int);
        //printf("STR0: %s\n", *str);
        for (int j = 0 ; str_int[j] != '\0'; j++ ) {
            (*str)[param->count++] = str_int[j];
        }
        //printf("STR1: %s\n", *str);
        //printf("STR2: %s\n", *str);
        //printf("C: %c\n", (*str)[param->count]);
        //printf("C: %c\n", (*str)[--param->count]);
        if (param->flag != '#') {
            param->count--;
            while ((*str)[param->count] == '0') param->count--;
            if ((*str)[param->count] == '.') (*str)[param->count] = '\0';
            param->count++;
        }
        (*str)[param->count] = '\0';
        //printf("STR3: %s\n", *str);
    }
}

void case_s(char **str, char *str_d, param *param) {
    //printf("111 %d %d %c\n", param->width, param->accuracy, param->flag);
    if (param->flag != '.' && param->accuracy == 0)
        param->width = (param->width > s21_strlen(str_d)) ? param->width - s21_strlen(str_d) : 0;
    //printf("222 %d %d %c\n", param->width, param->accuracy, param->flag);
    if (param->flag == ' ') (*str)[param->count++] = ' ';
    if (param->flag == '-') {
        //printf("TUT1\n");
        for (int j = 0 ; str_d[j] != '\0'; j++ )
            (*str)[param->count++] = str_d[j];
        s21_alignment(&str, param);
    }
    else if (param->flag == '0' || param->flag == '+' || (param->width > 0 && param->accuracy == 0)) {
        s21_alignment(&str, param);
        for (int j = 0 ; str_d[j] != '\0'; j++)
            (*str)[param->count++] = str_d[j];
        //printf("TUT2\n");
    }
    else if (param->flag != '-' && param->accuracy == 0)
        for (int j = 0 ; str_d[j] != '\0'; j++) {
            (*str)[param->count++] = str_d[j];
            //printf("TUT3\n");
        }
    else if (param->width >= 0 && param->accuracy >= 0) {
        //param->accuracy = (param->accuracy < s21_strlen(str_d)) ? param->accuracy : s21_strlen(str_d);
        param->width -= param->accuracy;
        //printf("TUT4\n");
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
    //printf("333 %d %d %c\n", param->width, param->accuracy, param->flag);
    //while (param->width-- > 0) (*str)[param->count++] = ' ';
}

void case_x_plus(char **str, param *param) {
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
    //if (param->va_int != 0) str_x[count++] = '0' + (param->va_int % 10);
    str_x[count] = '\0';
    //printf("param->width: %d\n", param->width);
    param->width = (param->width > s21_strlen(str_x)) ? param->width - s21_strlen(str_x) : -1;
    //printf("param->width: %d\n", param->width);
    if ((param->flag == '#' || param->flag2 == '#') && param->va_int != 0) param->width -= 2;
    if (param->width > 0 && param->flag != '-' && param->accuracy == 0) {
        s21_alignment(&str, param);
    }
    else if (param->accuracy > 0) {
        param->accuracy = (param->accuracy > s21_strlen(str_x)) ? param->accuracy - s21_strlen(str_x) : 0;
        //printf("str1: %s\n", *str);
        if ((param->flag == '#' || param->flag2 == '#') && param->va_int != 0) {
            (*str)[param->count++] = '0';
            (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
        }
        //printf("str2: %s\n", *str);
        s21_alignment(&str, param);
        //printf("str3: %s\n", *str);
    }
    if ((param->flag == '#' || param->flag2 == '#') && param->va_int != 0 && param->accuracy == 0) {
        (*str)[param->count++] = '0';
        (*str)[param->count++] = (param->type == 'x') ? 'x' : 'X';
    }
    for (int i = count - 1; i >= 0; i--)
        (*str)[param->count++] = str_x[i];
    if (param->flag == '-')
        s21_alignment(&str, param);
}

void case_x_minus(char **str, param *param) {
    int count = 0, count_revers = 0, plus = 0;
    long long int result;
    char *binary_str_revers, *binary_str, *str_x;
    str_x = calloc(1024 + 1, sizeof(char));
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    param->va_int *= -1;
    while (param->va_int > 0) {
        binary_str_revers[count_revers++] = (param->va_int % 2 == 0) ? '0' : '1';
        param->va_int /= 2;
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
    for (int i = 0; i < count_revers; i++) {
        (*str)[param->count++] = str_x[i];
    }
    free(str_x);
}

void case_o_plus(char **str, param *param) {
    //printf("param->va_int: %lld\n", param->va_int);
    int count = 0;
    char *str_o;
    str_o = calloc(1024 + 1, sizeof(char));
    if (param->va_int == 0) str_o[count++] = '0';
    while (param->va_int > 0) {
        str_o[count++] = '0' + param->va_int % 8;
        param->va_int /= 8;
    }
    //
    param->width = (param->width > s21_strlen(str_o)) ? param->width - s21_strlen(str_o) : -1;
    if (param->flag == '-') {
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
        s21_alignment(&str, param);
    }
    else if (param->width > 0) {
        s21_alignment(&str, param);
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
    }
    else if (param->accuracy > 0) {
        param->accuracy = (param->accuracy > s21_strlen(str_o)) ? param->accuracy - s21_strlen(str_o) : 0;
        s21_alignment(&str, param);
        for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
    }
    //l here
    else for (int i = count - 1; i >= 0; i--) (*str)[param->count++] = str_o[i];
}

void case_o_minus(char **str, param *param) {
    //param->length = 0;
    //(*str)[param->count] = '\0';
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
    for (int i = 0; str_x8[i] != '\0'; i++) (*str)[param->count++] = str_x8[i];
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
    //printf("STR: %s\n", str_d);
    param->length = 0;
    char hex_addr[sizeof(void *) * 2 + 1], hex_addr_2[sizeof(void *) * 2 + 1];
    uintptr_t address = (uintptr_t) str_d;
    int first = 1, count = 2;
    if (str_d != NULL) {
        for(int i = sizeof(void*) * 2 - 1; i >= 0; --i) 
            hex_addr[i] = "0123456789abcdef"[((address >> (i * 4)) & 0xf)];
        hex_addr[sizeof(void *) * 2 + 1] = '\0';
        hex_addr_2[0] = '0';
        hex_addr_2[1] = 'x';
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
    //
    param->width = (param->width > s21_strlen(hex_addr_2)) ? param->width - s21_strlen(hex_addr_2) : -1;
    if (param->width > 0) s21_alignment(&str, param);
    //
    for (int i = 0; i < count; i++) (*str)[param->count++] = hex_addr_2[i];
}