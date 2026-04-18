Aim:

To implement the nth Fibonacci term using recursion and iteration.

Algorithm:
Recursive
If n <= 1, return n.
Else return fib(n-1) + fib(n-2).
Iterative
Initialize a = 0, b = 1.
Repeat until nth term.
Print the result.

Full Program:

#include <stdio.h>

int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int fibIterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Fibonacci using recursion = %d\n", fibRecursive(n));
    printf("Fibonacci using iteration = %d\n", fibIterative(n));

    return 0;
}
