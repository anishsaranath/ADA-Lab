#include <stdio.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mst[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mst[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prims(int graph[V][V], int V) {
    int parent[V], key[V], mst[V];
    int mincost = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mst, V);
        mst[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mst[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edges in MST:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d (weight %d)\n", parent[i], i, graph[i][parent[i]]);
        mincost += graph[i][parent[i]];
    }
    printf("Minimum cost: %d\n", mincost);
}

int main() {
    int V;
    printf("Enter vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prims(graph, V);
    return 0;
}
