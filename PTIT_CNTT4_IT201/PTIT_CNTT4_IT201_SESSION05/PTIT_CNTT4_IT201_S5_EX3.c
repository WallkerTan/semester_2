#include <stdio.h>

int prn(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * prn(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 1)
    {
        int t = prn(n);
        printf("%d", t);
    }
    else
    {
        printf("khong hơp le\n");
    }
    return 0;
}