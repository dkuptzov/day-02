#include <float.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Функция для перевода целого числа в бинарную строку
char* to_binary_string(uint32_t n, char* buffer) {
    for (int i = 31; i >= 0; --i) { // Всего 32 бита
        buffer[i] = (n & (1 << (31 - i))) ? '1' : '0';
    }
    buffer[32] = '\0'; // Завершаем строку символом конца строки
    return buffer;
}

int main() {
    float my_float = FLT_MAX; // Число с плавающей точкой

    // Используем объединение для совместного доступа к данным
    union FloatIntRepresentation {
        float f;
        uint32_t i;
    };

    union FloatIntRepresentation repr;
    repr.f = my_float;

    // Берём целое представление
    uint32_t binary_representation = repr.i;

    // Готовим буфер для хранения строкового представления
    char bin_str[33]; // Размер должен вмещать 32 символа плюс завершающий 0

    // Конвертируем в строку
    to_binary_string(binary_representation, bin_str);

    // Печать результата
    printf("Бинарное представление числа %f: %s\n", my_float, bin_str);

    return 0;
}