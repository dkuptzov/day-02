#include <float.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

// Маски для работы с частями числа
#define SIGN_MASK ((uint32_t)(1U << 31))
#define EXPONENT_MASK ((uint32_t)(((1U << 8) - 1) << 23))
#define MANTISSA_MASK ((uint32_t)((1U << 23) - 1))

double mantissa_to_decimal(uint64_t mantissa) {
    int pos = 0;
    char buffer[100];
    double result = 1.0; // Имплицитная единица мантиссы
    //for(int i = 22; i >= 0; i--) {
    //    result += (((mantissa >> i) & 1) * pow(2.0, -(23 - i)));
    //    printf("%f\n", ((mantissa >> i) & 1) * pow(2.0, -(23 - i)));
    //}
    for(int i = 22; i >= 0; --i) {
        uint32_t bit_value = (mantissa >> i) & 1;
        buffer[pos++] = '0' + bit_value; // Запись соответствующей цифры
    }
    buffer[pos] = '\0'; // Закрывающий символ конца строки
    printf("STR: %s\n", buffer);
    return result;
}

// Функция для выделения мантиссы и экспоненты
void show_components(float value) {
    union {
        float fval;
        uint32_t raw_bits;
    } u;

    u.fval = value;

    // Извлечём знак, экспоненту и мантиссу
    int sign = (u.raw_bits & SIGN_MASK) != 0;
    int exponent = ((u.raw_bits & EXPONENT_MASK) >> 23) - 127;
    uint32_t mantissa = (u.raw_bits & MANTISSA_MASK);

    //Проверка на ноль:
    if(exponent == -127 && mantissa == 0) {
        printf("Число: 0.0\n");
    }
    //Проверка на бесконечность:
    if(exponent == 128 && mantissa == 0) {
        printf("Число: Infinity\n");
    }
    //Проверка на NaN (Not-a-Number):
    if(exponent == 128 && mantissa != 0) {
        printf("Число: NaN\n");
    }

    // Печать результатов
    printf("Знак: %d\n", sign);
    printf("Экспонента: %d\n", exponent);
    printf("Мантисса (в двоичных битах): 0x%x\n", mantissa);

    uint64_t full_mantissa = (1ULL << 23) | mantissa;
    printf("Мантисса (в двоичных битах): 0x%lx\n", full_mantissa);

    char buffer[100];
    int idx = 0;
    if(sign) {
        buffer[idx++] = '-';
    }
    printf("STR0: %s\n", buffer);
    // Первая цифра (1, подразумеваемая единица)
    buffer[idx++] = '1';
    printf("STR1: %s\n", buffer);
    // Добавляем ".0"
    buffer[idx++] = '.';
    printf("STR2: %s\n", buffer);
    int i = 22; // Начало индекса (сначала высшая степень)
    while(i >= 0) {
        buffer[idx++] = '0' + ((full_mantissa >> i) & 1);
        i--;
    }
    printf("STR3: %s\n", buffer);
    // Устанавливаем десятичную точку

    int dec_point_position = exponent + 23; // Позиция десятичной точки
    printf("dec_point_position: %d\n", dec_point_position);
    if(dec_point_position > 0 && dec_point_position < idx) {
        buffer[dec_point_position] = '.';
    }
    buffer[idx] = '\0';
    printf("STR4: %s\n", buffer);

    int start = 0;
    while(start < idx && buffer[start] == '0') {
        start++;
    }
    printf("STR5: %s\n", buffer);
    if(start > 0) {
        for(int k = 0; k < idx - start; k++) {
            buffer[k] = buffer[k + start];
        }
        idx -= start;
    }
    printf("STR6: %s\n", buffer);

    // Завершающая печать
    printf("Final STR: %s\n", buffer);

    double decimal_mantissa = mantissa_to_decimal(full_mantissa);
    printf("RES: %.20f\n", decimal_mantissa);
    double final_number = decimal_mantissa * pow(2.0, exponent);
    printf("RES: %.20f\n", final_number);
}

int main() {
    float maxFloat = FLT_MAX;
    show_components(maxFloat);
    return 0;
}