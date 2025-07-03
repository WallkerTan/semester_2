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

void addlastNode(Node *head, int data)
{
    Node *newNode = creatNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printNode(Node *head)
{
    Node *curent = head;
    while (curent != NULL)
    {
        printf("%d ", curent->data);
        curent = curent->next;
    }
    printf("\n");
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
        temp = temp->next;
    }
    return cnt;
}

void deleteNodelast(Node *head)
{
    Node *temp = head;
    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return;
    }
    Node *last = head, *first = NULL;
    while (last->next != NULL)
    {
        first = last;
        last = last->next;
    }
    first->next = NULL;
}

Node *deleteFirstNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    temp = temp->next;
    free(head);
    return temp;
}

Node *deleValueNode(Node *head, int value)
{
    if (head->data == value)
    {
        head = deleteFirstNode(head);
    }
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *A = temp->next;
            temp->next = A->next;
            free(A);
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

Node *delNodeRand(Node *head, int pos)
{
    int n = lenght(head);
    if (pos <= 0 || pos > n)
    {
        printf("khong hop le.\n");
        return;
    }

    Node *first = NULL, *last = head;
    for (int i = 1; i < pos; i++)
    {
        first = last;
        last = last->next;
    }
    first->next = last->next;

    return head;
}

int indexOf(Node *head, int data)
{
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL && temp->data != data)
    {
        cnt++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return -1;
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
    int n;
    printf("giá trị muốn thêm vào cuối: ");
    scanf("%d", &n);
    addlastNode(last, n);
    printNode(head);
    printf("xóa phần tử cuối.\n");
    deleteNodelast(head);
    printNode(head);
    int t = indexOf(head, 20);
    printf("%d\n", t);
    head = deleteFirstNode(head);
    printNode(head);
    head = delNodeRand(head, 2);
    printNode(head);
    int z;
    printf("giá trị muốn xóa: ");
    scanf("%d", &z);
    head = deleValueNode(head, z);
    printNode(head);
    return 0;
}