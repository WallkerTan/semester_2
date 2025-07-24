#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int A[n], B[n][n];
    memset(B, 0, sizeof(B));
    memset(A, 0, sizeof(A));
    for (int i = 0; i < k; i++)
    {
        int z, t;
        scanf("%d%d", &z, &t);
        if (z >= 0 && z < n && t < n && t >= 0)
        {
            if (B[z][t] == 0)
            {
                A[t]++;
                A[z]++;
                B[z][t] = 1;
                B[t][z] = 1;
            }
        }
    }
    int l;
    printf("nhập đỉnh muốn tìm cạnh kề: ");
    scanf("%d", &l);
    if (l >= 0 && l < n)
        printf("%d", A[l]);

    return 0;
}