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

void addlastNode(Node *head,int data) {
    Node *newNode = creatNode(data);
    if (head==NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
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
void deleteNodelast(Node *head) {
    Node *temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    Node *last = head, *first = NULL;
    while (last->next != NULL) {
        first = last;
        last = last->next;
    }
    first->next = NULL;
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
    addlastNode(last,n);
    printNode(head);
    printf("xóa phần tử cuối.\n");
    deleteNodelast(head);
    printNode(head);
    return 0;
}