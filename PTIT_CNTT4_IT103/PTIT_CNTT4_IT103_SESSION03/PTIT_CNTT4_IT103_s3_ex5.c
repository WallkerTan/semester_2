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

    int **arr = (int **)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int *));
    }

    if (n % 2 == 0)
    {
        printf("không có đường chéo chính.\n");
        return 0;
    }

    if (m % 2 == 0)
    {
        printf("không có đường chéo phụ.\n");
        return 0;
    }

    int t = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i == j)
            {
                t += arr[i][j];
            }
            if (i + j == n - 1)
            {
                k += arr[i][j];
            }
        }
    }
    printf("tong đường chéo chính: %d\n", t);
    printf("tong đường chéo phụ: %d\n", k);
    free(arr);

    return 0;
}