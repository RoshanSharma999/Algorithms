#include <stdio.h>
#define MAX 10
#define INF 9999

void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX], i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX], n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (use 9999 for infinity):\n");
    for(int i = 0; i < n; i++){
    	printf("Row %d:\n", i + 1);
    	for(int j = 0; j < n; j++)
    		scanf("%d", &graph[i][j]);
    }
    floydWarshall(graph, n);
    return 0;
}
