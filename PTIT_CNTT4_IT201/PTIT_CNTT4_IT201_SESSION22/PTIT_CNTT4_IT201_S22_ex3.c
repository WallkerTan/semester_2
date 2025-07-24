#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *creatNode(int data)
{

    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Cấp phát thất bại!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addedgh(node *graph[], int begin, int end)
{
    node *newnode = creatNode(end);
    newnode->next = graph[begin];
    graph[begin] = newnode;
}

void outz(node *graph[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        node *temp = graph[i];
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node *graph[n];
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                addedgh(graph, i, j);
            }
        }
    }

    outz(graph, n);

    return 0;
}