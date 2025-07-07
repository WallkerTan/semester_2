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

// độ dài
int getLength(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *last = NULL;
// thêm đầu
Node *addFirstNode(Node *head, int data)
{
    if (head == NULL)
    {
        Node *node = creatNode(data);
        last = node;
        return node;
    }

    Node *node = creatNode(data);
    head->prev = node;
    node->next = head;
    return node;
}
// thêm cuối
Node *addLastNode(Node *head, int data)
{
    if (head == NULL)
    {
        Node *node = creatNode(data);
        head = node;
        last = node;
        return head;
    }
    Node *node = creatNode(data);
    last->next = node;
    node->prev = last;
    last = node;
    return head;
}
// thêm tùm lum
Node *addNode(Node *head, int data, int index)
{
    // ds rông thêm luôn vào đầu
    if (head == NULL || index == 1)
    {
        return addFirstNode(head, data);
    }
    int n = getLength(head);
    // thêm vào cuối
    if (index == n + 1)
    {
        return addLastNode(head, data);
    }
    if (index <= 0 || index > n + 1)
    {
        printf("vị trí vượt ngoài phạm vi.\n");
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    Node *newNode = creatNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}
// xóa đầu
Node *deleFirst(Node *head)
{
    // ko có phần tử
    if (head == NULL)
    {
        last = NULL;
        return NULL;
    }
    // có 1 phần tử
    if (head->next == NULL)
    {
        free(head);
        last == NULL;
        return NULL;
    }
    head->next->prev = NULL;
    free(head);
    return head->next;
}
// xóa cuối
Node *deleLast(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        last = NULL;
        return NULL;
    }
    Node *temp = last;
    last = last->prev;
    last->next = NULL;
    free(temp);
    return head;
}
// xóa tùm lum
Node *deleNode(Node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }

    int n = getLength(head);

    if (index == 1)
    {
        return deleFirst(head);
    }

    if (index == n)
    {
        return deleLast(head);
    }

    if (index <= 0 || index > n)
    {
        printf("index không hợp lệ");
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    Node *newnode = temp;
    if (temp->next != NULL)
        temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(newnode);
    return head;
}
// tìm kiếm
void searchNode(Node *head)
{
    if (head == NULL)
    {
        printf("ds rỗng.n");
        return;
    }
    int n = getLength(head) / 2;
    Node *temp = head;
    int t = 0;
    for (int i = 1; i < n + 1; i++)
    {
        t++;
        temp = temp->next;
    }
    printf("node %d : %d.\n", t, temp->data);
}

// sắp sếp
void bulbleSort(Node *head)
{
    Node *end = last;

    int swapped = 1; // cờ để kiểm tra nếu có hoán đổi

    while (swapped)
    {
        Node *temp = head;
        swapped = 0;
        while (temp != end)
        {
            if (temp->data > temp->next->data)
            {
                int flag = temp->data;
                temp->data = temp->next->data;
                temp->next->data = flag;
                swapped = 1;
            }
            temp = temp->next;
        }
        end = end->prev; // sau mỗi vòng lặp, phần tử lớn nhất đã ở cuối
    }
}
// in
void Cout(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    Node *head = NULL;
    head = addLastNode(head, 10);
    head = addLastNode(head, 20);
    head = addLastNode(head, 30);
    head = addLastNode(head, 40);
    head = addLastNode(head, 50);
    while (1)
    {
        printf("1: In mảng.\n");
        printf("2: thêm đầu.\n");
        printf("3: thêm cuối.\n");
        printf("4: thêm tùm lum.\n");
        printf("5: xóa đầu.\n");
        printf("6: xóa cuối.\n");
        printf("7: xóa tùm lum.\n");
        printf("8: tìm kiếm.\n");
        printf("9: sắp sếp.\n");
        printf("10: thoát.\n");
        int choice,value,idx;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Cout(head);
            break;
        case 2:
            scanf("%d", &value);
            head = addFirstNode(head, value);
            break;
        case 3:
            scanf("%d", &value);
            head = addLastNode(head, value);
            break;
        case 4:
            scanf("%d %d", &idx, &value);
            head = addNode(head, value, idx);
            break;
        case 5:
            head = deleFirst(head);
            break;
        case 6:
            head = deleLast(head);
            break;
        case 7:
            scanf("%d", &idx);
            head = deleNode(head, idx);
            break;
        case 8:
            searchNode(head);
            break;
        case 9:
            bulbleSort(head);
            break;

        default:
            break;
        }
    }

    return 0;
}