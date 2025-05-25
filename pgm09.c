#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;

int compareEdge(const void *a, const void *b) {
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight - b1->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalMST(Edge edges[], int v, int e) {
    Edge result[v];
    int edgeCount = 0, i = 0;

    qsort(edges, e, sizeof(Edge), compareEdge);

    Subset *subsets = (Subset *)malloc(v * sizeof(Subset));

    for (int j = 0; j < v; j++) {
        subsets[j].parent = j;
        subsets[j].rank = 0;
    }

    while (edgeCount < v - 1 && i < e) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[edgeCount++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < edgeCount; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum cost of MST: %d\n", minCost);

    free(subsets);
}

int main() {
    int v, e;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    Edge edges[e];
    printf("Enter each edge in the format: src dest weight\n");
    for (int i = 0; i < e; i++) {
        printf("Edge %d: ", i + 1);
		// 1-based to 0-based
        int src, dest, weight;
		scanf("%d %d %d", &src, &dest, &weight);
		edges[i].src = src - 1;
		edges[i].dest = dest - 1;
		edges[i].weight = weight;
    }

    kruskalMST(edges, v, e);
    return 0;
}
