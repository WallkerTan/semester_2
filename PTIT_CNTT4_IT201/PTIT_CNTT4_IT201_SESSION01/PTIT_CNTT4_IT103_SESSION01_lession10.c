#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int found = 0;
int permutation(char *b, char *a, int start, int end)
{
    if (start == end)
    {
        if (strcmp(b,a) == 0)
        {
            found = 1;
            return;
        }
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(&a[start], &a[i]);
            permutation(b, a, start + 1, end);
            swap(&a[start], &a[i]);
        }
    }
}
int main()
{
    char s1[20], s2[20];

    printf("Nhập chuỗi 1: ");
    scanf("%s", s1);

    printf("Nhập chuỗi 2: ");
    scanf("%s", s2);

    int n1 = strlen(s1);
    int n2 = strlen(s2);
    if (n1 != n2)
    {
        found = 0;
        return 0;
    }
    permutation(s1, s2, 0, n2 - 1);

    if (found)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}