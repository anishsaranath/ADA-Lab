#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define MAX_EDGES 100

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int graph[MAX][MAX], int V)
{
    int edges[MAX_EDGES][3];
    int edgeCount = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount][0] = i;
                edges[edgeCount][1] = j;
                edges[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Kruskal's MST:\n");
    int mstWeight = 0;

    for (int i = 0; i < edgeCount; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (find(u) != find(v))
        {
            printf("%d -- %d : %d\n", u, v, weight);
            mstWeight += weight;
            unionSets(u, v);
        }
    }

    printf("Total Weight: %d\n", mstWeight);
}

int main()
{
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    kruskal(graph, V);

    return 0;
}
