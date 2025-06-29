#include <stdio.h>

int maze(int r, int c, int mr, int mc)
{
    // điều kiện dừng khi đi đến đích
    if (r > mr || c > mc)
        return 0;
    if (r == mr && c == mc)
        return 1;
    return maze(r + 1, c, mr, mc) + maze(r, c + 1, mr, mc);
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int t = maze(0, 0, r - 1, c - 1);
    printf("%d", t);
    return 0;
}