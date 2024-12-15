#include <stdio.h>
#include <math.h>

void mathceil(double *x) {
    *x = ceil(*x);
}

void mathfloor(double *x) {
    *x = floor(*x);
}

void normceil(double *x) {
    if(*x == (int)*x) {
        *x = (int)*x;
    } else {
        *x = (int)(*x) + 1;
    }

}

void normfloor(double *x) {
    *x = (int)(*x);
}
int main() {
    double a = 591.29, b = 64.66, c = a, d = b;

    printf("Ceil of %lf", a);
    mathceil(&a);
    printf(" is: %d\n", (int)a);
    printf("Floor of %lf", b);
    mathfloor(&b);
    printf(" is: %d", (int)b);

    printf("\nWithout math.h ...\n");

    printf("Ceil of %lf", c);
    normceil(&c);
    printf(" is: %d\n", (int)c);
    printf("Floor of %lf", d);
    normfloor(&d);
    printf(" is: %d", (int)d);

    return 0;
}
