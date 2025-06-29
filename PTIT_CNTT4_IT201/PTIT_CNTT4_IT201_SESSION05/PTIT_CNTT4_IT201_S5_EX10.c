#include <stdio.h>

int maze(int r, int c, int mr, int mc, int br, int bc)
{
    // điều kiện dừng khi đi đến đích
    if (r > mr || c > mc || (r == br && c == bc))
        return 0;
    if (r == mr && c == mc)
        return 1;
    return maze(r + 1, c, mr, mc, br, bc) + maze(r, c + 1, mr, mc, br, bc);
}

int main()
{
    int r, c, br, bc;
    scanf("%d%d", &r, &c, &br, &bc);

    int t = maze(0, 0, r - 1, c - 1, br, bc);
    printf("%d", t);
    return 0;
}