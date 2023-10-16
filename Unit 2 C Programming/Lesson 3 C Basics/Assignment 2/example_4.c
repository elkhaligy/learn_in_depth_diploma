//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    float n1;
    printf("Enter a number: ");
    scanf("%f", &n1);
    if (n1)
        printf("%.2f is positive", n1);
    else if(n1 == 0)
        printf("You entered a zero");
    else
        printf("%.2f is negative",n1);
    return 0;
}
