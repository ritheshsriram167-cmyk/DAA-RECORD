Aim:

To implement Minimum Spanning Tree using Kruskal’s algorithm.

Algorithm:

Read vertices and edges.
Sort edges by weight.
Add smallest edge that does not form a cycle.
Repeat until V-1 edges are selected.
Print MST edges and cost.


Full Program:
#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

void sortEdges(struct Edge edges[], int e) {
    struct Edge temp;
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int v, e;
    struct Edge edges[100];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (int i = 0; i < v; i++)
        parent[i] = i;

    sortEdges(edges, e);

    int count = 0, minCost = 0;
    printf("Edges in MST:\n");

    for (int i = 0; i < e && count < v - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            printf("%d - %d = %d\n", edges[i].u, edges[i].v, edges[i].w);
            minCost += edges[i].w;
            unionSet(a, b);
            count++;
        }
    }

    printf("Total cost = %d\n", minCost);

    return 0;
}
