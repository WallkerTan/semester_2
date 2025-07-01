#include <stdio.h>

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nDo phuc tap thoi gian: O(n^2)\n");

    return 0;
}
