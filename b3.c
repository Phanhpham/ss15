#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int vertices[MAX][MAX];
    int numVertices;
} Graph;

void initializeGraph(Graph *g, int V)
{
    g->numVertices = V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g->vertices[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v)
{
    g->vertices[u][v] = 1;
    g->vertices[v][u] = 1;
}

void DFS(Graph *g, int vertex, bool visited[])
{
    visited[vertex] = true;
    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->vertices[vertex][i] == 1 && !visited[i])
        {
            DFS(g, i, visited);
        }
    }
}

bool isConnected(Graph *g)
{
    bool visited[MAX] = {false};

    // Bắt đầu duyệt từ đỉnh đầu tiên
    DFS(g, 0, visited);

    // Kiểm tra xem tất cả các đỉnh có được thăm hay không
    for (int i = 0; i < g->numVertices; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int V, E;
    printf("Nhập số đỉnh: ");
    scanf("%d", &V);

    printf("Nhập số cạnh: ");
    scanf("%d", &E);

    Graph g;
    initializeGraph(&g, V);

    printf("Nhập danh sách các cạnh:\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    if (isConnected(&g))
    {
        printf("\n\u0110ồ thị liên thông\n");
    }
    else
    {
        printf("\n\u0110ồ thị không liên thông\n");
    }

    return 0;
}
