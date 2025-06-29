#include <stdio.h>
#include <stdbool.h>

void inputArray(int A[], int B[][2], int n, int *count)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        bool check = false;

        for (int j = 0; j < *count; j++) // sử dụng hai vòng lặp trong truowngg họp xấu nhất count tawnn n nlaanf => o(n2)
        {
            if (A[i] == B[j][0])
            {
                check = true;
                B[j][1]++;
                break;
            }
        }

        if (!check)
        {
            B[*count][0] = A[i];
            B[*count][1] = 1;
            (*count)++;
        }
    }
}

void printfArray(int B[][2], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        printf("%d: %d lần\n", B[i][0], B[i][1]);// o(n)
    }
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    int A[n];    // O(n)
    int B[n][2]; // O(n2)
    inputArray(A, B, n, &count);
    printfArray(B, &count);
    return 0;
}
