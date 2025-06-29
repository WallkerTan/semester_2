#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("số phần tử không hợp lệ!!");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("số phần tử không hợp lệ!!");
        return 0;
    }
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    for (int i = n; i < n + m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}