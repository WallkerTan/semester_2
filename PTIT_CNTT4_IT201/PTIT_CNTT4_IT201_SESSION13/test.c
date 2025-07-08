#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct stack
{
    int max;
    int top;
    char A[][100]; // mỗi phần tử là chuỗi, dùng để lưu chuỗi biểu thức con
} stack;

stack *creatStack(int max)
{
    stack *newStack = (stack *)malloc(sizeof(stack) + max * sizeof(newStack->A[0]));
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

void push(stack *st, const char *x)
{
    if (full(st))
    {
        printf("stack_Full.\n");
        return;
    }
    st->top += 1;
    strcpy(st->A[st->top], x);
}

char *pop(stack *st)
{
    if (empty(st))
    {
        return NULL;
    }
    return st->A[st->top--];
}

bool isBracketLeft(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isBracketRight(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool isMatching(char a, char b)
{
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    stack *num = creatStack(100);     // lưu toán hạng dưới dạng chuỗi
    stack *op = creatStack(100);      // lưu toán tử
    stack *bracket = creatStack(100); // lưu dấu ngoặc

    int i = 0;
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            i++;
            continue;
        }

        if (isdigit(str[i]))
        {
            char temp[100];
            sprintf(temp, "%c", str[i]);
            push(num, temp);
            i++;
            continue;
        }

        if (isBracketLeft(str[i]))
        {
            char temp[2] = {str[i], '\0'};
            push(bracket, temp);
            i++;
            continue;
        }

        if (isOperator(str[i]))
        {
            char temp[2] = {str[i], '\0'};
            push(op, temp);
            i++;
            continue;
        }

        if (isBracketRight(str[i]))
        {
            if (empty(bracket) || !isMatching(bracket->A[bracket->top][0], str[i]))
            {
                printf("lỗi biểu thức.\n");
                return 0;
            }

            char b[100], a[100], o[100], r[100];
            strcpy(b, pop(num));
            strcpy(a, pop(num));
            strcpy(o, pop(op));
            pop(bracket);

            sprintf(r, "(%s%s%s)", a, o, b);
            push(num, r);
            i++;
            continue;
        }

        printf("ký tự không hợp lệ: %c\n", str[i]);
        return 0;
    }

    if (!empty(bracket))
    {
        printf("lỗi biểu thức.\n");
        return 0;
    }

    printf("Biểu thức kết quả: %s\n", pop(num));

    free(num);
    free(op);
    free(bracket);
    return 0;
}
