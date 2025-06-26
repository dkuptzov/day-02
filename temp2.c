#include <float.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h> // Включаем math.h для функции modf

// Функция для преобразования long double в строку с заданным количеством цифр после запятой
void ldtoa(long double value, int digits_after_dot, char* buffer) {
    // Разделяем целую и дробную части
    long long integer_part = (long long)value;
    long double fractional_part = value - integer_part;

    // Преобразуем целую часть в строку
    int idx = 0;
    if(integer_part == 0) {
        buffer[idx++] = '0';
    } else {
        do {
            buffer[idx++] = '0' + (integer_part % 10);
            integer_part /= 10;
        } while(integer_part > 0);
    }

    // Переворачиваем строку
    for(int i = 0, j = idx - 1; i < j; i++, j--) {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Добавляем точку
    buffer[idx++] = '.';

    // Преобразуем дробную часть
    for(int i = 0; i < digits_after_dot; i++) {
        long double frac_part;
        long double int_part = modfl(fractional_part * 10.0, &frac_part);
        int digit = (int)int_part;
        buffer[idx++] = '0' + digit;
        fractional_part = frac_part;
    }

    // Завершаем строку
    buffer[idx] = '\0';
}

// Основная функция
int main() {
    long double huge_number = FLT_MAX;
    char buffer[1000];

    // Преобразуем число в строку с точностью до 20 цифр после запятой
    ldtoa(huge_number, 20, buffer);

    // Выводим результат
    printf("HUGE NUMBER AS STRING: %s\n", buffer);
    return 0;
}