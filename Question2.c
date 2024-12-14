#include <stdio.h>

void fibonacci(int n) {
    long fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < n; i++) {
        printf("%ld ", fib[i]);
    }
}

long rfibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return rfibonacci(n - 1) + rfibonacci(n - 2);
    }
}

void printr(int n) {
    if (n == 0) {
        printf("0 ");
        return;
    }
    printr(n-1);
    printf("%ld ", rfibonacci(n));
}

int main() {
    int n = 30;
    printf("Iterative Fibonacci: ");
        fibonacci(n);
    printf("\nRecursive Fibonacci: ");
        printr(n-1);
    return 0;
}
/* In terms of readibility, the iterative fibonacci is easier to understand as you are using an array which allows you
 * to track the fibonacci sequence as the for loop iterates. The recursive fibonacci uses two functions, one of them to
 * assist in printing the entire sequence and may be more complex to understand & follow along. The recursive function
 * gets harder to track as n takes larger values.
 *
 * In terms of stack frame usage, the iterative function has a constant stack frame usage and uses a fixed amount of memory.
 * For the recursive function, a stack frame is added for every recursive call. Furthermore, with large values of n,
 * one can easily notice how rapid the iterative implementation computes the fibonacci sequence as opposed to the recursive
 * implementation. */
