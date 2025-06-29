#include <stdio.h>

void fibolasi(int n, int begin, int end, int count)
{
    if (count > n)
        return;

    fibolasi(n, end, end + begin, count + 1);
    printf("%d ", end);
}

int main()
{
    int n;
    scanf("%d", &n);
    fibolasi(n, 0, 1, 1);
    return 0;
}
