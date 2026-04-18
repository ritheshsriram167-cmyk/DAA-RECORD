Aim:

To implement the Tower of Hanoi problem using recursion and display the sequence of moves.

Algorithm:

Read the number of disks n.
If n == 1, move disk from source to destination.
Otherwise:
Move n-1 disks from source to auxiliary.
Move nth disk from source to destination.
Move n-1 disks from auxiliary to destination.
Print all moves.

Full Program:
#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
