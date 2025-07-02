#include <stdio.h>
#include <stdlib.h>

// 1. Khởi tạo cấu trúc cho 1 phần tử trong danh sách liên kết đơn
struct Node
{
    int data;          // Dữ liệu kiểu số nguyên
    struct Node *next; // Con trỏ đến phần tử tiếp theo
};

// 2. Hàm tạo node mới
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm in toàn bộ danh sách
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    // 3. Tạo danh sách liên kết đơn với 5 phần tử bất kỳ
    int values[5] = {12, 7, 34, 21, 9};

    for (int i = 0; i < 5; i++)
    {
        struct Node *newNode = createNode(values[i]);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // In danh sách
    printf("Danh sách liên kết đơn gồm 5 phần tử:\n");
    printList(head);

    return 0;
}
