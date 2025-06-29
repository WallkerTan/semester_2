#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("so phan tu khong duoc am!!!\n");
        return 0;
    }

    if (n == 0)
    {
        printf("so luong phan tu phai lon hon không!!!");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("so thu %d = ", i + 1);
        scanf("%d", &arr[i]);
    }
    free(arr);
    return 0;
}