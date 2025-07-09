#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct Stack
{
    int MAXsize;
    int top;
    char *A[];
} Stack;

Stack *creatStack(int MAXsize)
{
    Stack *newstack = (Stack *)malloc(MAXsize * sizeof(char) + sizeof(char));
    if (!newstack)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }

    newstack->MAXsize = MAXsize;
    newstack->top = -1;
    return newstack;
}

bool empty(Stack *st)
{
    return st->top == -1;
}

bool isFull(Stack *st)
{
    return st->top = st->MAXsize - 1;
}

void push(Stack *st, char str[])
{
    if (isFull(st))
    {
        printf("st_Full.\n");
        return;
    }
    st->top += 1;
    st->A[st->top] = str;
}

char pop()

    int main()
{

    return 0;
}