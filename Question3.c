#include <stdio.h>


int igcd(int x, int y) {
   while (y != 0) {
       int t = x % y;
       x = y;
       y = t;
   }
    return x;

}

int rgcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return rgcd(y, x % y);
}

int main() {
    int x = 90, y = 60;
    printf("Iterative GCD of %d and %d is %d\n", x, y, igcd(x, y));
    printf("Recursive GCD of %d and %d: %d\n", x, y, rgcd(x, y));

}

/* In terms of readibility, the iterative GCD implementation is slightly more complex to understand and implement but
 * not that difficult. It uses a temporary variable t which allows us to swap the contents of x and y. The recursive GCD
 * implementation is very easy to understand and is a direct implementation of the Euclid function itself. Without a doubt,
 * the recursive GCD function is what most would come up with when prompted with this question.
 *
 * In terms of stack frame usage, the iterative function keeps a constant stack frame usage whilst the recursive function
 * adds a new stack frame for each recursive call. Both functions seem to compute the GCD in a relatively equal time frame. */
