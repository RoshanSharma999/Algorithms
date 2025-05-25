#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_CITIES 100

int minDistance(int dist[], bool sptSet[], int N) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < N; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int N, int src) {
    printf("City\tDistance from City %d\n", src);
    for (int i = 0; i < N; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX_CITIES][MAX_CITIES], int src, int N) {
    int dist[MAX_CITIES];
    bool sptSet[MAX_CITIES];
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet, N);
        sptSet[u] = true;
        for (int v = 0; v < N; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, N, src);
}

int main() {
    int N, src;
    int graph[MAX_CITIES][MAX_CITIES];
    
    printf("Enter number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &N);
    printf("Enter the adjacency matrix representing the graph (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source city (0 to %d): ", N-1);
    scanf("%d", &src);
    dijkstra(graph, src, N);
    return 0;
}
