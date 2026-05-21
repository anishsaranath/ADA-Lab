#include <stdio.h>

#define MAX 10

int indegree[MAX];
void topologicalSort(int graph[MAX][MAX], int V)
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        indegree[i] = 0;
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    int count = 0;

    printf("Topological Order : ");
    while (count < V)
    {
        for (i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                printf("%d ", i);

                indegree[i] = -1;

                for (j = 0; j < V; j++)
                {
                    if (graph[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }

                count++;
            }
        }
    }

    printf("\n");
}

int main()
{
    int V, i, j;

    int graph[MAX][MAX];

    printf("Enter number of vertices : ");
    scanf("%d", &V);

    printf("Enter adjacency matrix :\n");

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, V);

    return 0;
}
