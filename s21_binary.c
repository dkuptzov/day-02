#include "s21_binary.h"

#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long int s21_to_binary(const param *param) {
    char *binary_str_revers, *binary_str;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    int count = 0, count_revers = 0, multi = 0, plus = 0;
    long long int x = param->va_int, result = 0;
    int do_it = s21_do_it(param);
    if (do_it) {
        while (x > 0) {
            binary_str_revers[count_revers++] = (x % 2 == 0) ? '0' : '1';
            x /= 2;
        }
        for (int i = count_revers - 1; i >= 0; i--)
            binary_str[count++] = binary_str_revers[i];
    }
    if (do_it && binary_str[count - 16] == '1') {
        for (int i = count - 1; i >= count - 16; i--) {
            if (binary_str[i] == '1' && i == count - 1)
                result += (pow(2, multi));
            else if (binary_str[i] == '0' && i == count - 1)
                plus = 1;
            else if (binary_str[i] == '1' && plus == 1) {
                result += (pow(2, multi));
                plus = 0;
            }
            else if (binary_str[i] == '0' && plus == 0) result += (pow(2, multi));
            multi++;
        }
        result *= -1;
    }
    else if (do_it) {
        for (int i = count - 1; i >= count - 16; i--) {
            if (binary_str[i] == '1')
                result += (pow(2, multi));
            multi++;
        }
    }
    else result = x;
    free(binary_str);
    free(binary_str_revers);
    return result;
}

long long int s21_type(long long int x, const param *param) {
    if (param->type == 'd' || param->type == 'o' || param->type == 'u' || param->type == 'x' || param->type == 'X') {
        if (param->length == 'h' && param->type == 'o' && (x > SHRT_MAX || x < SHRT_MIN)) x = s21_to_binary2(x, 14, param);
        else if (param->length == 'h' && (x > SHRT_MAX || x < SHRT_MIN)) x = s21_to_binary2(x, 16, param);
        else if (param->length == 'x' && (x > INT_MAX || x < INT_MIN)) x = s21_to_binary2(x, 32, param);
        else if (param->type == 'l' && (x > LONG_MAX || x < LONG_MIN)) x = s21_to_binary2(x, 64, param);
    }
    return x;
}

long long int s21_to_binary2(long long int x, int bit, const param *param) {
    char *binary_str_revers, *binary_str;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    int count = 0, count_revers = 0, multi = 0, plus = 0;
    long long int result = 0;
    while (x > 0) {
        binary_str_revers[count_revers++] = (x % 2 == 0) ? '0' : '1';
        x /= 2;
    }
    for (int i = count_revers - 1; i >= 0; i--)
        binary_str[count++] = binary_str_revers[i];
    while (binary_str[count - bit] == '1' && param->type == 'o') bit++;
    if (binary_str[count - bit] == '1') {
        for (int i = count - 1; i >= count - bit; i--) {
            if (binary_str[i] == '1' && i == count - 1)
                result += (pow(2, multi));
            else if (binary_str[i] == '0' && i == count - 1)
                plus = 1;
            else if (binary_str[i] == '1' && plus == 1) {
                result += (pow(2, multi));
                plus = 0;
            }
            else if (binary_str[i] == '0' && plus == 0) result += (pow(2, multi));
            multi++;
        }
        result *= -1;
    }
    else {
        for (int i = count - 1; i >= count - 16; i--) {
            if (binary_str[i] == '1')
                result += (pow(2, multi));
            multi++;
        }
    }
    free(binary_str);
    free(binary_str_revers);
    return result;
}

int s21_do_it(const param *param) {
    int do_it = 0;
    if (param->type == 'd' && param->length == 'x') {
        if (param->va_int > INT_MAX || param->va_int < INT_MIN) do_it = 1;
    }
    else if (param->type == 'u') {
        if (param->va_int > LLONG_MAX || param->va_int < LLONG_MIN) do_it = 1;
    }
    else if (param->length == 'l') {
        if (param->va_int > LONG_MAX || param->va_int < LONG_MIN) do_it = 1;
    }
    else if (param->length == 'h')
        if (param->va_int > SHRT_MAX || param->va_int < SHRT_MIN) do_it = 1;
    return do_it;
}