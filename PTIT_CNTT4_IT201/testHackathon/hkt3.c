#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct task
{
    int Id;
    char *Title;
    int Priority;
    char *Dealine;
    struct task *next;
    struct task *prev;
} task;

typedef struct
{
    task *Top;
} stack;

typedef struct
{
    task *front;
    task *rear;
} queue;

// kiểm tra rỗng
bool emptyS(stack *s)
{
    return s->Top == NULL;
}

bool emptyQ(queue *q)
{
    return q->front == NULL;
}

// tạo thời gian ảo
char *ranDealine()
{
    char *time = (char *)malloc(20 * sizeof(char));
    int d = rand() % 30;
    int h = rand() % 24;
    int m = rand() % 60;
    int s = rand() % 60;
    sprintf(time, "%02d:%02d:%02d:%02d", d, h, m, s);
    return time;
}

// clone id
int cloneID(stack *s)
{
    if (emptyS(s))
    {
        return 1;
    }
    task *temp = s->Top;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->Id + 1;
}

// khởi tạo một task
task *creatTask(stack *s, char *Title, int Priority, char *Dealine)
{
    task *newtask = (task *)malloc(sizeof(task));
    if (!newtask)
    {
        printf("cap phat bo nho that bai.\n");
        return NULL;
    }
    newtask->Id = cloneID(s);
    newtask->next = NULL;
    newtask->prev = NULL;
    newtask->Priority = Priority;
    newtask->Title = (char *)malloc(strlen(Title) + 1);
    newtask->Dealine = (char *)malloc(strlen(Dealine) + 1);
    strcpy(newtask->Dealine, Dealine);
    strcpy(newtask->Title, Title);
    return newtask;
}

// khởi rạo một stack
stack *creatStack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (!s)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    s->Top = NULL;
    return s;
}

// khởi tạo 1 queue
queue *creatQueue()
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

// tạo bản sao
task *cloneTask(task *t)
{
    task *clone = (task *)malloc(sizeof(task));
    clone->Id = t->Id;
    clone->Priority = t->Priority;

    clone->Title = (char *)malloc(strlen(t->Title) + 1);
    strcpy(clone->Title, t->Title);

    clone->Dealine = (char *)malloc(strlen(t->Dealine) + 1);
    strcpy(clone->Dealine, t->Dealine);

    clone->next = clone->prev = NULL;
    return clone;
}

// thêm vào queue
void pushQueue(queue *q, task *t)
{
    task *task = cloneTask(t);
    // nếu ko có phần tử
    if (emptyQ(q))
    {
        q->front = q->rear = task;
        return;
    }
    q->rear->next = task;
    task->prev = q->rear;
    q->rear = task;
}

// thêm vào stack
void pushStack(stack *s, task *t)
{
    task *task = cloneTask(t);
    // nếu ko có phần từ
    if (emptyS(s))
    {
        s->Top = task;
        return;
    }
    s->Top->prev = task;
    task->next = s->Top;
    s->Top = task;
}

// lấy phần tử đầu stack
task *popStack(stack *s)
{
    if (emptyS(s))
    {
        printf("ds rong.\n");
        return NULL;
    }
    task *temp = s->Top;
    s->Top = s->Top->next;
    temp->next = NULL;
    if (s->Top != NULL)
        s->Top->prev = NULL;
    return temp;
}

bool duplicate(const char *a, const char *b)
{
    while (*a && *b)
    {
        if (tolower(*a) != tolower(*b))
        {
            return false;
        }
        a++;
        b++;
    }
    return *a == *b;
}

void search(stack *s, char *name)
{
    task *temp = s->Top;
    int t = 0;
    while (temp != NULL)
    {
        if (duplicate(temp->Title, name))
        {
            printf("%d_____%s_____%d_____%s.\n", temp->Id, temp->Title, temp->Priority, temp->Dealine);
            t = 1;
        }
        temp = temp->next;
    }
    if (t == 0)
    {
        printf("ko tìm thấy.\n");
    }
}

void swapTaskData(task *a, task *b)
{
    if (!a || !b)
        return;

    // Hoán đổi ID
    int tempId = a->Id;
    a->Id = b->Id;
    b->Id = tempId;

    // Hoán đổi Priority
    int tempPriority = a->Priority;
    a->Priority = b->Priority;
    b->Priority = tempPriority;

    // Hoán đổi Title
    char *tempTitle = a->Title;
    a->Title = b->Title;
    b->Title = tempTitle;

    // Hoán đổi Dealine
    char *tempDeadline = a->Dealine;
    a->Dealine = b->Dealine;
    b->Dealine = tempDeadline;
}

void bubbleSort(stack *s)
{

    if (s->Top == NULL)
        return;

    int swap;
    task *head;
    task *maxValue = NULL;

    do
    {
        swap = 0;
        head = s->Top;
        while (head->next != maxValue)
        {
            if (head->Priority > head->next->Priority)
            {
                swapTaskData(head, head->next);
                swap = 1;
            }
            head = head->next;
        }
        maxValue = head;
    } while (swap);
}

void showMenu()
{
    printf("\n==== MENU NHIEM VU ====\n");
    printf("1. Them nhiem vu\n");
    printf("2. Hien thi nhiem vu\n");
    printf("3. Xoa nhiem vu\n");
    printf("4. Cap nhat nhiem vu\n");
    printf("5. Danh dau hoan thanh\n");
    printf("6. Sap xep nhiem vu\n");
    printf("7. Tim kiem nhiem vu\n");
    printf("8. Thoat\n");
    printf("=======================\n");
    printf("Nhap lua chon (1-8): ");
}

void printStack(stack *s)
{
    if (emptyS(s))
    {
        printf("Stack rong.\n");
        return;
    }

    printf("=== Danh sach nhiem vu (STACK) ===\n");
    task *temp = s->Top;
    while (temp != NULL)
    {
        printf("ID: %d | Tieu de: %s | Do uu tien: %d | Deadline: %s\n",
               temp->Id, temp->Title, temp->Priority, temp->Dealine);
        temp = temp->next;
    }
}

void printQueue(queue *q)
{
    if (emptyQ(q))
    {
        printf("Queue rong.\n");
        return;
    }

    printf("=== Danh sach nhiem vu (QUEUE) ===\n");
    task *temp = q->front;
    while (temp != NULL)
    {
        printf("ID: %d | Tieu de: %s | Do uu tien: %d | Deadline: %s\n",
               temp->Id, temp->Title, temp->Priority, temp->Dealine);
        temp = temp->next;
    }
}

void deleteTaskByID_Stack(stack *s, int id)
{
    if (emptyS(s))
    {
        printf("Stack rong.\n");
        return;
    }

    task *cur = s->Top;
    task *prev = NULL;

    while (cur != NULL)
    {
        if (cur->Id == id)
        {
            if (prev == NULL)
            {
                s->Top = cur->next;
                if (s->Top)
                    s->Top->prev = NULL;
            }
            else
            {
                prev->next = cur->next;
                if (cur->next)
                    cur->next->prev = prev;
            }

            free(cur->Title);
            free(cur->Dealine);
            free(cur);
            printf("Da xoa task co ID = %d trong Stack.\n", id);
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("Khong tim thay ID %d trong Stack.\n", id);
}

void updateTaskByID(task *head, int id)
{
    task *cur = head;
    while (cur != NULL)
    {
        if (cur->Id == id)
        {
            char newTitle[100];
            int newPriority;
            char newDeadline[50];

            printf("Nhap tieu de moi: ");
            getchar(); // xoa '\n' bi sot lai
            fgets(newTitle, sizeof(newTitle), stdin);
            newTitle[strcspn(newTitle, "\n")] = 0; // xoa '\n'

            printf("Nhap do uu tien moi: ");
            scanf("%d", &newPriority);

            printf("Nhap deadline moi: ");
            getchar(); // xoa '\n'
            fgets(newDeadline, sizeof(newDeadline), stdin);
            newDeadline[strcspn(newDeadline, "\n")] = 0;

            // Ghi đè dữ liệu
            free(cur->Title);
            free(cur->Dealine);
            cur->Title = strdup(newTitle);
            cur->Dealine = strdup(newDeadline);
            cur->Priority = newPriority;

            printf("Da cap nhat task co ID = %d.\n", id);
            return;
        }
        cur = cur->next;
    }

    printf("Khong tim thay task co ID = %d.\n", id);
}

void updateTaskByID_Stack(stack *s, int id)
{
    if (emptyS(s))
    {
        printf("Stack rong.\n");
        return;
    }

    task *cur = s->Top;
    while (cur != NULL)
    {
        if (cur->Id == id)
        {
            char newTitle[100];
            int newPriority;
            char newDeadline[50];

            printf("Nhap tieu de moi: ");
            getchar(); // xoa \n truoc do
            fgets(newTitle, sizeof(newTitle), stdin);
            newTitle[strcspn(newTitle, "\n")] = 0; // xoa \n

            printf("Nhap do uu tien moi: ");
            scanf("%d", &newPriority);

            printf("Nhap deadline moi: ");
            getchar(); // xoa \n
            fgets(newDeadline, sizeof(newDeadline), stdin);
            newDeadline[strcspn(newDeadline, "\n")] = 0;

            // Ghi de noi dung
            free(cur->Title);
            free(cur->Dealine);
            cur->Title = strdup(newTitle);
            cur->Dealine = strdup(newDeadline);
            cur->Priority = newPriority;

            printf(">> Da cap nhat task co ID = %d.\n", id);
            return;
        }
        cur = cur->next;
    }

    printf(">> Khong tim thay task co ID = %d trong Stack.\n", id);
}

int main()
{
    stack *s = creatStack();
    queue *q = creatQueue();
    int choice;
    do
    {
        showMenu();
        scanf("%d", &choice);
        getchar();
        char name[50];
        int p, id;
        switch (choice)
        {
        case 1:
            printf("-> Them nhiem vu\n");
            // ten
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            // mức độ ưu tiên
            scanf("%d", &p);
            task *newtask = creatTask(s, name, p, ranDealine());
            pushStack(s, newtask);
            break;
        case 2:
            printf("-> Hien thi nhiem vu\n");
            printStack(s);
            break;
        case 3:
            printf("-> Xoa nhiem vu\n");
            scanf("%d", &id);
            deleteTaskByID_Stack(s, id);
            break;
        case 4:
            printf("-> Cap nhat nhiem vu\n");
            scanf("%d", &id);
            updateTaskByID_Stack(s, id);
            break;
        case 5:
            printf("-> Danh dau hoan thanh\n");
            break;
        case 6:
            printf("-> Sap xep nhiem vu\n");
            bubbleSort(s);
            break;
        case 7:
            printf("-> Tim kiem nhiem vu\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            search(s, name);
            break;
        case 8:
            printf("-> Thoat chuong trinh\n");
            break;
        default:
            printf("-> Lua chon khong hop le!\n");
            break;
        }

    } while (choice != 8);

    return 0;
}
