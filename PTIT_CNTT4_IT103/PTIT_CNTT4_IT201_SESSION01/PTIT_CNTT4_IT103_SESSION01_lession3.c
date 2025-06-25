#include <stdio.h>

int *mallocArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) // mảng => O(n)
    {
        arr[i] = i;
    }
    return arr;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = mallocArray(n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    free(a);
    return 0;
}