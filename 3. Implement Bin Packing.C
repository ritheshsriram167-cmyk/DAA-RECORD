Aim: To implement the Bin Packing problem using the First Fit algorithm.

Algorithm:
         Read the number of items and bin capacity.
         Read item sizes.
         Place each item in the first bin where it fits.
         If not possible, open a new bin.
         Print bins used. 

Full Program:

#include <stdio.h>
int main() {
    int n, capacity;
    int items[100], binRemaining[100];
    int binCount = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < 100; i++)
        binRemaining[i] = capacity;

    for (int i = 0; i < n; i++) {
        int placed = 0;
        for (int j = 0; j < binCount; j++) {
            if (binRemaining[j] >= items[i]) {
                binRemaining[j] -= items[i];
                printf("Item %d of size %d placed in Bin %d\n", i + 1, items[i], j + 1);
                placed = 1;
                break;
            }
        }
        if (!placed) {
            binRemaining[binCount] -= items[i];
            printf("Item %d of size %d placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Number of bins required = %d\n", binCount);

    return 0;
}
