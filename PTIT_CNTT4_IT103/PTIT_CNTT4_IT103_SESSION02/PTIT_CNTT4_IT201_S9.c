#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxCount = 0, maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
                visited[j] = 1;
            }
        }
        visited[i] = 1;
        if (count > maxCount)
        {
            maxCount = count;
            maxValue = arr[i];
        }
    }

    printf("Phan tu xuat hien nhieu nhat la %d voi %d lan\n", maxValue, maxCount);

    free(arr);
    free(visited);
    return 0;
}
