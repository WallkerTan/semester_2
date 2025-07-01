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

int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

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

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int a[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Mang ban dau:\n");
    printArray(a, n);

    insertionSort(a, n);

    printf("Mang sau khi sap xep:\n");
    printArray(a, n);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int linearResult = linearSearch(a, n, x);
    int binaryResult = binarySearch(a, n, x);

    if (linearResult != -1)
        printf("Tuyen tinh: Tim thay tai vi tri %d\n", linearResult + 1);
    else
        printf("Tuyen tinh: Khong tim thay\n");

    if (binaryResult != -1)
        printf("Nhi phan: Tim thay tai vi tri %d\n", binaryResult + 1);
    else
        printf("Nhi phan: Khong tim thay\n");

    return 0;
}
