#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Tạo node mới
Node *creatNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Thêm node vào cuối danh sách, trả về head mới nếu cần
Node *addlastNode(Node *head, int data)
{
    Node *newNode = creatNode(data);
    if (head == NULL)
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// In danh sách
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

// Tính độ dài danh sách
int length(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Xóa node cuối
Node *deleteNodelast(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Xóa node đầu
Node *deleteFirstNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Xóa node theo giá trị
Node *deleValueNode(Node *head, int value)
{
    while (head != NULL && head->data == value)
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

// Xóa node ở vị trí bất kỳ (1-based)
Node *delNodeRand(Node *head, int pos)
{
    int n = length(head);
    if (pos <= 0 || pos > n)
    {
        printf("Vị trí không hợp lệ.\n");
        return head;
    }

    if (pos == 1)
        return deleteFirstNode(head);

    Node *prev = head;
    for (int i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
    }

    Node *toDelete = prev->next;
    prev->next = toDelete->next;
    free(toDelete);

    return head;
}

// Tìm vị trí đầu tiên của giá trị
int indexOf(Node *head, int data)
{
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
            return cnt;
        cnt++;
        temp = temp->next;
    }
    return -1;
}

// In phần tử giữa (lấy node giữa bên phải nếu chẵn)
void midNode(Node *head)
{
    int n = length(head);
    int mid = n / 2;

    Node *temp = head;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    printf("Node %d: %d\n", mid + 1, temp->data);
}

// Sắp xếp danh sách tăng dần (bubble sort)
void sortNode(Node *head)
{
    if (head == NULL)
        return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// MAIN
int main()
{
    Node *head = NULL;
    head = addlastNode(head, 10);
    head = addlastNode(head, 20);
    head = addlastNode(head, 30);
    head = addlastNode(head, 20);
    head = addlastNode(head, 30);
    head = addlastNode(head, 20);
    head = addlastNode(head, 30);
    head = addlastNode(head, 40);
    head = addlastNode(head, 50);

    int n;
    printf("Giá trị muốn thêm vào cuối: ");
    scanf("%d", &n);
    head = addlastNode(head, n);

    printf("Danh sách sau khi thêm:\n");
    printNode(head);

    printf("Xóa phần tử cuối:\n");
    head = deleteNodelast(head);
    printNode(head);

    int t = indexOf(head, 20);
    printf("Vị trí của giá trị 20: %d\n", t);

    printf("Xóa node đầu:\n");
    head = deleteFirstNode(head);
    printNode(head);

    printf("Xóa node tại vị trí 2:\n");
    head = delNodeRand(head, 2);
    printNode(head);

    int z;
    printf("Giá trị muốn xóa khỏi danh sách: ");
    scanf("%d", &z);
    head = deleValueNode(head, z);
    printNode(head);

    printf("Phần tử giữa danh sách:\n");
    midNode(head);

    printf("Danh sách sau khi sắp xếp:\n");
    sortNode(head);
    printNode(head);

    return 0;
}
