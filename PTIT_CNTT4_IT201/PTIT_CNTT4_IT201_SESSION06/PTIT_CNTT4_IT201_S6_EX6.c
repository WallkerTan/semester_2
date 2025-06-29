#include <stdio.h>

int num(int n, int step)
{
    if (step == n - 1 || step >= n)
    {
        return 1;
    }
    else
    {
        return num(n, step + 1) + num(n, step + 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    int t = num(n, 0);
    printf("%d", t);
    return 0;
}