#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("%d", max);
    free(arr);
    return 0;
}