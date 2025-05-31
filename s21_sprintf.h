#ifndef SPRINTF21_H
#define SPRINTF21_H

typedef struct param {
  int count;
  int count_sign;
  int width;
  int accuracy;
  char length;
  char flag;
  char type;
  char c;
  //short int h;
  //long int l;
  //int va_int;
  //long long int va_ll;
  long long int va_int;
  double va_f;
} param;

//char *s21_atoi(param *param);
//char *s21_atof(param *param);
int s21_sprintf(char *str, const char *str_format, ...);
void s21_alignment(char ***str, param *param);
int s21_str_to_number(char *str_sing);
//void case_u(char **str, param *param);
//void case_f(char **str, param *param);
int s21_strlen(char *str_du);
//int s21_to_binary(param *param);

#endif