#include <stdio.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *creatNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *appendNode(Node *last, int datta)
{
    Node *node = creatNode(datta);
    last->next = node;
    last = node;
    return node;
}

void printNodeList(Node *head)
{
    Node *curent = head;
    while (curent != NULL)
    {
        printf("%d ", curent->data);
        curent = curent->next;
    }
    printf("\n");
}

int main()
{
    Node *head = creatNode(10);
    Node *last = head;

    return 0;
}