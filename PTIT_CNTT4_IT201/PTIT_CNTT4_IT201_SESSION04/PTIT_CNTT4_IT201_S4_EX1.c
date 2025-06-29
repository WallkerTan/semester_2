#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (b[a[i]] == 0)
        {
            b[a[i]] = i;
        }
    }
    int k;
    scanf("%d", &k);
    if (b[k] != 0)
    {
        printf("%d", b[k]);
    }
    else
    {
        printf("khong tim thay\n");
    }
    return 0;
}
