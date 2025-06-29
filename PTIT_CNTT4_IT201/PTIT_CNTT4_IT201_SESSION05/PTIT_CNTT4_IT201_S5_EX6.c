#include <stdio.h>

int prn(int a[], int index, int n)
{
    if (index == n)
    {
        return a[index];
    }
    return a[index] + prn(a, index + 1, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int t = prn(a, 0, n - 1);
    printf("%d", t);

    return 0;
}