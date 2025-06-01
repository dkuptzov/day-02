#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_sprintf.h"

void clear(char **str, char **str2);

int main() {
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    double y = 85.95654;
    int x = 123456789;
    int a;
    char *s = "KARAMBA";
    char c = 'D';

    a = s21_sprintf(str, "NUMBER %c TEST", c);
    a = sprintf(str2, "NUMBER %c TEST", c);
    printf("ORG_CCC: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %s TEST", s);
    a = sprintf(str2, "NUMBER %s TEST", s);
    printf("ORG_SSS: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %d TEST", x);
    a = sprintf(str2, "NUMBER %d TEST", x);
    printf("ORG_UDD: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %f TEST", y);
    a = sprintf(str2, "NUMBER %f TEST", y);
    printf("ORG_FFF: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %20d TEST", x);
    a = sprintf(str2, "NUMBER %20d TEST", x);
    printf("ORG_10D: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %+20d TEST", x);
    a = sprintf(str2, "NUMBER %+20d TEST", x);
    printf("ORG_+10: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %-20d TEST", x);
    a = sprintf(str2, "NUMBER %-20d TEST", x);
    printf("ORG_-10: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %.20d TEST", x);
    a = sprintf(str2, "NUMBER %.20d TEST", x);
    printf("ORG_...: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER % d TEST", x);
    a = sprintf(str2, "NUMBER % d TEST", x);
    printf("ORG_   : %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %09d TEST", x);
    a = sprintf(str2, "NUMBER %09d TEST", x);
    printf("ORG_ 09: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %hd TEST", x);
    a = sprintf(str2, "NUMBER %hd TEST", x);
    printf("ORG_ HD: %s\n\n", str2);
    clear(&str, &str2);

    long int x_long = 14665465467;
    a = s21_sprintf(str, "NUMBER %ld TEST", x_long);
    a = sprintf(str2, "NUMBER %ld TEST", x_long);
    printf("ORG_ LD: %s\n\n", str2);
    clear(&str, &str2);

    x = -12345;
    a = s21_sprintf(str, "NUMBER %u TEST", x);
    a = sprintf(str2, "NUMBER %u TEST", x);
    printf("ORG_  U: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER %-10d TEST", x);
    a = sprintf(str2, "NUMBER %-10d TEST", x);
    printf("ORG_10D: %s\n\n", str2);
    clear(&str, &str2);

    c = 'X';
    a = s21_sprintf(str, "NUMBER %-10c TEST", c);
    a = sprintf(str2, "NUMBER %-10c TEST", c);
    printf("ORG_10C: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "NUMBER +%5d TEST", x);
    a = sprintf(str2, "NUMBER +%5d TEST", x);
    printf("ORG_ 5D: %s\n\n", str2);
    clear(&str, &str2);

    s = "Hello World!";
    a = s21_sprintf(str, "NUMBER %15s TEST", s);
    a = sprintf(str2, "NUMBER %15s TEST", s);
    printf("ORG_15s: %s\n\n", str2);
    clear(&str, &str2);

    y = 123.456789;
    a = s21_sprintf(str, "NUMBER %.3f TEST", y);
    a = sprintf(str2, "NUMBER %.3f TEST", y);
    printf("ORG_.3F: %s\n\n", str2);
    clear(&str, &str2);

    x = 1234567;
    a = s21_sprintf(str, "NUMBER %010u TEST", x);
    a = sprintf(str2, "NUMBER %010u TEST", x);
    printf("ORG_10U: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "Test: %-10s|%5d|%c|%.2f", "string", 12345, 'Z', 123.456789);
    a = sprintf(str2, "Test: %-10s|%5d|%c|%.2f", "string", 12345, 'Z', 123.456789);
    printf("ORG_|||: %s\n\n", str2);
    clear(&str, &str2);
//
    a = s21_sprintf(str, "%10hd%10ld", (short)-12345, (long)-1234567890);
    a = sprintf(str2, "%10hd%10ld", (short)-12345, (long)-1234567890);
    printf("ORG_1HD: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "Text:\n%d", 12345);
    a = sprintf(str2, "Text:\n%d", 12345);
    printf("ORG_DDD: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "% d % d % d", -123, 456, -789);
    a = sprintf(str2, "% d % d % d", -123, 456, -789);
    printf("ORG_ D : %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%-+10.2f", -123.456789);
    a = sprintf(str2, "%-+10.2f", -123.456789);
    printf("ORG_DDD: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%+-10.2f", -123.456789);
    a = sprintf(str2, "%+-10.2f", -123.456789);
    printf("ORG_DDD: %s\n\n", str2);
    clear(&str, &str2);

    //a = sprintf(str3, "ERROR %f TEST", y);
    //printf("ERROR_1: %s\n", str3);

    printf("NOT USED: %d\n", a);
    return 0;
}

void clear(char **str, char **str2) {
    free(*str);
    free(*str2);
    *str = calloc(1024 + 1, sizeof(char));
    *str2 = calloc(1024 + 1, sizeof(char));
}