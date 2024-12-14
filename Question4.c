#include <stdio.h>


void dectohex(int num) {

    if (num == 0) {
        return;
    }

    int rem = num % 16;
    dectohex(num / 16);

    if (rem < 10) {
        printf("%d", rem);
    } else {
        printf("%c", 'A' + rem - 10);
    }
}

int main() {
    int num = 450;
    dectohex(num);
}
