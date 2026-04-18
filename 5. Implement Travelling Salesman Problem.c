Aim:

To implement the Travelling Salesman Problem and find the minimum cost path.

Algorithm:

Read number of cities and cost matrix.
Fix starting city as 0.
Generate all possible tours.
Compute total cost of each tour.
Print minimum cost.


Full Program:

#include <stdio.h>
#include <limits.h>

int cost[10][10], visited[10], n;
int minCost = INT_MAX;

void tsp(int city, int count, int currentCost) {
    if (count == n && cost[city][0] > 0) {
        currentCost += cost[city][0];
        if (currentCost < minCost)
            minCost = currentCost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, currentCost + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0);

    printf("Minimum cost = %d\n", minCost);

    return 0;
}
