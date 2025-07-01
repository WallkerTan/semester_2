#include <stdio.h>

int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000)
        return 1;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int x;
    scanf("%d", &x);

    int result = linearSearch(a, n, x);

    if (result != -1)
        printf("Tim thay tai vi tri: %d\n", result);
    else
        printf("Khong tim thay\n");

    printf("Do phuc tap thoi gian: O(n)\n");

    return 0;
}
