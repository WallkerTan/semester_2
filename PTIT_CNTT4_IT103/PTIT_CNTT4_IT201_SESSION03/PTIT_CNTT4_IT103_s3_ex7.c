#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n <= 0)
    {
        printf("số hàng không hợp lệ");
        return 0;
    }
    if (m <= 0)
    {
        printf("số cột không hợp lệ\n");
        return 0;
    }

    int **arr = (int **)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int *));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int k;
    scanf("%d",&k);
    if (k > n || k < 0)
    {
        printf("so hang khong hop le\n");
        return 0;
    }
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += arr[k][j];
    }
    printf("tổng của mày là : %d\n", sum);
    free(arr);

    return 0;
}
