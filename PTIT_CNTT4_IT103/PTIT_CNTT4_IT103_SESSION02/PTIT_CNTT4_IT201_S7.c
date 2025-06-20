#include <stdio.h>
#include <stdlib.h>

#define OFFSET 1000
#define MAX_value 2001
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum;
    scanf("%d", &sum);

    int newarr[MAX_value] = {0};
    for (int i = 0; i < n; i++)
    {
        int comp = sum - arr[i];
        int idx = comp + OFFSET;
        if (idx >= 0 && idx <= MAX_value && newarr[idx] != 0)
        {
            printf("vị trí: %d -> %d\nvị trí: %d -> %d\ntong: %d", newarr[idx] - 1, newarr[newarr[idx] - 1], i, newarr[i], sum);
            free(arr);
            return 0;
        }
        newarr[arr[i] + OFFSET] = i + 1;
    }
    printf("Khong tim thay cap nao co tong = %d\n", sum);
    free(arr);
    return 0;
}