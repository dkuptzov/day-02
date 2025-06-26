#include "s21_atoi.h"

#include <math.h>
#include <stdio.h>
#include <stdint.h>
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
            else if (param->accuracy > 0) max = param->accuracy;
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
        //x = s21_atoi_int(str, digit, param->va_f, param);
        x = s21_atoi_float(str, digit, param->va_f, param);
        printf("PAR4: %Lf\n", param->va_f);
        y = (param->va_f < 0) ? param->va_f * -1.0 : param->va_f;
        y -= (long long int)y;
        if (param->flag_dot == 1 && param->accuracy >= 0) max2 = param->accuracy;
        else max2 = max;
        while (count < max) {
            int test = 0;
            y -= (long long int)y;
            while (test++ < max2 - count) y *= 10;
            if (param->type == 'e' || param->type == 'E') {
                if (param->flag_dot != 1 || count == max - 1) y = round(y);
                else if (param->flag_dot != 1) y = round(y);
            }
            else if (param->type == 'f' || param->type == 'g' || param->type == 'G') y = round(y);
            y /= pow(10, max2 - count - 1);
            str[x++] = '0' + ((int)y % 10);
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
    int count = 0;
    long long int x_first = x;
    long long int z;
    if (param->accuracy <= 0 && param->length == 'L' && param->flag_dot == 1) x = round(x);
    if (x > 0) z = (long long int)(x + 0.000001);
    else z = (long long int)(x - 0.000001);
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

int s21_atoi_float(char *str, char *digit, long double x, param *param) {
    float fval;
    uint32_t raw_bits;
    int sign = (raw_bits & ((uint32_t)(1U << 31))) != 0;
    int exponent = ((raw_bits & (uint32_t)(((1U << 8) - 1) << 23)) >> 23) - 127;
    uint32_t mantissa = (raw_bits & (uint32_t)((1U << 23) - 1));

    //Проверка на ноль:
    if(exponent == -127 && mantissa == 0) {
        printf("Число: 0.0\n");
    }
    //Проверка на бесконечность:
    if(exponent == 128 && mantissa == 0) {
        printf("Число: Infinity\n");
    }
    //Проверка на NaN (Not-a-Number):
    if(exponent == 128 && mantissa != 0) {
        printf("Число: NaN\n");
    }

    // Печать результатов
    printf("Знак: %d\n", sign);
    printf("Экспонента: %d\n", exponent);
    printf("Мантисса (в двоичных битах): 0x%x\n", mantissa);

    uint64_t full_mantissa = (1ULL << 23) | mantissa;
    printf("Мантисса (в двоичных битах): 0x%lx\n", full_mantissa);

    char buffer[100];
    int idx = 0;
    if(sign) {
        buffer[idx++] = '-';
    }
    printf("STR0: %s\n", buffer);
    // Первая цифра (1, подразумеваемая единица)
    buffer[idx++] = '1';
    printf("STR1: %s\n", buffer);
    // Добавляем ".0"
    buffer[idx++] = '.';
    printf("STR2: %s\n", buffer);
    int i = 22; // Начало индекса (сначала высшая степень)
    while(i >= 0) {
        buffer[idx++] = '0' + ((full_mantissa >> i) & 1);
        i--;
    }
    printf("STR3: %s\n", buffer);
    // Устанавливаем десятичную точку

    int dec_point_position = exponent + 23; // Позиция десятичной точки
    printf("dec_point_position: %d\n", dec_point_position);
    if(dec_point_position > 0 && dec_point_position < idx) {
        buffer[dec_point_position] = '.';
    }
    buffer[idx] = '\0';
    printf("STR4: %s\n", buffer);

    int start = 0;
    while(start < idx && buffer[start] == '0') {
        start++;
    }
    printf("STR5: %s\n", buffer);
    if(start > 0) {
        for(int k = 0; k < idx - start; k++) {
            buffer[k] = buffer[k + start];
        }
        idx -= start;
    }
    printf("STR6: %s\n", buffer);

    // Завершающая печать
    printf("Final STR: %s\n", buffer);

    double decimal_mantissa = s21_mantissa_to_decimal(full_mantissa);
    printf("RES: %.20f\n", decimal_mantissa);
    double final_number = decimal_mantissa * pow(2.0, exponent);
    printf("RES: %.20f\n", final_number);
    return final_number;
}

double s21_mantissa_to_decimal(uint64_t mantissa) {
    double result = 1.0; // Имплицитная единица мантиссы
    for(int i = 22; i >= 0; i--) {
        result += (((mantissa >> i) & 1) * pow(2.0, -(23 - i)));
        printf("%f\n", result);
    }
    return result;
}

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