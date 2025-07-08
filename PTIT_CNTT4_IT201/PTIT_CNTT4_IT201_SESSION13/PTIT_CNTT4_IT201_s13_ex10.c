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

bool isNumber(char c)
{
    return isdigit(c);
}

int main()
{
    char a, b, c, s[50];
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    deleSpace(str);
    int n = getleng(str);
    stack *num = creatStack(20);
    stack *opt = creatStack(20);
    stack *all = creatStack(100);
    int i = 0;
    while (str[i] != '\0')
    {
        if (isNumber(str[i]))
        {
            push(num, str[i]);
            i++;
            continue;
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            a = pop(num);
            b = pop(num);
            char temp[100];
            sprintf(temp, "(%s %c %s)", b, str[i], a);
            push(num, temp);
            i++;
            continue;
        }
        i++;
    }
    printf("%s", pop(num));
    free(num);
    free(opt);
    return 0;
}