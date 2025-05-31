#include "s21_binary.h"

#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long int s21_to_binary(param *param) {
    char *binary_str_revers, *binary_str;
    binary_str_revers = calloc(1024 + 1, sizeof(char));
    binary_str = calloc(1024 + 1, sizeof(char));
    int count = 0, count_revers = 0, do_it = 0, multi = 0, plus = 0;
    long long int x = param->va_int, result = 0;
    if (param->type == 'd' && param->length == 'x') {
        if (x > INT_MAX || x < INT_MIN) do_it = 1;
    } else if (param->type == 'u') {
        if (x > LLONG_MAX || x < LLONG_MIN) do_it = 1;
    } else if (param->length == 'l') {
        if (x > LONG_MAX || x < LONG_MIN) do_it = 1;
    } else if (param->length == 'h')
        if (x > SHRT_MAX || x < SHRT_MIN) do_it = 1;
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
    else result = x;
    free(binary_str);
    free(binary_str_revers);
    return result;
}