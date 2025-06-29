#include <stdio.h>

void prn(int n)
{
    if (n == 1)
    {
        printf("%d", n);
        return;
    }
    prn(n - 1);
    printf("%d", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 1)
    {
        prn(n);
    }
    return 0;
}