#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int start) {
    int i, current;
    for (i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("Nodes reachable from node %d are:\n", start);
    
    while (!isEmpty()) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, edges, origin, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (origin destination):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &origin, &dest);
        if (origin >= n || dest >= n || origin < 0 || dest < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            adj[origin][dest] = 1;
        }
    }
    printf("Enter starting node for BFS: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
