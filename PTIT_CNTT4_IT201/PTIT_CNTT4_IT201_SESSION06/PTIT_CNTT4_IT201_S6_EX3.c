#include <stdio.h>

int sumnum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sumnum(n / 10);
}

int main()
{

    int n;
    scanf("%d", &n);
    int t = sumnum(n);
    printf("%d", t);
    return 0;
}