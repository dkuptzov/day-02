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
    printf("Test001 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test002 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test003 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test004 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test005 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test006 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test007 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test008 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test009 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test010 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test011 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test012 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test013 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test014 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test015 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test016 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test017 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test018 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test019 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test020 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
    free(str);
    free(str2);
}
END_TEST

START_TEST(test_21)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "This is a simple value %d";
    int val = 6;
    ck_assert_int_eq(s21_sprintf(str, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str, str2);
    printf("Test021 --------------\n");
    printf("%s\n", str);
    printf("%s\n", str2);
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
    printf("Test022 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test023 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test024 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test025 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test026 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test027 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test028 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test029 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test030 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test031 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test032 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test033 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test034 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test035 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test036 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test037 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test038 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test039 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test040 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test041 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test042 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test043 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test044 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test045 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test046 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test047 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test048 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test049 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test050 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test051 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test052 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test053 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test054 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test055 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    printf("Test056 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_57)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test057 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_58)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test058 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_59)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test059 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_60)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'), sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
    ck_assert_str_eq(str1, str2);
    printf("Test060 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_61)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test061 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_62)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test062 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_63)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test063 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_64)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15s";
    char *val = "55 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test064 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_65)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%-15.9s";
    char *val = "11 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test066 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_66)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%s";
    char *val =
        "33 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test066 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_67)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%s%s%s%s";
    char *val =
        "44 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3), sprintf(str2, format, val, s1, s2, s3));
    ck_assert_str_eq(str1, str2);
    printf("Test067 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_68)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format, format));
    ck_assert_str_eq(str1, str2);
    printf("Test068 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_69)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format, format));
    ck_assert_str_eq(str1, str2);
    printf("Test069 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_70)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.5p";
    ck_assert_int_eq(s21_sprintf(str1, format, format), sprintf(str2, format, format));
    ck_assert_str_eq(str1, str2);
    printf("Test070 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_71)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%p";
    char *ptr = NULL;
    ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));
    ck_assert_str_eq(str1, str2);
    printf("Test071 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_72)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test072 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_73)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%Lf";
    long double val = 513515.131513515151351;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test073 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_74)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%10Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test074 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_75)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.0Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test075 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_76)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test076 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_77)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.15Lf";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test077 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_78)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.14Lf";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test078 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_79)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%Lf";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test079 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_80)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test080 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_81)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% .0f %.lf %Lf %f %lf %Lf";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 9851.51351;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));
    ck_assert_str_eq(str1, str2);
    printf("Test081 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);    
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_82)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.17Le";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test082 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_83)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.0Le";
    long double val = 15.35;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test083 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_84)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.Le";
    long double val = 15.000009121;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test084 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_85)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.15Le";
    long double val = 0.000000000000000123;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test085 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_86)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.15Le";
    long double val = -15.35581134;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test086 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_87)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%Le";
    long double val = 72537572375.1431341;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test087 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_88)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%015E";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test088 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_89)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%15e";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test089 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_90)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "% .0e %.le %Le %e %le %Le";
    float val = 0;
    double val1 = 0;
    long double val2 = 3515315.153151;
    float val3 = 5.5;
    double val4 = 0.094913941;
    long double val5 = 95919539159.53151351131;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
        sprintf(str2, format, val, val1, val2, val3, val4, val5));
    ck_assert_str_eq(str1, str2);
    printf("Test090 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_91)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    char *format = "%.17LE";
    long double val = 4134121;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
    ck_assert_str_eq(str1, str2);
    printf("Test091 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_92)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));
    ck_assert_str_eq(str1, str2);
    printf("Test092 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_93)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));
    ck_assert_str_eq(str1, str2);
    printf("Test093 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_94)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'), sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));
    ck_assert_str_eq(str1, str2);
    printf("Test094 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_95)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"), sprintf(str2, "%s", "Drop Sega PLS"));
    ck_assert_str_eq(str1, str2);
    printf("Test095 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_96)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
        sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));
    ck_assert_str_eq(str1, str2);
    printf("Test096 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_97)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));
    ck_assert_str_eq(str1, str2);
    printf("Test097 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_98)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100), sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));
    ck_assert_str_eq(str1, str2);
    printf("Test098 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_99)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001), sprintf(str2, "%f", 0.0001));
    ck_assert_str_eq(str1, str2);
    printf("Test099 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_100)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));
    ck_assert_str_eq(str1, str2);
    printf("Test100 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_101)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%u", 100), sprintf(str2, "%u", (unsigned)100));
    ck_assert_str_eq(str1, str2);
    printf("Test101 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_102)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100), sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));
    ck_assert_str_eq(str1, str2);
    printf("Test102 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_103)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));
    ck_assert_str_eq(str1, str2);
    printf("Test103 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_104)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'), sprintf(str2, "%-8c", '\t'));
    ck_assert_str_eq(str1, str2);
    printf("Test104 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_105)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));
    ck_assert_str_eq(str1, str2);
    printf("Test105 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_106)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN), sprintf(str2, "%x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test106 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_107)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test107 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);    
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_108)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX), sprintf(str2, "%x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test108 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_109)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN), sprintf(str2, "%X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test109 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_110)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test110 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_111)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX), sprintf(str2, "%X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test111 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_112)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
    printf("Test112 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_113)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
        sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
    ck_assert_str_eq(str1, str2);
    printf("Test113 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_114)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN), sprintf(str2, "%-3x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test114 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_115)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test115 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_116)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX), sprintf(str2, "%-3x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test116 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_117)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN), sprintf(str2, "%13x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test117 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_118)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test118 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_119)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX), sprintf(str2, "%13x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test119 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_120)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN), sprintf(str2, "%-60X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test120 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_121)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test121 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_122)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX), sprintf(str2, "%-60X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test122 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_123)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN), sprintf(str2, "%7X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test123 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_124)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test124 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_125)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX), sprintf(str2, "%7X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test125 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_126)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
    printf("Test126 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_127)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(
        s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
        sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
    ck_assert_str_eq(str1, str2);
    printf("Test127 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_128)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN), sprintf(str2, "%#x", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test128 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_129)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test129 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_130)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX), sprintf(str2, "%#x", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test130 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_131)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN), sprintf(str2, "%#X", (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test131 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_132)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
    ck_assert_str_eq(str1, str2);
    printf("Test132 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_133)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX), sprintf(str2, "%#X", INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test133 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_134)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535,
                                 -13, -0, 123213123), sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
    printf("Test134 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_135)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535,
                                 -13, -0, 123213123), sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13,
                             -0, 123213123));
    ck_assert_str_eq(str1, str2);
    printf("Test135 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_136)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN), sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test136 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_137)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0), sprintf(str2, "%*x", 11, 0));
    ck_assert_str_eq(str1, str2);
    printf("Test137 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_138)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX), sprintf(str2, "%*x", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test138 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_139)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN), sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
    ck_assert_str_eq(str1, str2);
    printf("Test139 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_140)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0), sprintf(str2, "%*X", 11, 0));
    ck_assert_str_eq(str1, str2);
    printf("Test140 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_141)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX), sprintf(str2, "%*X", 11, INT32_MAX));
    ck_assert_str_eq(str1, str2);
    printf("Test141 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_142)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251), sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
    printf("Test142 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_143)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0,
                                 -1, 199, -123978, 3, -1251), sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                             199, -123978, 3, -1251));
    ck_assert_str_eq(str1, str2);
    printf("Test143 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
    free(str1);
    free(str2);
}
END_TEST

START_TEST(test_144)
{
    char *str1, *str2;
    str1 = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    int a = s21_sprintf(str1, "%*.6x", 11, 0);
    int b = sprintf(str2, "%*.6x", 11, 0);
    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
    printf("Test144 --------------\n");
    printf("%s\n", str1);
    printf("%s\n", str2);
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
    tcase_add_test(tc_core, test_57);
    tcase_add_test(tc_core, test_58);
    tcase_add_test(tc_core, test_59);
    tcase_add_test(tc_core, test_60);
    tcase_add_test(tc_core, test_61);
    tcase_add_test(tc_core, test_62);
    tcase_add_test(tc_core, test_63);
    tcase_add_test(tc_core, test_64);
    tcase_add_test(tc_core, test_65);
    tcase_add_test(tc_core, test_66);
    tcase_add_test(tc_core, test_67);
    tcase_add_test(tc_core, test_68);
    tcase_add_test(tc_core, test_69);
    tcase_add_test(tc_core, test_70);
    tcase_add_test(tc_core, test_71);
    tcase_add_test(tc_core, test_72);
    tcase_add_test(tc_core, test_73);
    tcase_add_test(tc_core, test_74);
    tcase_add_test(tc_core, test_75);
    tcase_add_test(tc_core, test_76);
    tcase_add_test(tc_core, test_77);
    tcase_add_test(tc_core, test_78);
    tcase_add_test(tc_core, test_79);
    tcase_add_test(tc_core, test_80);
    tcase_add_test(tc_core, test_81);
    tcase_add_test(tc_core, test_82);
    tcase_add_test(tc_core, test_83);
    tcase_add_test(tc_core, test_84);
    tcase_add_test(tc_core, test_85);
    tcase_add_test(tc_core, test_86);
    tcase_add_test(tc_core, test_87);
    tcase_add_test(tc_core, test_88);
    tcase_add_test(tc_core, test_89);
    tcase_add_test(tc_core, test_90);
    tcase_add_test(tc_core, test_91);
    tcase_add_test(tc_core, test_92);
    tcase_add_test(tc_core, test_93);
    tcase_add_test(tc_core, test_94);
    tcase_add_test(tc_core, test_95);
    tcase_add_test(tc_core, test_96);
    tcase_add_test(tc_core, test_97);
    tcase_add_test(tc_core, test_98);
    tcase_add_test(tc_core, test_99);
    tcase_add_test(tc_core, test_100);
    tcase_add_test(tc_core, test_101);
    tcase_add_test(tc_core, test_102);
    tcase_add_test(tc_core, test_103);
    tcase_add_test(tc_core, test_104);
    tcase_add_test(tc_core, test_105);
    tcase_add_test(tc_core, test_106);
    tcase_add_test(tc_core, test_107);
    tcase_add_test(tc_core, test_108);
    tcase_add_test(tc_core, test_109);
    tcase_add_test(tc_core, test_110);
    tcase_add_test(tc_core, test_111);
    tcase_add_test(tc_core, test_112);
    tcase_add_test(tc_core, test_113);
    tcase_add_test(tc_core, test_114);
    tcase_add_test(tc_core, test_115);
    tcase_add_test(tc_core, test_116);
    tcase_add_test(tc_core, test_117);
    tcase_add_test(tc_core, test_118);
    tcase_add_test(tc_core, test_119);
    tcase_add_test(tc_core, test_120);
    tcase_add_test(tc_core, test_121);
    tcase_add_test(tc_core, test_122);
    tcase_add_test(tc_core, test_123);
    tcase_add_test(tc_core, test_124);
    tcase_add_test(tc_core, test_125);
    tcase_add_test(tc_core, test_126);
    tcase_add_test(tc_core, test_127);
    tcase_add_test(tc_core, test_128);
    tcase_add_test(tc_core, test_129);
    tcase_add_test(tc_core, test_130);
    tcase_add_test(tc_core, test_131);
    tcase_add_test(tc_core, test_132);
    tcase_add_test(tc_core, test_133);
    tcase_add_test(tc_core, test_134);
    tcase_add_test(tc_core, test_135);
    tcase_add_test(tc_core, test_136);
    tcase_add_test(tc_core, test_137);
    tcase_add_test(tc_core, test_138);
    tcase_add_test(tc_core, test_139);
    tcase_add_test(tc_core, test_140);
    tcase_add_test(tc_core, test_141);
    tcase_add_test(tc_core, test_142);
    tcase_add_test(tc_core, test_143);
    tcase_add_test(tc_core, test_144);

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