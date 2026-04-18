Aim:

To implement a randomized algorithm for searching an element in an array.

Algorithm:

Read array elements and target.
Randomly select unchecked indices.
Compare selected value with target.
If found, print index.
Otherwise continue until all checked.
  
Full Program:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int n, arr[100], target;
    int checked[100] = {0}, count = 0;

    srand(time(0));

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target element: ");
    scanf("%d", &target);

    while (count < n) {
        int index = rand() % n;

        if (checked[index] == 0) {
            checked[index] = 1;
            count++;

            printf("Checking index %d, value %d\n", index, arr[index]);

            if (arr[index] == target) {
                printf("Element found at index %d\n", index);
                return 0;
            }
        }
    }

    printf("Element not found\n");
    return 0;
}
