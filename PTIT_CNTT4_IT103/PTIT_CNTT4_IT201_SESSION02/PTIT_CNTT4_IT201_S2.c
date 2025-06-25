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

    printf("nhập số cần đếm: ");
    int t;
    scanf("%d", &t);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == t)
        {
            dem++;
        }
    }
    printf("%d", dem);

    free(arr);
    return 0;
}