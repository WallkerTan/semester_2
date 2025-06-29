#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k = n - 1;
    int fount = 0;
    for (int i = 0; i <= k; i++)
    {
        if (a[i] == a[k] && i != k)
        {
            printf("cap doi xung: %d %d\n", a[i], a[k]);
            fount = 1;
        }
        k--;
    }
    if (fount = 0)
    {
        printf("khong doi xung ok chua.\n");
    }
    return 0;
}