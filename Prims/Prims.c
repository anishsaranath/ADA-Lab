#include <stdio.h>
#include <limits.h>

#define V 100

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (mst[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prims(int graph[V][V], int n) {
    int parent[V], key[V], mst[V];
    int mincost = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mst[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edges in MST:\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d (weight %d)\n", parent[i], i, graph[i][parent[i]]);
        mincost += graph[i][parent[i]];
    }
    printf("Minimum cost: %d\n", mincost);
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter adjacency matrix (0 if no edge, otherwise edge weight):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prims(graph, n);
    return 0;
}
