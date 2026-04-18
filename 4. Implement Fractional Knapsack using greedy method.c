Aim: To implement the Fractional Knapsack problem using the greedy method.

Algorithm:
          Read number of items, values, weights, and capacity.
          Find profit/weight ratio.
          Sort items in descending order of ratio.
          Pick full items while possible.
          If needed, pick fractional part of next item.
          Print maximum profit. 

Full Program:

#include <stdio.h>

struct Item {
    int value, weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    struct Item temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    struct Item items[100];
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter values and weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalProfit += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
