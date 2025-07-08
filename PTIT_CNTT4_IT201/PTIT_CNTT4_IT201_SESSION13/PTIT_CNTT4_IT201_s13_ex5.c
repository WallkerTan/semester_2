#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int max;
    int top;
    int A[];
} stack;

stack *creatStack(int max)
{
    stack *newStack = (stack *)malloc(max * sizeof(int) + sizeof(stack));
    if (!newStack)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    newStack->max = max;
    newStack->top = -1;
    return newStack;
}

bool empty(stack *st)
{
    return st->top == -1;
}

bool full(stack *st)
{
    return st->top == st->max - 1;
}

void push(stack *st, int x)
{
    if (full(st))
    {
        printf("stack_Full.\n");
        return;
    }
    st->top += 1;
    st->A[st->top] = x;
}

int pop(stack *st)
{
    if (empty(st))
    {
        return -1;
    }
    int t = st->top;
    st->top -= 1;
    return st->A[t];
}

int main()
{
    int n;
    printf("nhap so phan tu.\n");
    scanf("%d", &n);
    int A[n];
    stack *st = creatStack(20);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        push(st, A[i]);
    }
    while (!empty(st))
    {
        printf("%d ", pop(st));
    }

    return 0;
}