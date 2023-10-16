//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    int n1;
    printf("Enter a number to check: ");
    scanf("%d", &n1);
    if (n1 % 2 == 0)
        printf("%d is even", n1);
    else
        printf("%d is odd", n1);

    return 0;
}
