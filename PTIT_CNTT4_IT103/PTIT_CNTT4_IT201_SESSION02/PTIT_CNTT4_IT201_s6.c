#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 100)
        return 1;

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int pos, val;
    scanf("%d%d", &pos, &val);
    if (pos >= 0 && pos <= n)
    {
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = val;
        n++;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}
