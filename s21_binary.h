#ifndef S21_BINARY_H
#define S21_BINARY_H

#include "s21_sprintf.h"

long long int s21_to_binary(const param *param);
long long int s21_type(long long int x, const param *param);
long long int s21_to_binary2(long long int x, int bit, const param *param);
int s21_do_it(const param *param);

#endif