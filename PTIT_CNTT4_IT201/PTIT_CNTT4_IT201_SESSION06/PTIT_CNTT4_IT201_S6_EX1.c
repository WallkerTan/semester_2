#include <stdio.h>

int bilary(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 2 + 10 * bilary(n / 2);
}

int main()
{

    int n;
    scanf("%d", &n);
    int t = bilary(n);
    printf("%d", t);
    return 0;
}