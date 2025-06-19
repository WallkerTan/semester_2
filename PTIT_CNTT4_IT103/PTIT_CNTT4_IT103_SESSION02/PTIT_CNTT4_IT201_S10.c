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
        printf("Phan tu %d xuat hien %d lan\n", arr[i], count);
        visited[i] = 1;
    }
    free(arr);
    free(visited);
    return 0;
}
