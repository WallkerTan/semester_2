#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    char name[30];
    struct Node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} queue;

queue *creatQ()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

Node *creatNode(char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

bool empty(queue *q)
{
    return q->front == NULL;
}

void push(queue *q, char *name)
{
    Node *newNode = creatNode(name);
    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void pop(queue *q)
{
    // ko có phần tử
    if (q->front == NULL)
    {
        printf("ds rỗng.\n");
        return;
    }
    // có 1 phần tử
    Node *temp = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
        free(temp);
        return;
    }
    q->front = q->front->next;
    free(temp);
}

char *front(queue *q)
{
    if (empty(q))
    {
        printf("ds rỗng.\n");
        return NULL;
    }
    return q->front->name;
}
void OUT(queue *q)
{
    Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%s.\n", temp->name);
        temp = temp->next;
    }
}
int main()
{
    queue *queueOld = creatQ();
    queue *queueNormal = creatQ();
    int choice;
    char name[30];

    do
    {
        printf("1. Thêm khách vào hàng đợi>=60\n");
        printf("5. Thêm khách vào hàng đợi<60\n");
        printf("2. Phục vụ khách\n");
        printf("3. Hiển thị danh sách khách đang chờ\n");
        printf("4. Thoát chương trình\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Nhập tên khách hàng:>=60 ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            push(queueOld, name);
            printf("Đã thêm %s vào hàng đợi.\n", name);
            break;

        case 2:
            if (!empty(queueOld))
            {
                printf("Phục vụ khách: %s\n", front(queueOld));
                pop(queueOld);
            }
            else if (!empty(queueNormal))
            {
                printf("Phục vụ khách: %s\n", front(queueNormal));
                pop(queueNormal);
            }
            else
            {
                printf("khong co khach.\n");
            }
            break;

        case 3:
            printf("Danh sách khách đang chờ:>60\n");
            if (empty(queueOld))
                printf(">60 ko có ai.\n");
            else
                OUT(queueOld);
            if (empty(queueNormal))
                printf("<60 không có ai.\n");
            else
                OUT(queueNormal);
            break;

        case 4:
            printf("Thoát chương trình.\n");
            break;
        case 5:
            printf("Nhập tên khách hàng:<60 ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            push(queueNormal, name);
            printf("Đã thêm %s vào hàng đợi.\n", name);
            break;

        default:
            printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }

    } while (choice != 4);

    // Giải phóng bộ nhớ queue
    while (!empty(queueOld))
        pop(queueOld);
    free(queueOld);
    // Giải phóng bộ nhớ queue
    while (!empty(queueNormal))
        pop(queueNormal);
    free(queueNormal);

    return 0;
}
