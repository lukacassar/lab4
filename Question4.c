#include <stdio.h>
#include <string.h>


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

void rev(char text[], int n) {
    int len = strlen(text);
      if (n >= len/2) {
        return;
    }


    char temp = text[n];
    text[n] = text[len - 1 - n];
    text[len - 1 - n] = temp;
    rev(text, n+1);
}

int main() {
    int num = 40;
    dectohex(num);

    char text[40] = "woof meow 123";
    rev(text, 0);
    printf("\nThe reversed string: %s", text);
}
