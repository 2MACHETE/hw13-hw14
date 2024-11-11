#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>
#define MAX_LEN 1000
int main() {
    setlocale(LC_ALL, "RUS");
    char str[MAX_LEN];
    int count = 0;
    printf("Строка: ");
    fgets(str, MAX_LEN, stdin);
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] != '\0' && !isalpha(str[i])) {
            i++;
        }
        int word_len = 0;
        while (str[i] != '\0' && isalpha(str[i])) {
            word_len++;
            i++;
        }
        if (word_len == 2) {
            count++;
        }
    }
    printf("Количество двухбуквенных слов: %d\n", count);
}