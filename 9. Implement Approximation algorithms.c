Aim:

To implement an approximation algorithm for the Vertex Cover problem.

Algorithm:
Read vertices and edges.
Pick an uncovered edge.
Add both endpoints to cover.
Remove all incident edges.
Repeat until no edges remain.
Print approximate vertex cover.
  
Full Program:

#include <stdio.h>
int main() {
    int e;
    int edges[100][2];
    int selected[100] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    printf("Approximate Vertex Cover: ");
    for (int i = 0; i < e; i++) {
        if (!selected[i]) {
            int u = edges[i][0];
            int v = edges[i][1];
            printf("%d %d ", u, v);

            for (int j = i; j < e; j++) {
                if (edges[j][0] == u || edges[j][1] == u ||
                    edges[j][0] == v || edges[j][1] == v) {
                    selected[j] = 1;
                }
            }
        }
    }

    printf("\n");
    return 0;
}
