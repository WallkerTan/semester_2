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
// thêm phần tử vào đầu
Node *addFirstNode(Node *head, int data)
{
    if (head == NULL)
    {
        return creatNode(data);
    }
    Node *newHead = creatNode(data);
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}
// xáo phần tử ở đầu
Node *delFirstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
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

int SizeNode(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        ++cnt;
        temp = temp->next;
    }
    return cnt;
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
    printf("do dai: %d.\n", SizeNode(head));
    printf("them phan tu vao dau: ");
    int s2;
    scanf("%d", &s2);
    head = addFirstNode(head, s2);
    Cout(head);
    printf("xóa đầu.\n");
    head = delFirstNode(head);
    Cout(head);
    return 0;
}