#include <stdio.h>
#include <string.h>

#include "sprintf.h"

int main() {
    char str[500], str2[500];
    double y = 85.95654;
    int x = 123456789;
    long int x_long = 14665465467;
    printf("%hu\n", (short int)x);
    int a;
    char *s = "KARAMBA";
    char c = 'D';

    a = s21_sprintf(str, "NUMBER %c TEST", c);
    a = sprintf(str2, "NUMBER %c TEST", c);
    printf("ORG_CCC: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %s TEST", s);
    a = sprintf(str2, "NUMBER %s TEST", s);
    printf("ORG_SSS: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %d TEST", x);
    a = sprintf(str2, "NUMBER %d TEST", x);
    printf("ORG_UDD: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %f TEST", y);
    a = sprintf(str2, "NUMBER %f TEST", y);
    printf("ORG_FFF: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %10d TEST", x);
    a = sprintf(str2, "NUMBER %10d TEST", x);
    printf("ORG_10D: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %+10d TEST", x);
    a = sprintf(str2, "NUMBER %+10d TEST", x);
    printf("ORG_+10: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %-10d TEST", x);
    a = sprintf(str2, "NUMBER %-10d TEST", x);
    printf("ORG_-10: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %.20d TEST", x);
    a = sprintf(str2, "NUMBER %.20d TEST", x);
    printf("ORG_...: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER % d TEST", x);
    a = sprintf(str2, "NUMBER % d TEST", x);
    printf("ORG_   : %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %09d TEST", x);
    a = sprintf(str2, "NUMBER %09d TEST", x);
    printf("ORG_HHH: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %hd TEST", x);
    a = sprintf(str2, "NUMBER %hd TEST", x);
    printf("ORG_HHH: %s\n\n", str2);

    a = s21_sprintf(str, "NUMBER %ld TEST", x_long);
    a = sprintf(str2, "NUMBER %ld TEST", x_long);
    printf("ORG_HHH: %s\n\n", str2);

    x = -12345;
    a = s21_sprintf(str, "NUMBER %-10d TEST", x);
    a = sprintf(str2, "NUMBER %-10d TEST", x);
    printf("ORG_HHH: %s\n\n", str2);

    //a = sprintf(str3, "ERROR %f TEST", y);
    //printf("ERROR_1: %s\n", str3);

    printf("NOT USED: %d\n", a);
    return 0;
}