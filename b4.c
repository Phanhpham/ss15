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
}

bool detectCycleUtil(Graph *g, int vertex, bool visited[], bool recStack[])
{
    if (!visited[vertex])
    {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (int i = 0; i < g->numVertices; i++)
        {
            if (g->vertices[vertex][i])
            {
                if (!visited[i] && detectCycleUtil(g, i, visited, recStack))
                {
                    return true;
                }
                else if (recStack[i])
                {
                    return true;
                }
            }
        }
    }

    recStack[vertex] = false;
    return false;
}

bool detectCycle(Graph *g)
{
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < g->numVertices; i++)
    {
        if (detectCycleUtil(g, i, visited, recStack))
        {
            return true;
        }
    }
    return false;
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

    if (detectCycle(&g))
    {
        printf("\n\u0110ồ thị c\u00f3 chu tr\u00ecnh\n");
    }
    else
    {
        printf("\n\u0110ồ thị kh\u00f4ng c\u00f3 chu tr\u00ecnh\n");
    }

    return 0;
}
