#include <stdio.h>
#include <stdlib.h>

int average(int *arr, int *n)
{

    float sumkk = 0;
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
            sumkk += arr[i];
        }
    }
    sumkk = sumkk / count;
    return sumkk;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    float pass = average(arr, &n);
    printf("%.2f", pass);
    free(arr);
    return 0;
}