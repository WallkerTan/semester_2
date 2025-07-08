#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct isStack
{
    int max;
    int top;
    int stack[];
} St;

St *Stack(int data)
{
    St *newStack = (St *)malloc(sizeof(St) + data * sizeof(int));
    if (!newStack)
    {
        printf("Cấp phát bộ nhớ thất bại.\n");
        return NULL;
    }

    newStack->max = data;
    newStack->top = -1;
    return newStack;
}

void removeSpace(char *str[])
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main()
{
    St *test = Stack(20);
    if (test != NULL)
    {
        printf("Sức chứa: %d\n", test->max);
        free(test);
    }
    return 0;
}
