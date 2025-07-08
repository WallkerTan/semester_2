#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
    int max;
    int top;
    char A[];
} stack;

stack *creatStack(int max)
{
    stack *newStack = (stack *)malloc(max * sizeof(char) + sizeof(stack));
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

void push(stack *st, char x)
{
    if (full(st))
    {
        printf("stack_Full.\n");
        return;
    }
    st->top += 1;
    st->A[st->top] = x;
}

char pop(stack *st)
{
    if (empty(st))
    {
        return -1;
    }
    char t = st->A[st->top];
    st->top -= 1;
    return t;
}

void deleSpace(char *str)
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

int getleng(char str[])
{
    int i = 0, cnt = 0;
    while (str[i] != '\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}

bool check(char str)
{
    return (str == '(' || str == '{' || str == '[');
}

bool check2(char a, char b)
{
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int main()
{
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    deleSpace(str);
    int n = getleng(str);
    stack *st = creatStack(n);

    for (int i = 0; i < n; i++)
    {
        if (check(str[i]))
        {
            push(st, str[i]);
            continue;
        }

        if (empty(st) || !check2(st->A[st->top], str[i]))
        {
            printf("false\n");
            free(st);
            return 0;
        }

        pop(st);
    }

    if (!empty(st))
    {
        printf("false\n");
    }
    else
    {
        printf("true\n");
    }

    free(st);
    return 0;
}
