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
// xóa cuối
Node *deleLastNode(Node *head)
{
    Node *head2 = head;
    while (head2->next != NULL)
    {
        head2 = head2->next;
    }
    head2->prev->next = NULL;
    free(head2);
    return head;
}
// in
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
// tìm
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
// độ dài
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
// thêm vào vị trí bất kì
Node *addNode(Node *head, int data, int index)
{
    int n = SizeNode(head);

    if (index <= 0 || index > n + 1)
    {
        printf("Vị trí không hợp lệ.\n");
        return head;
    }

    if (index == 1)
        return addFirstNode(head, data);

    if (index == n + 1)
        return appenNode(head, data);

    Node *temp = head;
    for (int i = 1; i < index - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    Node *newnode = creatNode(data);
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    return head;
}
// xóa bất kì
Node *deleNode(Node *head, int index)
{
    if (head == NULL)
    {
        printf("ds dang rong.\n");
        return NULL;
    }
    int n = SizeNode(head);

    if (index == 1) {
        return delFirstNode(head);
    }
    if (index == n) {
        return deleLastNode(head);
    }

    if (index <= 0 || index > n)
    {
        printf("vi tri khong hop le.\n");
        return head;
    }
    Node *dNode = head;
    for (int i = 1; i < index; i++)
    {
        dNode = dNode->next;
    }
    if (dNode->prev != NULL)
        dNode->prev->next = dNode->next;

    if (dNode->next != NULL)
        dNode->next->prev = dNode->prev;
    free(dNode);
    return head;
}
Node *reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // Hoán đổi prev và next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Di chuyển sang node trước đó (vì đã đảo)
        current = current->prev;
    }

    // temp lúc này trỏ tới node trước NULL, ta cần trả về temp->prev
    if (temp != NULL)
        head = temp->prev;

    return head;
}
Node *changeplace(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *temp = head;
    Node *newhead = NULL;
    while (temp->next != NULL) {
        if (temp!=newhead && temp->next != NULL) {
            int t = temp->data;
            temp->data = temp->next->data;
            temp->next->data = t;
            newhead = temp->next;
        }
        temp = temp->next;
    }
    return head;
}
// cập nhật lại last
Node *getLast(Node *head)
{
    if (head == NULL)
        return NULL;
    while (head->next != NULL)
        head = head->next;
    return head;
}
int main()
{
    Node *head = NULL;
    Node *last = NULL;
    head = appenNode(head, 10);
    head = appenNode(head, 20);
    head = appenNode(head, 30);
    head = appenNode(head, 40);
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
    last = getLast(head);
    Cout(head);
    printf("them phan tu vao cuoi: ");
    int s3;
    scanf("%d", &s3);
    head = appenNode(head, s3);
    last = getLast(head);
    Cout(head);
    printf("xóa đầu.\n");
    head = delFirstNode(head);
    last = getLast(head);
    Cout(head);
    printf("xoa cuoi.\n");
    head = deleLastNode(head);
    last = getLast(head);
    Cout(head);
    printf("them vi tri bat ki: gia trị - vị trí: ");
    int s4, index;
    scanf("%d%d", &s4, &index);
    head = addNode(head, s4, index);
    last = getLast(head);
    Cout(head);
    printf("xoa vi tri bat ki:");
    int index2;
    scanf("%d", &index2);
    head = deleNode(head, index2);
    last = getLast(head);
    Cout(head);
    printf("dao nguoc ds:\n");
    head = reverse(head);
    last = getLast(head);
    Cout(head);
    printf("dao nguoc.\n");
    head = changeplace(head);
    last = getLast(head);
    Cout(head);
    return 0;
}