#include <stdio.h>
#include <string.h>

void myFunc(char *str) {
    int n = strlen(str);
    int validity = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            validity = 1;
            break;
        }
    }


    double frequency[n];
    for (int i = 0; i < n; i++) {
        frequency[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i] == str[j]) {
                frequency[i]++;
            }
        }
    }

    int maxFrequency = 0;
    int sameFreq[n];
    int a = 0;


    for (int i = 0; i < n; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
        }
    }


    for (int i = 0; i < n; i++) {
        if (frequency[i] == maxFrequency) {
            sameFreq[a] = i;
            a++;
        }
    }


    double printFreq[a];
    for (int i = 0; i < a; i++) {
        printFreq[i] = str[sameFreq[i]];
    }


    double finalArr[a];
    for (int i = 0; i < a; i++) {
        finalArr[i] = printFreq[i];
    }


    double temp;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (finalArr[i] < finalArr[j]) {
                temp = finalArr[i];
                finalArr[i] = finalArr[j];
                finalArr[j] = temp;
            }
        }
    }

    double printer;
    double original = finalArr[0];

    if (validity == 1) {
        printf("String contains a number\n");
    }
    else {
        printf("String contains no number\n");
    }

    printf("String length: %d\n", n);

    printf("String first character: %c\n", str[0]);

    printf("String mode frequency is %d\n", maxFrequency);
    printf("String most frequent character: %c\n", (char)original);

    for (int i = 0; i < a; i++) {
        printer = finalArr[i];
        if (printer != original && i != 0) {
            printf("String most frequent character: %c\n", (char)finalArr[i]);
            original = printer;
        }
    }
}

int main() {
    char input[100];
    printf("Input a stream of text. Type 'exit' to terminate, either by itself or as the last word - anything beyond 'exit' will be ignored in this case\n");
    while (fgets(input, 100, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        myFunc(input);

    }
}