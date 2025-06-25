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

    if (m != m)
    {
        printf("không có đường chéo chính.\n");
        printf("không có đường chéo phụ.\n");
        return 0;
    }

    int t = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        t += arr[i][i];
        k += arr[i][n - 1 - i];
    }
    printf("tong đường chéo chính: %d\n", t);
    printf("tong đường chéo phụ: %d\n", k);
    free(arr);

    return 0;
}