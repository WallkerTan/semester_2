#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// ds các khóa học chưa hoàn thành
typedef struct course
{
    int id;
    char name[100];
    int credit;
    bool status;
    struct course *next;
} course;

// ds các khóa học hoàn thành
typedef struct course2
{
    int id;
    char name[100];
    int credit;
    bool status;
    struct course2 *next;
    struct course2 *prev;
} course2;

typedef struct queue
{
    course *front;
    course *rear;
} queue;

// là số
bool isNUmber(char a)
{
    return isdigit(a);
}

// tạo 1 khóa học
course *creatSubject(int id, char *name, int credit)
{
    course *newC = (course *)malloc(sizeof(course));
    if (!newC)
    {
        printf("cấp phat thất bại.\n");
        return NULL;
    }
    newC->id = id;
    strcpy(newC->name, name);
    newC->credit = credit;
    newC->status == false;
    newC->next = NULL;
    return newC;
}


course2 *creatSubject2(int id, char *name, int credit)
{
    course2 *newC = (course2 *)malloc(sizeof(course2));
    if (!newC)
    {
        printf("cấp phat thất bại.\n");
        return NULL;
    }
    newC->id = id;
    strcpy(newC->name, name);
    newC->credit = credit;
    newC->status = false;
    newC->next = NULL;
    newC->prev = NULL;
    return newC;
}


// tạo một hàng đợi
queue *creatQ()
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

// kiểm tra rỗng
bool empty(queue *q)
{
    return q->front == NULL;
}
// thêm một phần tử vào hàng đợi
void push(queue *q, int id, char *name, int credit)
{
    course *newC = creatSubject(id, name, credit);
    // nếu không có phần tử
    if (empty(q))
    {
        q->front = q->rear = newC;
        return;
    }
    q->rear->next = newC;
    q->rear = newC;
}

void push2(queue *q, int id, char *name, int credit)
{
    course2 *newC = creatSubject2(id, name, credit);
    if (empty(q))
    {
        q->front = q->rear = (course *)newC;  // Ép kiểu nếu bạn giữ queue dùng course*
        return;
    }
    q->rear->next = (course *)newC;
    ((course2 *)newC)->prev = (course2 *)q->rear;
    ((course2 *)newC)->status = true;
    q->rear = (course *)newC;
}

void deleCourse(queue *q, int id)
{
    course *temp = q->front;
    course *h = NULL;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            // nếu chỉ có một phần tử
            if (temp->next == h)
            {
                q->front = q->rear = NULL;
            } // là phần tử đầu
            else if (h == NULL && temp->next != NULL)
            {
                q->front = temp->next;
            } // là phần tử cuối
            else if (h != NULL && temp->next == NULL)
            {
                course *t = q->rear;
                q->rear = h;
                free(t);
            } // bất kì
            else
            {
                h->next = temp->next;
            }
            return;
        }
        temp = temp->next;
    }
    free(temp);
}

void updateC(queue *q, int id)
{
    course *temp = q->front;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("1: sửa tên.\n2: tín chỉ.\nkhác: thoát.\n");
            int choice;
            scanf("%d", &choice);
            getchar();
            if (choice == 1)
            {
                char newname[30];
                printf("ten moi: ");
                fgets(newname, sizeof(newname), stdin);
                newname[strcspn(newname, "\n")] = '\0';
                strcpy(temp->name, newname);
            }
            else if (choice == 2)
            {
                int t;
                printf("số tín chỉ: ");
                scanf("%d", &t);
                temp->credit = t;
            }
            else
            {
                break;
            }
        }
    }
    return;
}

void showMenu()
{
    printf("\n");
    printf("\n===== MENU CHỨC NĂNG =====\n");
    printf("1. Thêm khóa học\n");
    printf("2. Hiển thị danh sách khóa học\n");
    printf("3. Xóa khóa học\n");
    printf("4. Cập nhật thông tin khóa học\n");
    printf("5. Đánh dấu khóa học đã hoàn thành\n");
    printf("6. Sắp xếp khóa học theo số tín chỉ\n");
    printf("7. Tìm kiếm khóa học theo tên\n");
    printf("0. Thoát chương trình\n");
    printf("===========================\n");
    printf("\n");
}

void OUT(queue *q)
{
    course *temp = q->front;
    while (temp != NULL)
    {
        printf("%d:  name: %s  credit: %d.\n", temp->id, temp->name, temp->credit);
        temp = temp->next;
    }
}

void complete(queue *q, queue *q2, int id) {
    course *temp = q->front;
    while (temp != NULL) {
        if (temp->id == id) {
            int t = temp->id;
            char name[100];
            strcpy(name, temp->name);
            int credit = temp->credit;
            push2(q2,t,name,credit);
            break;
        }
    }
    deleCourse(q,id);
}

int main() {
    queue *c1 = creatQ();
    queue *c2 = creatQ();
    int choice;
    do
    {
        int id, cred;
        char name[30];
        showMenu();
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("id: ");
                scanf("%d", &id);
                while (getchar() != '\n')
                    ; // xóa toàn bộ dòng còn lại trong bộ đệm

                printf("tên: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // xóa ký tự '\n' nếu có

                printf("số tín chỉ: ");
                scanf("%d", &cred);
                push(c1, id, name, cred);
                break;
            case 2:
                printf(">> Bạn đã chọn: Hiển thị danh sách khóa học\n");
                OUT(c1);
                OUT(c2);
                break;
            case 3:
                printf(">> Bạn đã chọn: Xóa khóa học\n");
                scanf("%d", &id);
                deleCourse(c1, id);
                break;
            case 4:
                printf(">> Bạn đã chọn: Cập nhật thông tin khóa học\n");
                scanf("%d", &id);
                updateC(c1, id);
                break;
            case 5:
                printf(">> Bạn đã chọn: Đánh dấu khóa học đã hoàn thành\n");
                scanf("%d", &id);
                complete(c1, c2, id);
                break;
            case 6:
                printf(">> Bạn đã chọn: Sắp xếp khóa học theo số tín chỉ\n");
                break;
            case 7:
                printf(">> Bạn đã chọn: Tìm kiếm khóa học theo tên\n");
                break;
            case 0:
                printf(">> Thoát chương trình.\n");
                break;
            default:
                printf(">> Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while (choice != 0);

    return 0;
}