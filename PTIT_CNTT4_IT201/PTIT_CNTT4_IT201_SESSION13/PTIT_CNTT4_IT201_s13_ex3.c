#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct isStack
{
    int top;
    int max;
    int stack[];
} stack;

stack *creatStack(int data)
{
    stack *newstack = (stack *)malloc(data * sizeof(int) + sizeof(stack));
    if (!newstack)
    {
        printf("cấp phát bộ hớ thất bại.\n");
        return NULL;
    }
    newstack->max = data;
    newstack->top = -1;
    return newstack;
}

bool empty(stack *st)
{
    return st->top == -1;
}

bool full(stack *st)
{
    return st->top == st->max - 1;
}

void push(int x, stack *st)
{
    if (full(st))
    {
        printf("stack_full.\n");
        return;
    }

    st->top += 1;
    st->stack[st->top] = x;
}

int pop(stack *st)
{
    if (empty(st))
    {
        return -1;
    }
    int t = st->top;
    st->top -= 1;
    return st->stack[t];
}

int main()
{
    stack *t = creatStack(10);
    push(10, t);
    printf("%d", pop(t));
    printf("%d", pop(t));
    free(t);
    return 0;
}