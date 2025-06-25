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
    int k;
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != k)
        {
            continue;
        }
        int idx = a[i] + ofset;
        if (idx > 0 && idx <= max_index)
        {
            b[idx] = i;
        }
    }

    printf("%d", b[k + ofset]);

    return 0;
}
