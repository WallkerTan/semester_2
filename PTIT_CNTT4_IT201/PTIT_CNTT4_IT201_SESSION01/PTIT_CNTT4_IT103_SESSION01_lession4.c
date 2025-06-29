#include <stdio.h>

int one(n)
{
    int sum = 0;//O(1)
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int two(n)
{
    int arr[n];// O(n)
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", one(n));getchar();
    printf("%d", two(n));
    return 0;
}