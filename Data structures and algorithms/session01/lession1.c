#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        printf("hello\n");
    }
    //O[n]
    return 0;
}