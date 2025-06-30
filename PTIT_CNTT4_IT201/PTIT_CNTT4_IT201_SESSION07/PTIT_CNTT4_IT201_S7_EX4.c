#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void outputstr(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c ", str[i]);
    }
    printf("\n");
}

bool isAllLetters(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void swapstr(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort2(char str[], int i) {
    if (str[i] == '\0') return 0;
    for (int j = i + 1; str[j] != '\0'; j++) {
        if (str[j] < str[i]) {
            swapstr(&str[i], &str[j]);
        }
    }
    return bubbleSort2(str, i + 1);
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (!isAllLetters(str)) {
        printf("Chuỗi không hợp lệ! Chỉ được chứa chữ cái.\n");
        return 0;
    }

    printf("Before: ");
    outputstr(str);

    bubbleSort2(str, 0);

    printf("After: ");
    outputstr(str);

    return 0;
}
