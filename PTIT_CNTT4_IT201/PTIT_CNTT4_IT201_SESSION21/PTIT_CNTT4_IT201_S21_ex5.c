#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node trong danh sách liên kết
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Cấp phát thất bại!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node *graph[], int start, int end)
{
    // Thêm end vào danh sách của start
    Node *newNode = createNode(end);
    newNode->next = graph[start];
    graph[start] = newNode;

    // Thêm start vào danh sách của end (vì là đồ thị vô hướng)
    newNode = createNode(start);
    newNode->next = graph[end];
    graph[end] = newNode;
}
void printGraph(Node *graph[], int V)
{
    for (int i = 0; i < V; i++)
    {
        printf("[%d] ", i);
        Node *temp = graph[i];
        while (temp)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int V = 3;      // Số đỉnh
    Node *graph[V]; // Mảng danh sách liên kết
    for (int i = 0; i < V; i++)
    {
        graph[i] = NULL;
    }

    addEdge(graph, 1, 2);
    printGraph(graph, V);
    printf("\n");

    addEdge(graph, 0, 1);
    printGraph(graph, V);

    return 0;
}
