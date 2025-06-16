#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int permutation(char *b, char *a, int start, int end)
{
    if (start == end)
    {
        if (strcmp(b, a) == 0)
        {
            printf("true\n");
            return 0;
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
        printf("false\n");
        return 0;
    }
    permutation(s1, s2, 0, n2 - 1);
    printf("false\n");
    return 0;
}