#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoare(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while (1)
    {
        do
        {
            ++i;
        } while (i <= r && a[i] < pivot);

        do
        {
            --j;
        } while (j >= l && a[j] > pivot);
        if (i >= j)
            return j;
        swap(&a[i], &a[j]);
    }
}

int lomuto(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    i++;
    swap(&a[i], a[r]);
    return i;
}

void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    // int pivot = hoare(a, l, r);
    // quickSort(a, l, pivot);
    int pivot = lomuto(a, l, r);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}