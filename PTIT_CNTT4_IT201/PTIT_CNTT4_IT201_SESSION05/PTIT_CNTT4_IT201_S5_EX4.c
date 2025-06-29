#include <stdio.h>

int prn(int n, int m)
{
    if (m == n)
    {
        return m;
    }
    return m + prn(n, m - 1);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n >= 0 && n <= m)
    {
        int t = prn(n, m);
        printf("%d", t);
    }
    else
    {
        printf("khong hơp le\n");
    }
    return 0;
}