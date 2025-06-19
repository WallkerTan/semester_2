#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int greater = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                greater = 0;
                break;
            }
        }
        if (greater)
            printf("%d\n", arr[i]);
    }
    if (n > 0)
        printf("%d\n", arr[n - 1]);

    free(arr);
    return 0;
}
