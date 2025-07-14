#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
} queue;

// Khởi tạo hàng đợi
queue *createQ()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
    {
        printf("Cấp phát thất bại.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// Tạo một node mới
Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("Cấp phát thất bại\n");
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

bool empty(queue *q)
{
    return q->front == NULL;
}

// Thêm phần tử vào hàng đợi
void push(queue *q, int data)
{
    Node *newnode = createNode(data);
    if (!newnode)
        return; // Nếu không cấp phát được node mới

    if (empty(q))
    {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

// Lấy phần tử đầu tiên
int front(queue *q)
{
    if (empty(q))
    {
        printf("Queue rỗng.\n");
        return -1;
    }
    return q->front->data;
}

// Xóa phần tử đầu tiên
void pop(queue *q)
{
    if (empty(q))
    {
        printf("Queue rỗng.\n");
        return;
    }
    Node *temp = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
    free(temp);
}

// In các phần tử trong hàng đợi
void OUT(queue *q)
{
    if (empty(q))
    {
        printf("Queue rỗng.\n");
        return;
    }
    Node *temp = q->front;
    printf("Các phần tử trong hàng đợi: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Giải phóng toàn bộ hàng đợi
void freeQueue(queue *q)
{
    while (!empty(q))
    {
        pop(q);
    }
    free(q);
}

int main()
{
    queue *q = createQ();
    if (!q)
        return 1;

    int choice, value;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Thêm phần tử vào queue (enqueue)\n");
        printf("2. Xóa phần tử khỏi queue (dequeue)\n");
        printf("3. Xem phần tử đầu tiên (front)\n");
        printf("4. Kiểm tra queue có rỗng không\n");
        printf("5. In toàn bộ queue\n");
        printf("0. Thoát\n");
        printf("Chọn: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhập giá trị cần thêm: ");
            scanf("%d", &value);
            push(q, value);
            break;
        case 2:
            pop(q);
            break;
        case 3:
            value = front(q);
            if (!empty(q))
                printf("Phần tử đầu tiên là: %d\n", value);
            break;
        case 4:
            if (empty(q))
                printf("Queue đang rỗng.\n");
            else
                printf("Queue KHÔNG rỗng.\n");
            break;
        case 5:
            OUT(q);
            break;
        case 0:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 0);

    freeQueue(q);
    return 0;
}
