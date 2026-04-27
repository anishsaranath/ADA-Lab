#include <stdio.h>
#include <limits.h>

int parent[100], rank[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
}

void kruskal(int n, int edges[][3], int m) {
    int mincost = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if (find(u) != find(v)) {
            printf("Edge %d-%d (weight %d)\n", u, v, w);
            union_sets(u, v);
            mincost += w;
        }
    }
    printf("Minimum cost: %d\n", mincost);
}

int main() {
    int n, m;
    printf("Enter vertices, edges: ");
    scanf("%d %d", &n, &m);

    int edges[100][3];
    printf("Enter %d edges (u v weight):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskal(n, edges, m);
    return 0;
}
