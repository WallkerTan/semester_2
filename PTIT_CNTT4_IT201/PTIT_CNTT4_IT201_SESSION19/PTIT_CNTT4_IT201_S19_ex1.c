#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct tree
{
    Node *root;
} tree;

typedef struct QNode
{
    Node *treeNode; // trỏ đến node trong cây
    struct QNode *next;
} QNode;

typedef struct queue
{
    QNode *front;
    QNode *rear;
} queue;

// tạo một queue
queue *creatQ()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (!q)
    {
        printf("cap phat bo nhơ that bai.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// tạo một qNode
QNode *creatQNode(Node *n)
{
    QNode *QN = (QNode *)malloc(sizeof(QNode));
    if (!QN)
    {
        printf("cap phat bo nhơ that bai.\n");
        return NULL;
    }
    QN->next = NULL;
    QN->treeNode = n;
    return QN;
}
// kiểm tra rỗng
bool empty(queue *q)
{
    return q->front == NULL;
}
// thêm vào tree
void pushQUeue(queue *q, Node *n)
{
    QNode *newQ = creatQNode(n);
    // nếu ko có phần tử
    if (empty(q))
    {
        q->front = q->rear = newQ;
        return;
    }
    q->rear->next = newQ;
    q->rear = newQ;
}

Node *popQueue(queue *q)
{
    // ko có phần tử
    if (empty(q))
    {
        printf("không có phàn tử.\n");
        return NULL;
    }

    QNode *temp = q->front;
    Node *treeNode = q->front->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

// tạo 1 node
Node *creatNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
    {
        printf("cấp phát bộ nhớ thất bại.\n");
        return NULL;
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// tạo 1 cây
tree *creatT()
{
    tree *t = (tree *)malloc(sizeof(tree));
    if (!t)
    {
        printf("cấp phát bộ nhớ thất bại.\n");
        return NULL;
    }
    t->root = NULL;
    return t;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return creatNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// thêm theo giá trị nhỏ , lớn
void push(tree *t, int data)
{
    t->root = insert(t->root, data);
}

// thêm theo lv
void push2(tree *t, int data)
{
    if (t->root == NULL)
    {
        t->root = creatNode(data);
        return;
    }
    queue *q = creatQ();
    pushQUeue(q, t->root);
    while (1)
    {
        Node *temp = popQueue(q);
        if (temp->left == NULL)
        {
            temp->left = creatNode(data);
            free(q);
            return;
        }
        else
        {
            pushQUeue(q, temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = creatNode(data);
            free(q);
            return;
        }
        else
        {
            pushQUeue(q, temp->right);
        }
    }
    free(q);
}

// 4 cách duyệt
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preoder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preoder(root->left);
        preoder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(Node *root)
{
    queue *q = creatQ();
    pushQUeue(q, root);
    while (!empty(q))
    {
        Node *t = popQueue(q);
        printf("%d ", t->data);
        if (t->left != NULL)
        {
            pushQUeue(q, t->left);
        }
        if (t->right != NULL)
        {
            pushQUeue(q, t->right);
        }
    }
    free(q);
}

void printTreeOrders(tree *t)
{
    printf("\n== Inorder ==\n");
    inorder(t->root);
    printf("\n");

    printf("\n== Preorder ==\n");
    preoder(t->root);
    printf("\n");

    printf("\n== Postorder ==\n");
    postorder(t->root);
    printf("\n");

    printf("\n== Level Order ==\n");
    levelOrder(t->root);
    printf("\n");
}

// giải phóng bộ nhớ
void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void freequeue(queue *q)
{
    while (!empty(q))
    {
        popQueue(q);
    }
    free(q);
}

// Tìm kiếm nhị phân (Binary Search) - Thuộc nhánh DFS
void BinarySearch(Node *root, int find)
{
    if (root == NULL)
    {
        printf("false.\n");
        return;
    }

    if (root->data == find)
    {
        printf("true.\n");
        return;
    }

    if (find < root->data)
    {
        BinarySearch(root->left, find);
    }
    else
    {
        BinarySearch(root->right, find);
    }
}

// Tìm kiếm theo BFS (dùng queue)
void BFS(Node *root, int find)
{
    if (root == NULL)
    {
        printf("false.\n");
        return;
    }
    queue *q = creatQ();
    pushQUeue(q, root);
    while (!empty(q))
    {
        Node *temp = popQueue(q);
        if (temp->data == find)
        {
            printf("true.\n");
            return;
        }
        if (temp->left != NULL)
            pushQUeue(q, temp->left);
        if (temp->right != NULL)
            pushQUeue(q, temp->right);
    }
    printf("false.\n");
    freequeue(q);
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

int main()
{
    tree *t = creatT();
    push(t, 10);
    push(t, 20);
    push(t, 30);
    push(t, 40);
    push(t, 50);
    tree *k = creatT();
    push2(k, 1);
    push2(k, 2);
    push2(k, 3);
    push2(k, 4);
    push2(k, 5);
    push2(k, 6);
    printTreeOrders(t);
    printTreeOrders(k);
    BinarySearch(t->root, 1);
    BFS(k->root, 3);
    printf("%d.\n", height(t->root));
    printf("%d.\n", height(k->root));
    freeTree(t->root);
    freeTree(k->root);
    return 0;
}
