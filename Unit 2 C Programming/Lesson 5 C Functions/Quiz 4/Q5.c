//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>


int main() {
    int n, pos;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter bit position: ");
    scanf("%d", &pos);
    n = n&~(1<<pos);
    printf("%d",n);
    return 0;
}
