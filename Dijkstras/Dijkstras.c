#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

int minDistance(int dist[], int visited[], int V)
{
    int min = INF, minIndex;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Dijkstra's Shortest Path from source %d:\n", src);
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d : %d\n", i, dist[i]);
    }
}

int main()
{
    int V, src;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}
