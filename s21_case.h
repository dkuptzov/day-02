#ifndef S21_CASE_H
#define S21_CASE_H

#include "s21_atoi.h"
#include "s21_binary.h"
#include "s21_sprintf.h"

void case_c(char **str, param *param);
void case_g(char **str, param *param);
void case_u(char **str, param *param);
void case_f(char **str, param *param);
void case_x_plus(char **str, param *param);
void case_x_minus(char **str, param *param);
void case_s(char **str, char *str_d, param *param);
void case_o_plus(char **str, param *param);
void case_o_minus(char **str, param *param);

#endif