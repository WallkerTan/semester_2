#include <stdio.h>

void fibolasi(int n, int begin, int end, int count)
{
    if (count < n)
    {
        fibolasi(n, end, begin + end, count + 1);
        return;
    }

    if (end >= 0)
    {
        printf("%d ", end);
        fibolasi(n, end - begin, begin, count - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    fibolasi(n, 0, 1, 2);
    return 0;
}
