//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    float n1, n2, tmp;
    printf("Enter value of a: ");
    scanf("%f", &n1);
    printf("Enter value of b: ");
    scanf("%f", &n2);
    tmp = n1;
    n1 = n2;
    n2 = tmp;
    printf("Value of a after swapping:%.2f\n",n1);
    printf("Value of b after swapping:%.2f",n2);
    return 0;
}
