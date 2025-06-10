#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_sprintf.h"

START_TEST(test_1)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "NUMBER 01: %c TEST", 'D'), sprintf(str2, "NUMBER 01: %c TEST", 'D'));
    ck_assert_str_eq(str1, str2);
    //printf("NUMBER 01: %%c TEST:     %s\n", str);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_2)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 02: %s TEST", "KARAMBA"), 
    sprintf(str2, "NUMBER 02: %s TEST", "KARAMBA"));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 02: %%s TEST:     %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_3)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 03: %d TEST", 123456789), 
    sprintf(str2, "NUMBER 03: %d TEST", 123456789));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 03: %%d TEST:     %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_4)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 04: %f TEST", 85.95654), 
    sprintf(str2, "NUMBER 04: %f TEST", 85.95654));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 04: %%f TEST:     %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_5)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 05: %20d TEST", 63546546), 
    sprintf(str2, "NUMBER 05: %20d TEST", 63546546));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 05: %%20d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_6)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 06: %+20d TEST", 644), 
    sprintf(str2, "NUMBER 06: %+20d TEST", 644));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 06: %%+20d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_7)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 07: %-20d TEST", -5000), 
    sprintf(str2, "NUMBER 07: %-20d TEST", -5000));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 07: %%-20d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_8)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 08: %.20d TEST", 473436), 
    sprintf(str2, "NUMBER 08: %.20d TEST", 473436));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 08: %%.20d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_9)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 09: % d TEST", 12345), 
    sprintf(str2, "NUMBER 09: % d TEST", 12345));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 09: %% d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_10)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 10: %09d TEST", 12345), 
    sprintf(str2, "NUMBER 10: %09d TEST", 12345));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 10: %%09d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_11)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 11: %hd TEST", 12345), 
    sprintf(str2, "NUMBER 11: %hd TEST", 12345));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 11: %%hd TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_12)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 12: %ld TEST", 14665465467), 
    sprintf(str2, "NUMBER 12: %ld TEST", 14665465467));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 12: %%ld TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_13)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 13: %u TEST", -12345), 
    sprintf(str2, "NUMBER 13: %u TEST", -12345));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 13: %%u TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_14)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 14: %-10d TEST", -12345), 
    sprintf(str2, "NUMBER 14: %-10d TEST", -12345));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 14: %%-10d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_15)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 15: %-10c TEST", 'X'), 
    sprintf(str2, "NUMBER 15: %-10c TEST", 'X'));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 15: %%-10c TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_16)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 16: +%5d TEST", 54321), 
    sprintf(str2, "NUMBER 16: +%5d TEST", 54321));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 16: +%%5d TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_17)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 17: %15s TEST", "Hello World!"), 
    sprintf(str2, "NUMBER 17: %15s TEST", "Hello World!"));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 17: %%15s TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_18)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 18: %.3f TEST", 123.456789), 
    sprintf(str2, "NUMBER 18: %.3f TEST", 123.456789));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 18: %%.3f TEST:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_19)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 19: %-10s|%5d|%c|%.2f", "string", 12345, 'Z', 123.456789), 
    sprintf(str2, "NUMBER 19: %-10s|%5d|%c|%.2f", "string", 12345, 'Z', 123.456789));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 19: %%-10s|%%5d|%%c|%%.2f:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_20)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 20: %10hd%10ld", (short)-12345, (long)-1234567890), 
    sprintf(str2, "NUMBER 20: %10hd%10ld", (short)-12345, (long)-1234567890));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 20: %%10hd%%10ld:   %s\n", str);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_21)
{
    printf("##########################################################\n\n\n\n");
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "This is a simple value %d";
    int val = 6;
    ck_assert_int_eq(s21_sprintf(str, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str, str2);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_22)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%5d";
    int val = 63;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_23)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%+12d";
    int val = 473;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_24)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%0*d";
    int val = 123;
    ck_assert_int_eq(s21_sprintf(str1, format, 5, val), sprintf(str2, format, 5, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_25)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_26)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_27)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_28)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_29)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_30)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_31)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_32)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_33)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_34)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681), sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_35)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_36)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-16o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_37)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_38)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-5.51o";
    int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_39)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%o";
    ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_40)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#o";
    int val = 57175;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_41)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%hd";
    short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_42)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%lo";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_43)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%lo, %o, %ho, %.5o, %5.o";
    long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681), sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_44)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%lo";
    long int val = 84518;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_45)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, (unsigned)0));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_46)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_47)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#-10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_48)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.15x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_49)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#-10x%x%X%#x%#X%5.5x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val), sprintf(str2, format, val, val, val, val, val, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_50)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#-5.10x";
    unsigned val = 858158158;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_51)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#x";
    unsigned val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_52)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#x";
    unsigned val = 18571;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_53)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#hx";
    unsigned short val = 12352;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_54)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#lx";
    unsigned long val = 18571757371571;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_55)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#2x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_56)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%#30x";
    unsigned val = 1;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    free(str1);
    free(str2);
}
END_TEST

Suite* make_suite(void)
{
    Suite *s = suite_create("Sprintf tests");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_1);
    tcase_add_test(tc_core, test_2);
    tcase_add_test(tc_core, test_3);
    tcase_add_test(tc_core, test_4);
    tcase_add_test(tc_core, test_5);
    tcase_add_test(tc_core, test_6);
    tcase_add_test(tc_core, test_7);
    tcase_add_test(tc_core, test_8);
    tcase_add_test(tc_core, test_9);
    tcase_add_test(tc_core, test_10);
    tcase_add_test(tc_core, test_11);
    tcase_add_test(tc_core, test_12);
    tcase_add_test(tc_core, test_13);
    tcase_add_test(tc_core, test_14);
    tcase_add_test(tc_core, test_15);
    tcase_add_test(tc_core, test_16);
    tcase_add_test(tc_core, test_17);
    tcase_add_test(tc_core, test_18);
    tcase_add_test(tc_core, test_19);
    tcase_add_test(tc_core, test_20);
    tcase_add_test(tc_core, test_21);
    tcase_add_test(tc_core, test_22);
    tcase_add_test(tc_core, test_23);
    tcase_add_test(tc_core, test_24);
    tcase_add_test(tc_core, test_25);
    tcase_add_test(tc_core, test_26);
    tcase_add_test(tc_core, test_27);
    tcase_add_test(tc_core, test_28);
    tcase_add_test(tc_core, test_29);
    tcase_add_test(tc_core, test_30);
    tcase_add_test(tc_core, test_31);
    tcase_add_test(tc_core, test_32);
    tcase_add_test(tc_core, test_33);
    tcase_add_test(tc_core, test_34);
    tcase_add_test(tc_core, test_35);
    tcase_add_test(tc_core, test_36);
    tcase_add_test(tc_core, test_37);
    tcase_add_test(tc_core, test_38);
    tcase_add_test(tc_core, test_39);
    tcase_add_test(tc_core, test_40);
    tcase_add_test(tc_core, test_41);
    tcase_add_test(tc_core, test_42);
    tcase_add_test(tc_core, test_43);
    tcase_add_test(tc_core, test_44);
    tcase_add_test(tc_core, test_45);
    tcase_add_test(tc_core, test_46);
    tcase_add_test(tc_core, test_47);
    tcase_add_test(tc_core, test_48);
    tcase_add_test(tc_core, test_49);
    tcase_add_test(tc_core, test_50);
    tcase_add_test(tc_core, test_51);
    tcase_add_test(tc_core, test_52);
    tcase_add_test(tc_core, test_53);
    tcase_add_test(tc_core, test_54);
    tcase_add_test(tc_core, test_55);
    tcase_add_test(tc_core, test_56);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite *suite = make_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}