q#include <stdio.h>
#define MAX 10

void warshall(int graph[MAX][MAX], int n) {
    int reach[MAX][MAX], i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            reach[i][j] = graph[i][j];
    
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
	
    printf("Transitive closure of given graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX], n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (row-by-row): \n");
    for(int i = 0; i < n; i++){
    	printf("Row %d:\n", i + 1);
    	for(int j = 0; j < n; j++)
    		scanf("%d", &graph[i][j]);
    }
    warshall(graph, n);
    return 0;
}
