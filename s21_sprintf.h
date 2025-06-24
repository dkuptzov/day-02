#include <stdarg.h>

#ifndef SPRINTF21_H
#define SPRINTF21_H

typedef struct param {
  int error;
  int g;
  int count; //счетчик для основной строки
  int count_sign; //счетчик для строки с цифрами
  int width; //ширина
  int accuracy; //точность
  char length; //h, l, L
  char type; //спецификатор
  char c; //храним здесь символ для спецификатор c
  long long int va_int;
  long double va_f;
  int its_float;
  short flag_minus;
  short flag_plus;
  short flag_space;
  short flag_hash;
  short flag_zero;
  short flag_dot;
} param;

int s21_sprintf(char *str, const char *str_format, ...);
void s21_alignment(char ***str, param *param);
int s21_str_to_number(char *str_sing);
int s21_strlen(char *str_du);
void s21_update_param(param *param);
void s21_switch(char c, char *str_ready, va_list args, param *param);

#endif