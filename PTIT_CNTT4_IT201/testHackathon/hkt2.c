#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

// cấu trúc cuộc gọi
typedef struct
{
    char phone[10];
    char calltime[10];
    struct Call *next;
    struct Call *prev;
} Call;

// cấu trúc ngăn sếp
typedef struct
{
    Call *Top;
} stack;

// cấu trúc hàng đợi
typedef struct
{
    Call *front;
    Call *rear;
} queue;

// tạo time ngẫu nhiên
char *rantime()
{
    static char time[10];
    int h = rand() % 2;
    int m = rand() % 60;
    int s = rand() % 60;
    sprintf(time, "%02d:%02d:%02d", h, m, s);
    return time;
}

stack *createStack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (!s)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    s->Top = NULL;
    return s;
}

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

Call *creatCall(char *phone)
{
    Call *c = (Call *)malloc(sizeof(Call));
    if (!c)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    c->next = NULL;
    c->prev = NULL;
    strcpy(c->phone, phone);
    strcpy(c->calltime, rantime());
    return c;
}

bool empty(queue *q, stack *s, int type)
{
    return type == 1 ? q->front == NULL : s->Top == NULL;
}

Call *cloneCall(Call *c)
{
    Call *clone = (Call *)malloc(sizeof(Call));
    if (!clone)
    {
        printf("cấp phát thất bại.\n");
        return NULL;
    }
    strcpy(clone->phone, c->phone);
    strcpy(clone->calltime, c->calltime);
    clone->next = clone->prev = NULL;
    return clone;
}

void pushStack(stack *s, Call *c)
{
    Call *temp = cloneCall(c);
    // nếu ko có phần tử
    if (empty(NULL, s, 2))
    {
        s->Top = temp;
        temp->next = NULL;
        return;
    }
    temp->next = s->Top;
    s->Top = temp;
}

void pushQueue(queue *q, Call *c)
{
    Call *temp = cloneCall(c);
    if (empty(q, NULL, 1))
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    temp->prev = q->rear;
    q->rear = temp;
}

void outHistory(queue *q)
{
    Call *temp = q->front;
    while (temp != NULL)
    {
        printf("%s\n", temp->phone);
        printf("%s\n", temp->calltime);
        temp = temp->next;
    }
    free(temp);
}

void outStack(stack *s)
{
    Call *temp = s->Top;
    while (temp != NULL)
    {
        printf("%s\n", temp->phone);
        printf("%s\n", temp->calltime);
        temp = temp->prev;
    }
    free(temp);
}

Call *popStack(stack *s)
{
    // nếu ko có phần tử
    if (empty(NULL, s, 2))
    {
        printf("ds rỗng.\n");
        return NULL;
    }
    // nếu có 1 phần tử
    Call *temp = s->Top;
    if (s->Top->next == NULL)
    {
        s->Top = NULL;
        free(temp);
        return NULL;
    }
    s->Top = s->Top->next;
    s->Top->prev = NULL;
    return temp;
}

void showMenu()
{
    printf("\n=== CALL HISTORY MANAGER ===\n");
    printf("1. CALL    - Gọi số điện thoại mới\n");
    printf("2. BACK    - Quay lại số trước đó\n");
    printf("3. REDIAL  - Gọi lại số tiếp theo\n");
    printf("4. HISTORY - Hiển thị lịch sử cuộc gọi\n");
    printf("5. EXIT    - Thoát chương trình\n");
    printf("Chọn chức năng (1-5): ");
}

void BACK(stack *s, stack *f)
{
    if (empty(NULL, s, 2))
    {
        printf("ds rỗng.\n");
        return;
    }
    Call *new = popStack(s);
    pushStack(f, new);
}

void REDIAL(stack *s, stack *f)
{
    if (empty(NULL, s, 2))
    {
        printf("khong co so de goi lai.\n");
        return;
    }
    pushStack(f, popStack(s));
}

int main()
{
    stack *callBackStack = createStack();
    stack *callForwardStack = createStack();
    queue *callHistoryQueue = createQueue();

    int choice;
    do
    {
        char phone[10];
        showMenu();

        Call *newCall;
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case 1:
            printf(">> nhap sdt:\n");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = '\0';
            newCall = creatCall(phone);
            printf("ban da goi : %s.\ntime: %s.\n", newCall->phone, newCall->calltime);
            // thêm vào callback , history
            pushStack(callBackStack, newCall);
            pushQueue(callHistoryQueue, newCall);
            // outHistory(callHistoryQueue);
            // outStack(callForwardStack);
            free(newCall);
            break;
        case 2:
            printf(">> [BACK]\n");
            BACK(callBackStack, callForwardStack);
            outStack(callBackStack);
            // outStack(callForwardStack);
            break;
        case 3:
            printf(">> [REDIAL] - Gọi lại số tiếp theo (chưa xử lý)\n");
            REDIAL(callForwardStack, callBackStack);
            outStack(callForwardStack);
            break;
        case 4:
            printf(">> [HISTORY]\n");
            outHistory(callHistoryQueue);
            break;
        case 5:
            printf(">> Đang thoát chương trình...\n");
            break;
        default:
            printf(">> Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 5);

    return 0;
}