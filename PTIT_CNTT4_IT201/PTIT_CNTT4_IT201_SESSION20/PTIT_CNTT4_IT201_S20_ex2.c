#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tnode
{
    int value;
    struct Tnode *left;
    struct Tnode *right;
} Tnode;

typedef struct Nqueue
{
    Tnode *node;
    struct Nqueue *next;
} Nqueue;

typedef struct queue
{
    Nqueue *front;
    Nqueue *rear;
} queue;

typedef struct Tree
{
    Tnode *root;
} Tree;

// khoier tạc các cấu trúc
Tnode *creatNode(int value)
{
    Tnode *newnode = (Tnode *)malloc(sizeof(Tnode));
    if (!newnode)
    {
        printf("cap phat bo nhơ that bại .\n");
        return 0;
    }
    newnode->left = newnode->right = NULL;
    newnode->value = value;
    return newnode;
}

Nqueue *creatNq(Tnode *n)
{
    Nqueue *newq = (Nqueue *)malloc(sizeof(Nqueue));
    if (!newq)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    newq->node = n;
    newq->next = NULL;
    return newq;
}

queue *creatQueue()
{
    queue *newq = (queue *)malloc(sizeof(queue));
    if (!newq)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    newq->front = newq->rear = NULL;
    return newq;
}

Tree *creatTree()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    if (!t)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    t->root = NULL;
    return t;
}

// thao tác hàng đợi hàng đợi
bool empty(queue *q)
{
    return q == NULL || q->front == NULL;
}

void freeTree(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void pushQueue(queue *q, Tnode *t)
{
    Nqueue *temp = creatNq(t);
    if (q == NULL || temp == NULL)
        return;
    // không có phần tử
    if (q->front == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

Tnode *popQueue(queue *q)
{
    if (q == NULL)
        return NULL;
    // nếu rỗng
    if (q->front == NULL)
    {
        printf("ds rỗng.\n");
        return NULL;
    }
    Nqueue *temp = q->front;
    Tnode *n = q->front->node;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return n;
}

// giải phóng bộ nhớ
void freeQueue(queue *q)
{
    if (q == NULL)
        return;
    while (!empty(q))
    {
        popQueue(q); // Hàm popQueue đã tự giải phóng Nqueue
    }
    free(q);
}
// 2 cách push
Tnode *insert(Tnode *root, int value)
{
    if (root == NULL)
    {
        return creatNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void pushOp(Tree *t, int value)
{
    t->root = insert(t->root, value);
}

void pushLR(Tree *t, int value)
{
    queue *q = creatQueue();
    if (t->root == NULL)
    {
        t->root = creatNode(value);
        return;
    }
    pushQueue(q, t->root);
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->left != NULL)
        {
            pushQueue(q, temp->left);
        }
        else
        {
            temp->left = creatNode(value);
            freeQueue(q);
            return;
        }
        if (temp->right != NULL)
        {
            pushQueue(q, temp->right);
        }
        else
        {
            temp->right = creatNode(value);
            freeQueue(q);
            return;
        }
    }
    freeQueue(q);
}

// menu
void menu()
{
    printf("\n===== MENU CHUONG TRINH CAY NHI PHAN =====\n");
    printf("1. Giai phong bo nho cay\n");
    printf("2. them node vao cay\n");
    printf("3. Duyet cay theo NLR (Pre-order)\n");
    printf("4. Duyet cay theo LNR (In-order)\n");
    printf("5. Duyet cay theo LRN (Post-order)\n");
    printf("6. Duyet cay theo chieu rong (Level-order)\n");
    printf("7. Tim mot gia tri trong cay\n");
    printf("8. Xoa mot node trong cay\n");
    printf("9. Tinh chieu cao cua cay\n");
    printf("10. Dem so la (node khong co con)\n");
    printf("11. Tim node co gia tri lon nhat\n");
    printf("12. Tim node co gia tri nho nhat\n");
    printf("0. Thoat chuong trinh\n");
    printf("==========================================\n");
}

// trái - gốc - phải
void Inorder(Tnode *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            Inorder(root->left);
        printf("%d ", root->value);
        if (root->right != NULL)
            Inorder(root->right);
    }
}

// gốc - trái - phải
void Preorder(Tnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->value);
        if (root->left != NULL)
            Preorder(root->left);
        if (root->right != NULL)
            Preorder(root->right);
    }
}
// trái - phải - gốc
void Postorder(Tnode *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            Postorder(root->left);
        if (root->right != NULL)
            Postorder(root->right);
        printf("%d ", root->value);
    }
}

// in theo lv
void levaloder(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        printf("%d ", temp->value);
        if (temp->left != NULL)
        {
            pushQueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            pushQueue(q, temp->right);
        }
    }
    freeQueue(q);
}

// lựa chọn kiểu thêm
int isadd()
{
    int choice;
    do
    {
        printf("1: thêm kieu tim kiem nhi phan.\n");
        printf("2: them theo lv.\n");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);
    return choice;
}

// tìm kiếm
void search(Tnode *root, int value)
{
    if (root == NULL)
    {
        printf("false.\n");
        return;
    }
    if (root->value == value)
    {
        printf("true.\n");
        return;
    }
    if (value < root->value && root->left != NULL)
    {
        search(root->left, value);
        return;
    }
    else if (value > root->right && root->right != NULL)
    {
        search(root->right, value);
        return;
    }
}

// tìm kiếm bfs
void BFS(Tnode *root, int value)
{
    if (root == NULL)
    {
        printf("false.\n");
        return;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->value == value)
        {
            printf("true.\n");
            return;
        }
        if (temp->left != NULL)
            pushQueue(q, temp->left);
        if (temp->right != NULL)
            pushQueue(q, temp->right);
    }
    printf("false.\n");
}

// tìm phần tử cuối cùng của gốc
Tnode *end(Tnode *root, Tnode *parent)
{
    if (root == NULL)
        return NULL;

    if (root->right != NULL)
    {
        return end(root->right, root);
    }
    else if (root->left != NULL)
    {
        return end(root->left, root);
    }
    if (parent != NULL)
    {
        if (parent->right == root)
            parent->right = NULL;
        else if (parent->left == root)
            parent->left = NULL;
    }

    Tnode *newnode = creatNode(root->value);
    free(root);
    return newnode;
}

void delelement(Tnode *root, int value)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        root = NULL;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->value == value)
        {
            Tnode *test = end(temp, NULL);
            temp->value = test->value;
            free(test);
            free(q);
            return;
        }
        if (temp->left != NULL)
            pushQueue(q, temp->left);
        if (temp->right != NULL)
            pushQueue(q, temp->right);
    }
    printf("khong tim thay.\n");
}

int heightTree(Tnode *root)
{
    if (root == NULL)
        return 0;
    int l = heightTree(root->left);
    int r = heightTree(root->right);
    return (l > r ? l : r) + 1;
}

void leaf(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    int cnt = 0;
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->left == NULL && temp->right == NULL)
        {
            cnt++;
        }
        if (temp->left != NULL)
        {
            pushQueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            pushQueue(q, temp->right);
        }
    }
    printf("co %d la.\n", cnt);
    freeQueue(q);
}

void max(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    int maxvalue = -9999;
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->value > maxvalue)
        {
            maxvalue = temp->value;
        }
        if (temp->left != NULL)
        {
            pushQueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            pushQueue(q, temp->right);
        }
    }
    printf("max: %d\n", maxvalue);
    freeQueue(q);
}

void min(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue *q = creatQueue();
    pushQueue(q, root);
    int minvalue = 9999;
    while (!empty(q))
    {
        Tnode *temp = popQueue(q);
        if (temp->value < minvalue)
        {
            minvalue = temp->value;
        }
        if (temp->left != NULL)
        {
            pushQueue(q, temp->left);
        }
        if (temp->right != NULL)
        {
            pushQueue(q, temp->right);
        }
    }
    printf("min: %d\n", minvalue);
    freeQueue(q);
}

int main()
{
    // tạo 1 cây
    Tree *t = creatTree();
    if (t == NULL)
        return 1;
    pushLR(t, 1);
    pushLR(t, 2);
    pushLR(t, 3);
    pushLR(t, 4);
    pushLR(t, 5);
    pushLR(t, 6);
    pushLR(t, 7);
    int choice, vle, z, del, find;
    do
    {
        menu();
        printf("lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            freeTree(t->root);
            printf("da giai phong bo nho.\n");
            break;
        case 2:
            z = isadd();
            if (z == 1)
            {
                printf("nhap gia tri muon them.\n");
                scanf("%d", &vle);
                pushOp(t, vle);
            }
            else if (z == 2)
            {
                printf("nhap gia tri muon them.\n");
                scanf("%d", &vle);
                pushLR(t, vle);
            }
            break;
        case 3:
            Preorder(t->root);
            break;
        case 4:
            Inorder(t->root);
            break;
        case 5:
            Postorder(t->root);
            break;
        case 6:
            levaloder(t->root);
            break;
        case 7:
            printf("gia tri muon tim kiem.\n");
            scanf("%d", &find);
            search(t->root, find);
            BFS(t->root, find);
            break;
        case 8:
            printf("gia tri muon xoa.\n");
            scanf("%d", &del);
            delelement(t->root, del);
            break;
        case 9:
            printf("cây cao: %d.\n", heightTree(t->root));
            break;
        case 10:
            leaf(t->root);
            break;
        case 11:
            max(t->root);
            break;
        case 12:
            min(t->root);
            break;
        default:
            break;
        }
    } while (choice != 0);
    return 0;
}