#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Gia tri n khong hop le.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Nhap vi tri muon xoa (0 -> %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("Vi tri khong hop le.\n");
        free(arr);
        return 1;
    }

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
