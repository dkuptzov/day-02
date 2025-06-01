#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s21_sprintf.h"

START_TEST(test_1)
{
    char *str, *str2;
    str = calloc(1024 + 1, sizeof(char));
    str2 = calloc(1024 + 1, sizeof(char));
    ck_assert_int_eq(s21_sprintf(str, "NUMBER 01: %c TEST", 'D'), sprintf(str2, "NUMBER 01: %c TEST", 'D'));
    ck_assert_str_eq(str, str2);
    printf("NUMBER 01: %%c TEST:     %s\n", str);
    free(str);
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