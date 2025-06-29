#include <stdio.h>

void printfdouble(int n)
{
    int i = 1; //O[1]
    while (i < n)
    {
        printf("%d\n", i);getchar();
        i *= 2;//o(n)
    }
}// =>> o(n)

int main()
{
    int n;
    scanf("%d", &n);
    printfdouble(n);
    return 0;
}