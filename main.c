#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// Рекурсивна функція для генерації анаграм
void generate(char* word, int* count, int start, int end) {
    SetConsoleOutputCP(1251);
    if (start == end) {
        printf("%s\n", word);
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            // Міняємо місцями символи
            char temp = word[start];
            word[start] = word[i];
            word[i] = temp;

            // Рекурсивно генеруємо анаграми для підрядка
            generate(word, count, start + 1, end);

            // Повертаємо символи на свої місця
            temp = word[start];
            word[start] = word[i];
            word[i] = temp;
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int count = 0;
    int length = strlen(word);
    generate(word, &count, 0, length - 1);

    printf("Кількість анаграм: %d\n", count);

    return 0;
}
