#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, m;
    printf("so hang: ");
    scanf("%d", &n);
    printf("so cot: ");
    scanf("%d", &m);
    if (n <= 0)
    {
        printf("so hang khong họp lệ!!!");
        return 0;
    }

    if (m <= 0)
    {
        printf("so cot khong họp lệ!!!");
        return 0;
    }

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max)
                max = arr[i][j];
            if (arr[i][j] < min)
                min = arr[i][j];
        }
    }
    printf("max: %d\n", max);
    printf("min: %d\n", min);
    free(arr);
    return 0;
}