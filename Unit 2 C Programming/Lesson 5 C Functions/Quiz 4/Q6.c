//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>


int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d",(n>>3)&1);

    return 0;
}
