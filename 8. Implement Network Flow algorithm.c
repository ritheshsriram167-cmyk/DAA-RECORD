Aim:

To implement the Network Flow algorithm using Ford-Fulkerson method.

Algorithm:
Read the capacity matrix.
Find augmenting path using BFS.
Find minimum residual capacity.
Add it to max flow.
Update residual graph.
Repeat until no augmenting path exists.

Full Program:
#include <stdio.h>
#include <string.h>

int bfs(int rGraph[10][10], int n, int s, int t, int parent[]) {
    int visited[10] = {0};
    int queue[10], front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }

    return visited[t];
}

int fordFulkerson(int graph[10][10], int n, int source, int sink) {
    int u, v;
    int rGraph[10][10];
    int parent[10];
    int maxFlow = 0;

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    while (bfs(rGraph, n, source, sink, parent)) {
        int pathFlow = 99999;

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < pathFlow)
                pathFlow = rGraph[u][v];
        }

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, graph[10][10], source, sink;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter capacity matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source and sink: ");
    scanf("%d %d", &source, &sink);

    printf("Maximum Flow = %d\n", fordFulkerson(graph, n, source, sink));

    return 0;
}
