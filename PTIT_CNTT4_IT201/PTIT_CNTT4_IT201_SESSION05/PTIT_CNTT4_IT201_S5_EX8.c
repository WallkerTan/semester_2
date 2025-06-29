#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isNumber(char str[50])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int num(char str[], int index)
{
    if (str[index] == '\0')
    {
        return 0;
    }
    return (str[index] - '0') + num(str, index - 1) * 10;
}

int main()
{
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (!isNumber(str))
    {
        printf("khong hop le\n");
        return;
    }
    int t = num(str, strlen(str) - 1);
    printf("%d", t);
    return 0;
}