#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int A;
    int **matrix;
} graph;

// khoi tạo 1 đồ thị
graph *creatPraph(int V)
{
    graph *g = (graph *)malloc(sizeof(graph));
    if (!g)
    {
        printf("cap phat that bai.\n");
        return NULL;
    }
    g->A = V;
    g->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        g->matrix[i] = (int *)calloc(V, sizeof(int));
        /* code */
    }
    return g;
}

// nối hai điểm đồ thị
void addedgh(graph *g, int a, int b)
{
    g->matrix[a][b] = 1;
    g->matrix[b][a] = 1;
}

void outone(graph *g)
{
    for (int i = 0; i < g->A; i++)
    {
        for (int j = 0; j < g->A; j++)
        {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

void outWo(graph *g)
{
    for (int i = 0; i < g->A; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < g->A; j++)
        {
            if (g->matrix[i][j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}

int main()
{
    graph *g = creatPraph(5);
    addedgh(g, 0, 1);
    outone(g);
    addedgh(g, 0, 2);
    outone(g);
    addedgh(g, 1, 3);
    outone(g);
    addedgh(g, 2, 1);
    outone(g);
    outWo(g);
    return 0;
}