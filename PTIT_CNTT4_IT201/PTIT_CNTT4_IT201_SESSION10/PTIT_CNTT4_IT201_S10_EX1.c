#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *creatNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printNode(Node *head)
{
    Node *curent = head;
    while (curent != NULL)
    {
        printf("%d ", curent->data);
        curent = curent->next;
    }
}

Node *appenNode(Node *last, int data)
{
    Node *node = creatNode(data);
    last->next = node;
    return node;
}

int lenght(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        ++cnt;
    }
    return cnt;
}

int main()
{
    Node *head = creatNode(10);
    Node *last = head;
    last = appenNode(last, 20);
    last = appenNode(last, 30);
    last = appenNode(last, 40);
    last = appenNode(last, 50);
    printNode(head);
    return 0;
}