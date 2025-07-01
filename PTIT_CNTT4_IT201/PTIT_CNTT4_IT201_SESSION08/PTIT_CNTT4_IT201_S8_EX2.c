#include <stdio.h>

int binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000)
        return 1;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int x;
    scanf("%d", &x);

    int result = binarySearch(a, n, x);

    if (result != -1)
        printf("phan tu vi tri thu %d\n", result + 1);
    else
        printf("Khong ton tai phan tu\n");

    printf("Do phuc tap thoi gian: O(log n)\n");

    return 0;
}
