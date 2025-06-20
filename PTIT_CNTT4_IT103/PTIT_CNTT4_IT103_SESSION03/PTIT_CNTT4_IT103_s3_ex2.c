#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("so phan tu khong duoc am!!");
        return 0;
    }
    if (n == 0)
    {
        printf("so phan tu phai lon hon khong!!");
        return 0;
    }
    int *arr = (int *)calloc(n, sizeof(int));
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    printf("gia tri lon nhat: %d", max);
    free(arr);
    return 0;
}