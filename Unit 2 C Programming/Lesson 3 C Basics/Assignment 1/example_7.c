//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    int n1, n2, tmp;
    printf("Enter value of a: ");
    scanf("%d", &n1);
    printf("Enter value of b: ");
    scanf("%d", &n2);
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
    printf("Value of a after swapping:%d\n", n1);
    printf("Value of b after swapping:%d", n2);
    return 0;
}
