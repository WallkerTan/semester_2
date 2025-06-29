#include <stdio.h>
#include <ctype.h>
#include <string.h>

int yet(int start, int end, char str[])
{
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;

    return yet(start + 1, end - 1, str);
}

int main()
{
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (yet(0, strlen(str) - 1, str))
    {
        printf("yet\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
