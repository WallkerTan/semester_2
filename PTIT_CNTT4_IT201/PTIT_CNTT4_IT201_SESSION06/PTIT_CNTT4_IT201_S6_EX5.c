#include <stdio.h>
#include <stdlib.h>

void maxmin(int *max, int *min, int Arr[], int n, int index)
{
    if (index == n)
        return;
    if (Arr[index] > *max)
    {
        *max = Arr[index];
    }
    else if (Arr[index] < *min)
    {
        *min = Arr[index];
    }
    maxmin(max, min, Arr, n, index + 1);
}

int main()
{

    int n;
    scanf("%d", &n);
    int *Arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    int max = Arr[0];
    int min = Arr[0];
    maxmin(&max, &min, Arr, n, 1);
    printf("max: %d\nmin: %d\n", max, min);
    free(Arr);
    return 0;
}