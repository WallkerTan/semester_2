#include <stdio.h>
#include <ctype.h>
#include <string.h>

int yet(int start, int end, char str[])
{
    if (str[start] != str[end])
    {
        return 0;
    }

    if (str[start] == str[end] || start >= end)
    {
        return 1;
    }

    return yet(start + 1, end - 1, str);
}
int main()
{
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    getchar();
    if (yet(0, strlen(str) - 1, str) != 0)
    {
        printf("yet\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}