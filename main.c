#include <math.h>
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
    printf("ORG_.2F: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%+-10.2f", -123.4000);
    a = sprintf(str2, "%+-10.2f", -123.4000);
    printf("ORG_.2F: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%cz", 65);
    a = sprintf(str2, "%cz", 65);
    printf("ORG_ASC: %s\n\n", str2);
    clear(&str, &str2);
    
    a = s21_sprintf(str, "%g", 9234567.45);
    a = sprintf(str2, "%g", 9234567.45);
    printf("ORG_ggg: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%g", 0.00000000923456789);
    a = sprintf(str2, "%g", 0.00000000923456789);
    printf("ORG_ggg: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %g TEST", -123.45);
    a = sprintf(str2, "TEST %g TEST", -123.45);
    printf("ORG_ggg: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %G TEST", 58457468.5665743);
    a = sprintf(str2, "TEST %G TEST", 58457468.5665743);
    printf("ORG_GGG: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %e TEST", 999.9999);
    a = sprintf(str2, "TEST %e TEST", 999.9999);
    printf("ORG_ .e: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %.2E TEST", 5653.0001);
    a = sprintf(str2, "TEST %.2E TEST", 5653.0001);
    printf("ORG_.2e: %s\n\n", str2);
    clear(&str, &str2);
//все надо проверить на 0 и проверить как работают с макс и мин и как себя ведет оригинал
    a = s21_sprintf(str, "TEST %x TEST", -100);
    a = sprintf(str2, "TEST %x TEST", -100);
    printf("ORG_ xX: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %X TEST", -1999999999);
    a = sprintf(str2, "TEST %X TEST", -1999999999);
    printf("ORG_-xX: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %o TEST", 123557546);
    a = sprintf(str2, "TEST %o TEST", 123557546);
    printf("ORG_OOO: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %o TEST", -100);
    a = sprintf(str2, "TEST %o TEST", -100);
    printf("ORG_OOO: %s\n\n", str2);
    clear(&str, &str2);

/*
    int w = 100;
    while (w >= 1) {
        if (w % 2 == 0) printf("0");
        else printf("1");
        w /= 2; 
    }
    printf("\n");

    long double number = 0.99988;
    int exponent = floor(log10(fabsl(number)));  // Вычисление порядка числа
    double mantissa = number / pow(10, exponent);  // Получаем мантиссу
    printf("%lf *** %d\n", mantissa, exponent);
    number *= 100000.0;
    number = round(number);
    number /= 10000.0;
    printf("%Lf\n", number);
    char x2 = '0' + ((int)number % 10);
    printf("CHAR: %c\n", x2);
    number -= (int)number;
    printf("%Lf\n", number);
    number *= 10000.0;
    number = round(number);
    number /= 1000.0;
    printf("%Lf\n", number);
    x2 = '0' + ((int)number % 10);
    printf("CHAR: %c\n", x2);
    number -= (int)number;
    printf("%Lf\n", number);
    number *= 1000.0;
    number = round(number);
    number /= 100.0;
    printf("%Lf\n", number);
    x2 = '0' + ((int)number % 10);
    printf("CHAR: %c\n", x2);
    number -= (int)number;
    printf("%Lf\n", number);
        number *= 100.0;
    number = round(number);
    number /= 10.0;
    printf("%Lf\n", number);
    x2 = '0' + ((int)number % 10);
    printf("CHAR: %c\n", x2);
    number -= (int)number;
    printf("%Lf\n", number);
        number *= 10.0;
    number = round(number);
    printf("%Lf\n", number);
    x2 = '0' + ((int)number % 10);
    printf("CHAR: %c\n", x2);
    number -= (int)number;
    printf("%Lf\n", number);
*/ 
/* 
    int count = 0;
    while (count < 6) {
        long double temp = mantissa - (long long int)mantissa;
        //printf("%d, %d, %Lf\n", count, max, temp);
        temp *= 10;
        //if (count < 6 - 1) temp = (long long int)temp;
        //else temp = round(temp);
        //str[x++] = '0' + ((long long int)temp % 10);
        int z = (int)temp;
        char x = '0' + (z % 10);
        printf("CHAR: %c\n", x);
        mantissa *= 10;
        mantissa -= (long long int)mantissa;
        count++;
    }
*/
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