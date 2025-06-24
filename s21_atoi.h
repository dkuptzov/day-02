#ifndef S21_ATOI_H
#define S21_ATOI_H

#include "s21_sprintf.h"

char *s21_atoi_new(param *param);
//int s21_atoi_int(char *str, char *digit, long long int x, param *param);
int s21_atoi_int(char *str, char *digit, long double x, param *param);

#endif