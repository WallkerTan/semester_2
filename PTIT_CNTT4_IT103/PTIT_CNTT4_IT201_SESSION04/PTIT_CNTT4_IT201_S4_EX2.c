#include <stdio.h>

#define max_index 10001
#define ofset 5000
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[max_index] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        int idx = a[i] + ofset; // giá trị
        if (idx > 0 && idx < max_index && b[idx] == 0)
        {
            b[idx] = i + 1;
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    printf("%d", b[max + ofset] - 1);
    return 0;
}
