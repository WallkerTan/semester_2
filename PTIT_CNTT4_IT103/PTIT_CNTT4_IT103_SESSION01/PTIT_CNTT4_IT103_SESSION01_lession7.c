#include <stdio.h>
#define maxsize 1000

int main()
{

    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int b[maxsize] = {0};
    for (int i = 0; i < n; i++)
    {
        b[A[i]]++;
        if (b[A[i]] > 1)
        {
            printf("true\n");
            return 0;
        }
    }
    printf("false");
    free(A);
    return 0;
}