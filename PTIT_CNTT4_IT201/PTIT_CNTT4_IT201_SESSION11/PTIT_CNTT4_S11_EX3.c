#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *creatNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
// thêm phần tử vào cuối
Node *appenNode(Node *head, int data)
{
    if (head == NULL)
    {
        return creatNode(data);
    }
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    Node *newNode = creatNode(data);
    last->next = newNode;
    newNode->prev = last;
    return head;
}

void Cout(Node *head)
{
    Node *temp = head;
    if (head->prev == NULL)
    {
        printf("NULL<--");
    }
    while (temp != NULL)
    {
        printf(temp->next != NULL ? "%d<-->" : "%d-->NULL", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void shearch(Node *head, int value)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("true\n");
            return;
        }
        temp = temp->next;
    }
    printf("false\n");
}

int main()
{
    Node *head = NULL;
    Node *last = NULL;
    head = appenNode(head, 10);
    head = appenNode(head, 10);
    head = appenNode(head, 10);
    head = appenNode(head, 10);
    Cout(head);
    printf("tim kiem: ");
    int s1;
    scanf("%d", &s1);
    shearch(head, s1);
    return 0;
}