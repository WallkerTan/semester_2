#include <stdio.h>

#define MAX_size 1000

int main()
{
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int b[MAX_size] = {0};
    int max = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        b[A[i]]++;
        if (b[A[i]] > max)
        {
            max = b[A[i]];
            value = A[i];
        }
    }
    printf("số xuất hiện nhiều nhất: %d : %d lần\n", value, max);
    getchar();
    return 0;
}