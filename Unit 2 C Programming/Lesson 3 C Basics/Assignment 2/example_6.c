//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    int a, sum = 0;
    printf("Enter an integer:");
    scanf("%d", &a);
    for (int i = 1; i <= a; ++i) {
        sum += i;
    }
    printf("Sum = %d",sum);

    return 0;
}
