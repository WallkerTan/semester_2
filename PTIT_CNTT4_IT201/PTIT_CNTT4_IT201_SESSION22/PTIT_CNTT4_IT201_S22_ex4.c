#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int A[n][n], B[n][n], cnt = 0;
    memset(B, 0, sizeof(B));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                if (j > i)
                {
                    cnt++;
                    B[i][j] = 1;
                }
                else
                {
                    if (B[j][i] == 0)
                    {
                        cnt++;
                        B[i][j] = 1;
                    }
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}