#include <stdio.h>

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int temp = a[i];
            a[i] = a[minIdx];
            a[minIdx] = temp;
        }
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

    selectionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nDo phuc tap thoi gian: O(n^2)\n");

    return 0;
}
