#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void output(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binaryRecursion(int k, int arr[], int left, int right)
{
    int mid = left + (right - left) / 2;
    if (left > right)
    {
        return -1;
    }
    if (arr[mid] == k)
    {
        return mid;
    }
    if (k < arr[mid])
    {
        return binaryRecursion(k, arr, left, mid - 1);
    }
    else
    {
        return binaryRecursion(k, arr, mid + 1, right);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    output(arr, n);
    int k;
    scanf("%d", &k);
    int left = 0;
    int right = n - 1;
    int z = binaryRecursion(k, arr, left, right);
    if (z == -1)
    {
        printf("khong tim thay\n");
        return 0;
    }
    printf("%d tại %d", k, z);
    free(arr);
    return 0;
}