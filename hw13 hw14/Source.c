#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#define max 1000  
#define N 123
int main() {
    int a; int b;
    setlocale(LC_ALL, "RUS");
    while (1) {
        printf("1 - hw13, 2 - hw14, 3 - exit: ");
        scanf("%d", &a);
        while (getchar() != '\n');
        switch (a) {
        case 1: hw13(); break;
        case 2: hw14(); break;
        case 3: exit(0);
        default: break;
        }
        printf("Continue? (1 - yes, 2 - no)");
        scanf("%d", &b);
        while (getchar() != '\n');
        if (b == 2) break;
    }
}
int hw13() {
    setlocale(LC_ALL, "RUS");
    char str[max];
    int count = 0;
    printf("Строка: ");
    fgets(str, max, stdin);
    int i = 0;
    while (str[i] != '\0') {
        while (str[i] != '\0' && !iswalpha(str[i])) {
            i++;
        }
        int word = 0;
        while (str[i] != '\0' && iswalpha(str[i])) {
            word++;
            i++;
        }
        if (word == 2) {
            count++;
        }
    }

    printf("Количество двухбуквенных слов: %d\n", count);
    return 0;
}
int hw14() {
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size, a, b;
    printf("Размер массива = ");
    scanf("%d", &size);
    if (size > N) {
        printf("Ошибка");
    }
    full_elements(array, size);
    while (1) {
        puts("1 - напечатать элементы, 2 - удвоить все элементы, 3 - найти индекс минимального");
        scanf("%d", &a);
        switch (a) {
        case 1: put_elements(array, size); break;
        case 2: dblmult_elements(array, size); break;
        case 3: find_min_index(array, size); break;
        default: break;
        }
        printf("\nПродолжить? (2 - нет): ");
        scanf("%d", &b);
        if (b == 2) break;
    }
}
int full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Элемент массива %d = ", i + 1);
        scanf("%lf", &ptr_array[i]);
    }
    puts("");
}
int put_elements(double* ptr_array, int n) {
    printf("Элеменеты массива:\n");
    for (int i = 0; i < n; i++) {
        printf("%.f ", ptr_array[i]);
    }
    puts("");
}
int dblmult_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = ptr_array[i] * 2;
    }
}
int find_min_index(double* ptr_array, int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < ptr_array[min_index]) {
            min_index = i;
        }
    }
    printf("Индекс минимального элемента = %d", min_index + 1);
}
