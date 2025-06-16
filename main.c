#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
/*
    FILE *file = NULL;
    file = fopen("ascii.txt", "r");
    while (c != EOF) {
        c = fgetc(file);
        a = s21_sprintf(str, "%c", c);
        a = sprintf(str2, "%c", c);
        //printf("%s\n", str2);
        if (strcmp(str, str2)) printf("TUT\n");
        clear(&str, &str2);
    }
*/

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

    a = s21_sprintf(str, "TEST %o TEST", -9999);
    a = sprintf(str2, "TEST %o TEST", -9999);
    printf("ORG_OOO: %s\n\n", str2);
    clear(&str, &str2);

    char *str_test;
    str_test = calloc(1024 + 1, sizeof(char));
    str_test = "35547546354";

    a = s21_sprintf(str, "TEST %p TEST", str_test);
    a = sprintf(str2, "TEST %p TEST", str_test);
    printf("ORG_PPP: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %#g TEST", 9999.00);
    a = sprintf(str2, "TEST %#g TEST", 9999.00);
    printf("ORG_ #g: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %e TEST", 0.000);
    a = sprintf(str2, "TEST %e TEST", 0.000);
    printf("ORG_  e: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %*c TEST", 5, 't');
    a = sprintf(str2, "TEST %*c TEST", 5, 't');
    printf("ORG_ *c: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %.*e TEST", 2, 5.1234);
    a = sprintf(str2, "TEST %.*e TEST", 2, 5.1234);
    printf("ORG_.*e: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %.3g TEST", 5.1234);
    a = sprintf(str2, "TEST %.3g TEST", 5.1234);
    printf("ORG_.3g: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "TEST %.*g TEST", 3, 5.1234);
    a = sprintf(str2, "TEST %.*g TEST", 3, 5.1234);
    printf("ORG_.*g: %s\n\n", str2);
    clear(&str, &str2);

    char *format1 = "%0*d";
    a = s21_sprintf(str, format1, 5, 123);
    a = sprintf(str2, format1, 5, 123);
    printf("ORG_0*d: %s\n\n", str2);
    clear(&str, &str2);

    char *format2 = "%.0d";
    a = s21_sprintf(str, format2, 0);
    a = sprintf(str2, format2, 0);
    printf("ORG_.0d: %s\n\n", str2);
    clear(&str, &str2);

    char format[] = "%0.*d";;
    a = s21_sprintf(str, format, 5, 3);
    a = sprintf(str2, format, 5, 3);
    printf("ORG_.*d: %s\n\n", str2);
    clear(&str, &str2);

    char format3[] = "%0.*d %d %4.*d %013d %d";
    a = s21_sprintf(str, format3, 5, 3, -10431, 13, 5311, 0, -58181);
    a = sprintf(str2, format3, 5, 3, -10431, 13, 5311, 0, -58181);
    printf("ORG_.*d: %s\n\n", str2);
    clear(&str, &str2);

    char format4[] = "% 5.51u";
    a = s21_sprintf(str, format4, 14140);
    a = sprintf(str2, format4, 14140);
    printf("ORG_.*d: %s\n\n", str2);
    clear(&str, &str2);

    char format5[] = "%lu, %u, %hu, %.5u, %5.u";
    a = s21_sprintf(str, format5, 949149114140, 14, 1441, 14414, 9681);
    a = sprintf(str2, format5, 949149114140, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format6[] = "%15o";
    a = s21_sprintf(str, format6, 14140);
    a = sprintf(str2, format6, 14140);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format7[] = "%-16o X";
    a = s21_sprintf(str, format7, 14140);
    a = sprintf(str2, format7, 14140);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format8[] = "Z %.51o X";
    a = s21_sprintf(str, format8, 14140);
    a = sprintf(str2, format8, 14140);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format9[] = "Z %o X";
    a = s21_sprintf(str, format9, 0);
    a = sprintf(str2, format9, 0);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format11[] = "Z %#o X";
    a = s21_sprintf(str, format11, 57175);
    a = sprintf(str2, format11, 57175);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format10[] = "Z %lo X";
    a = s21_sprintf(str, format10, 949149114140);
    a = sprintf(str2, format10, 949149114140);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format12[] = "Z %#-20x X";
    a = s21_sprintf(str, format12, 858158158);
    a = sprintf(str2, format12, 858158158);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format13[] = "Z %.15x X";
    a = s21_sprintf(str, format13, 858158158);
    a = sprintf(str2, format13, 858158158);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format14[] = "Z %#x X";
    a = s21_sprintf(str, format14, 0);
    a = sprintf(str2, format14, 0);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format15[] = "Z %#lx X";
    a = s21_sprintf(str, format15, 18571757371571);
    a = sprintf(str2, format15, 18571757371571);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format16[] = "Z %#30x X";
    a = s21_sprintf(str, format16, 1);
    a = sprintf(str2, format16, 1);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format17[] = "Z %#-5.10x X";
    a = s21_sprintf(str, format17, 858158158);
    a = sprintf(str2, format17, 858158158);
    printf("ORG_uuu: %s\n\n", str2);
    clear(&str, &str2);

    char format18[] = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    a = s21_sprintf(str, format18, val, 'c', 'a', 'b', 'b');
    a = sprintf(str2, format18, val, 'c', 'a', 'b', 'b');
    printf("ORG_060: %s\n\n", str2);
    clear(&str, &str2);

    char format19[] = "%-5.3c";
    a = s21_sprintf(str, format19, val);
    a = sprintf(str2, format19, val);
    printf("ORG_061: %s\n\n", str2);
    clear(&str, &str2);
    //60 && 61 test.c -> error

    char format20[] = "%15c";
    a = s21_sprintf(str, format20, val);
    a = sprintf(str2, format20, val);
    printf("ORG_062: %s\n\n", str2);
    clear(&str, &str2);

    char format21[] = "%.15s";
    a = s21_sprintf(str, format21, "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE");
    a = sprintf(str2, format21, "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE");
    printf("ORG_063: %s\n\n", str2);
    clear(&str, &str2);

    char format65[] = "%-15.9s";
    a = s21_sprintf(str, format65, "69 IS MY1FAVORITE NUMBER");
    a = sprintf(str2, format65, "69 IS MY1FAVORITE NUMBER");
    printf("ORG_065: %s\n\n", str2);
    clear(&str, &str2);

    //char format117[] = "NUMBER 17: %15s TEST";
    a = s21_sprintf(str, "NUMBER 17: %15s TEST", "Hello World!");
    a = sprintf(str2, "NUMBER 17: %15s TEST", "Hello World!");
    printf("ORG_065: %s\n\n", str2);
    clear(&str, &str2);

    char format69[] = "%15p";
    a = s21_sprintf(str, format69, format69);
    a = sprintf(str2, format69, format69);
    printf("ORG_069: %s\n\n", str2);
    clear(&str, &str2);

    char format71[] = "%15p";
    char *ptr = NULL;
    a = s21_sprintf(str, format71, ptr);
    a = sprintf(str2, format71, ptr);
    printf("ORG_071: %s\n\n", str2);
    clear(&str, &str2);

    long double val74 = 15.35;
    char *format74 = "%20Lf";
    a = s21_sprintf(str, format74, val74);
    a = sprintf(str2, format74, val74);
    printf("ORG_074: %s\n\n", str2);
    clear(&str, &str2);

    long double val77 = -15.35581134;
    char *format77 = "%.14Lf";
    a = s21_sprintf(str, format77, val77);
    a = sprintf(str2, format77, val77);
    printf("ORG_077: %s\n\n", str2);
    clear(&str, &str2);

    long double val78 = 72537572375.1431341;
    char *format78 = "%Lf";
    a = s21_sprintf(str, format78, val78);
    a = sprintf(str2, format78, val78);
    printf("ORG_078: %s\n\n", str2);
    clear(&str, &str2);

    float val80 = 0;
    char *format80 = "% f";
    a = s21_sprintf(str, format80, val80);
    a = sprintf(str2, format80, val80);
    printf("ORG_080: %s\n\n", str2);
    clear(&str, &str2);

    float val81 = 0;
    double val81_1 = 0;
    long double val81_2 = 3515315.153151;
    float val81_3 = 5.5;
    double val81_4 = 9851.51351;
    long double val81_5 = 95919539159.53151351131;
    char *format81 = "% .f %.lf %Lf %f %lf %Lf";
    a = s21_sprintf(str, format81, val81, val81_1, val81_2, val81_3, val81_4, val81_5);
    a = sprintf(str2, format81, val81, val81_1, val81_2, val81_3, val81_4, val81_5);
    printf("ORG_081: %s\n\n", str2);
    clear(&str, &str2);

    long double val82 = 15.35;
    char *format82 = "%.17Le";
    a = s21_sprintf(str, format82, val82);
    a = sprintf(str2, format82, val82);
    printf("ORG_082: %s\n\n", str2);
    clear(&str, &str2);

    long double val83 = 15.35;
    char *format83 = "%.0Le";
    a = s21_sprintf(str, format83, val83);
    a = sprintf(str2, format83, val83);
    printf("ORG_083: %s\n\n", str2);
    clear(&str, &str2);

    long double val001 = 95919539159.53151351131;
    char *format001 = "%Lf";
    a = s21_sprintf(str, format001, val001);
    a = sprintf(str2, format001, val001);
    printf("ORG_001: %s\n\n", str2);
    clear(&str, &str2);

    long double val85 = 0.000000000000000123;
    char *format85 = "%.15Le";
    a = s21_sprintf(str, format85, val85);
    a = sprintf(str2, format85, val85);
    printf("ORG_085: %s\n\n", str2);
    clear(&str, &str2);

    long double val87 = 72537572375.1431341;
    char *format87 = "%Le";
    a = s21_sprintf(str, format87, val87);
    a = sprintf(str2, format87, val87);
    printf("ORG_087: %s\n\n", str2);
    clear(&str, &str2);

    char *format88 = "%015E";
    float val88 = 0;
    a = s21_sprintf(str, format88, val88);
    a = sprintf(str2, format88, val88);
    printf("ORG_088: %s\n\n", str2);
    clear(&str, &str2);

    char *format89 = "%15e";
    float val89 = 0;
    a = s21_sprintf(str, format89, val89);
    a = sprintf(str2, format89, val89);
    printf("ORG_089: %s\n\n", str2);
    clear(&str, &str2);

    char *format90 = "% .0e %.le %Le %e %le %Le";
    float val90 = 0;
    double val901 = 0;
    long double val902 = 3515315.153151;
    float val903 = 5.5;
    double val904 = 0.094913941;
    long double val905 = 95919539159.53151351131;
    a = s21_sprintf(str, format90, val90, val901, val902, val903, val904, val905);
    a = sprintf(str2, format90, val90, val901, val902, val903, val904, val905);
    printf("ORG_090: %s\n\n", str2);
    clear(&str, &str2);

    char *format91 = "%.17LE";
    long double val91 = 4134121;
    a = s21_sprintf(str, format91, val91);
    a = sprintf(str2, format91, val91);
    printf("ORG_091: %s\n\n", str2);
    clear(&str, &str2);
    format91 = "%.17Le";
    val91 = 4134121.1;
    a = s21_sprintf(str, format91, val91);
    a = sprintf(str2, format91, val91);
    printf("ORG_091: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%x", 0);
    a = sprintf(str2, "%x", 0);
    printf("ORG_106: %s\n\n", str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123);
    printf("STR1_134: %d * %s\n", a, str);
    a = sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123);
    printf("STR2_134: %d * %s\n", a, str2);
    clear(&str, &str2);

    a = s21_sprintf(str, "%*.6x", 11, 0);
    printf("STR1_134: %d * %s\n", a, str);
    a = sprintf(str2, "%*.6x", 11, 0);
    printf("STR2_134: %d * %s\n", a, str2);
    clear(&str, &str2);

    printf("=================================================================\n");
    a = s21_sprintf(str, "%*.*X", 13, 5, -419);
    //a = s21_sprintf(str, "%*.*X", 666, 999, 13);
    printf("STR1_134: %d * %s\n", a, str);
    a = sprintf(str2, "%*.*X", 13, 5, -419);
    //a = sprintf(str2, "%*.*X", 666, 999, 13);
    printf("STR2_134: %d * %s\n", a, str2);
    clear(&str, &str2);

    char format160[] = "%8.3c";
    a = s21_sprintf(str, format160, 'a');
    printf("STR1_160: %d * %s\n", a, str);
    a = sprintf(str2, format160, 'a');
    printf("STR2_160: %d * %s\n", a, str2);
    clear(&str, &str2);

    printf("=================================================================\n");
    //char format161[] = "%.0g";
    //double hex161 = 0.123000;
    a = s21_sprintf(str, "%hx", -111111);
    printf("STR1_161: %d * %s\n", a, str);
    a = sprintf(str2, "%hx", -111111);
    printf("STR2_161: %d * %s\n", a, str2);
    clear(&str, &str2);

/*
    long double val191 = 0.4134121;
    //long double val191 = 0.1535;
    int time = 0;
    while (time++ < 10) {
        val191 *= pow(10, 17);
        printf("%d: %Lf\n", time, val191);
        val191 /= pow(10, 16);
        printf("%d: %Lf\n", time, val191);
        val191 -= (long long int)val191;
        printf("%d: %Lf\n", time, val191);
    }
*/

    /*char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681), sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));*/


    //    if (!strcmp(str, str2)) printf("TUT\n");
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
