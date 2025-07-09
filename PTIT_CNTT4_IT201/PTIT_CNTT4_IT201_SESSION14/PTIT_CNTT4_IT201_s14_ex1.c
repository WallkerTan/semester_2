#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Stack
{
    int MaxSize;
    int Top;
    int A[];
} stack;

bool isfull(stack *st)
{
    return st->Top == st->MaxSize - 1;
}

bool empty(stack *st)
{
    return st->Top == -1;
}

void push(stack *st, int data)
{
    if (isfull(st))
    {
        printf("st_full\n");
        return NULL;
    }
    st->Top += 1;
    st->A[st->Top] = data;
}

int pop(stack *st)
{
    if (empty(st))
    {
        printf("stack_rong.\n");
        return -1;
    }
    int t = st->A[st->Top];
    st->Top -= 1;
    return t;
}

stack *creatStack(int data)
{
    stack *newstack = (stack *)malloc(data * sizeof(int) + sizeof(stack));
    if (!newstack)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    newstack->MaxSize = data;
    newstack->Top = -1;
    return newstack;
}

int main()
{
    stack *number = creatStack(20);
    while (1)
    {
        printf("1: them vao stack.\n");
        printf("2. lấy phần tu cuối cùng.\n");
        printf("3. lấy toàn bộ ngăn sếp.\n");
        printf("4. thoát.\n");
        int n, pu, po;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("nhập giá trị thêm: ");
            scanf("%d", &pu);
            push(number, pu);
            break;
        case 2:
            po = pop(number);
            printf("%d", po);
            break;
        case 3:
            while (!empty(number))
            {
                printf("%d ", pop(number));
            }
            break;
        case 4:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}
