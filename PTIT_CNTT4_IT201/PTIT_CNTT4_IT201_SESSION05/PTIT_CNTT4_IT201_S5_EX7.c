#include <stdio.h>

void fibonaci(int n, int one, int two, int count) // 0 1 1 2 3 5 8
{
    if (count >= n)
        return;
    printf("%d ", one);
    fibonaci(n, two, one + two, count + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    fibonaci(n, 0, 1, 0);
    return 0;
}