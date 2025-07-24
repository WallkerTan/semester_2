#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph
{
    int V;
    int **matrix;
} graph;

typedef struct Qdata
{
    int data;
    struct Qdata *next;
} Qdata;

typedef struct queue
{
    Qdata *front;
    Qdata *rear;
} queue;

Qdata *createQdata(int value)
{
    Qdata *newNode = (Qdata *)malloc(sizeof(Qdata));
    if (newNode == NULL)
    {
        printf("Không thể cấp phát bộ nhớ cho Qdata.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        printf("Không thể cấp phát bộ nhớ cho queue.\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool empty(queue *q)
{
    return q->front == NULL;
}

void pushQ(queue *q, int data)
{
    Qdata *temp = createQdata(data);
    if (empty(q))
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int popQ(queue *q)
{
    if (empty(q))
    {
        printf("Queue rỗng.\n");
        return -1;
    }
    Qdata *temp = q->front;
    int z = temp->data;
    q->front = q->front->next;
    free(temp);
    return z;
}

void freeQueue(queue *q)
{
    while (!empty(q))
    {
        popQ(q);
    }
    free(q);
}

graph *creatGrap(int V)
{
    graph *g = (graph *)malloc(sizeof(graph));
    if (!g)
    {
        printf("Cấp phát bộ nhớ thất bại.\n");
        return NULL;
    }
    g->V = V;
    g->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        g->matrix[i] = (int *)calloc(V, sizeof(int));
    }
    return g;
}

void freeGraph(graph *g)
{
    for (int i = 0; i < g->V; i++)
    {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

void addedgh(graph *g, int src, int dest)
{
    g->matrix[src][dest] = 1;
    g->matrix[dest][src] = 1;
}

void DFSutil(graph *g, int a, int *visited)
{
    printf("%d ", a);
    visited[a] = 1; // Sửa từ == sang =
    for (int i = 0; i < g->V; i++)
    {
        if (g->matrix[a][i] == 1 && visited[i] == 0)
        {
            DFSutil(g, i, visited);
        }
    }
}

void DFS(graph *g, int src)
{
    int *visited = (int *)calloc(g->V, sizeof(int));
    printf("DFS: ");
    DFSutil(g, src, visited);
    printf("\n");
    free(visited);
}

void BFS(graph *g, int src)
{
    queue *q = createQueue();
    int *visited = (int *)calloc(g->V, sizeof(int));

    printf("BFS: ");
    visited[src] = 1;   // Đánh dấu đỉnh nguồn đã thăm
    printf("%d ", src); // In đỉnh nguồn
    pushQ(q, src);

    while (!empty(q))
    {
        int t = popQ(q);
        for (int i = 0; i < g->V; i++)
        {
            if (g->matrix[t][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                pushQ(q, i);
            }
        }
    }
    printf("\n");

    free(visited);
    freeQueue(q);
}

int main()
{
    graph *g = creatGrap(4);
    addedgh(g, 0, 1);
    addedgh(g, 0, 2);
    addedgh(g, 0, 3);
    addedgh(g, 1, 3);

    DFS(g, 0);
    BFS(g, 0);

    freeGraph(g);
    return 0;
}