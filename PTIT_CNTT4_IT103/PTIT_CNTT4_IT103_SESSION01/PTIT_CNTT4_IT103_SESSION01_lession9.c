#include <stdio.h>
#include <stdlib.h>

void all(int **A, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void diagonal(int **A, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                printf("%d ", A[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **A = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = malloc(m * sizeof(int));
    }

    printf("Nhập ma trận %dx%d:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Toàn bộ ma trận:\n");
    all(A, n, m);

    printf("Đường chéo chính:\n");
    diagonal(A, n, m);

    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);

    return 0;
}
