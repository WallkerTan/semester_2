#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

void *deleSpace(char *str)
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
    int a, b, s;
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int n = getleng(str);
    stack *st = creatStack(20);
    deleSpace(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (isNumber(str[i]))
        {
            push(st, str[i] - '0');
            i++;
            continue;
        }
        switch (str[i])
        {
        case '+':
            a = pop(st);
            b = pop(st);
            s = a + b;
            break;
        case '-':
            a = pop(st);
            b = pop(st);
            s = a - b;
            break;
        case '*':
            a = pop(st);
            b = pop(st);
            s = a * b;
            break;
        case '/':
            a = pop(st);
            b = pop(st);
            if (b == 0)
            {
                printf("lỗi chia cho 0.\n");
                return 0;
            }
            s = a / b;
            break;
        default:
            printf("toán tử không hợp lệ: %c\n", str[i]);
            free(st);
            break;
        }
        push(st, s);
        i++;
    }

    printf("%d", pop(st));
    free(st);
    return 0;
}