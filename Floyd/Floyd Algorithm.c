#include <stdio.h>
#define INF 99999

void main() {
    int n;
    printf("Enter number of vertices: "); scanf("%d", &n);
    int D[n][n];
    printf("Enter weight matrix (use %d for INF):\n", INF);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &D[i][j]);
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
    printf("Shortest distance matrix:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", D[i][j]);
        printf("\n");
    }
}
