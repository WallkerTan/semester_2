#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int index;
    int value;
    printf("vị trí: ");
    scanf("%d", &index);
    printf("giá trị: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++)
    {
        if (i == index)
        {
            arr[i] = value;
        }
        printf("%d", arr[i]);
    }
    return 0;
}