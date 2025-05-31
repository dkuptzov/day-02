#ifndef SPRINTF21_H
#define SPRINTF21_H

typedef struct param {
  int count;
  int count_sign;
  int width;
  int accuracy;
  char length;
  char flag;
} param;

char *s21_atoi(long long int x);
char *s21_atof(double x);
int s21_sprintf(char *str, const char *str_format, ...);
void s21_alignment(char ***str, param *param);
int s21_str_to_number(char *str_sing);
void case_u(long long int va, char **str, param *param);
void case_f(double va, char **str, param *param);
int s21_strlen(char *str_du);
int s21_to_binary(long long int x);

#endif