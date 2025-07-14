#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} queue;

// khoi tao hang doi
queue *creatQ()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// khoi tao một node mới
Node *creatNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("cap phat thất bại");
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

bool empty(queue *q)
{
    return q->front == NULL;
}

// thê phần tử
void push(queue *q, int data)
{
    // khi rỗng
    Node *newnode = creatNode(data);
    if (empty(q))
    {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

int front(queue *q)
{
    return q->front->data;
}

void pop(queue *q)
{
    // khi ko có phần tử
    if (empty(q))
    {
        printf("queue rỗng.\n");
        return;
    }
    // chỉ có một phần tử
    Node *temp = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
        free(temp);
        return;
    }
    q->front = q->front->next;
    free(temp);
}

void OUT(queue *q)
{
    Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] == 1)
        {
            continue;
        }
        else
        {
            printf("false.\n");
            return 0;
        }
    }
    printf("true.\n");
    return 0;
}