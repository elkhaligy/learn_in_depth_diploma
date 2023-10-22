//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>


int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    if(n%3==0)
        printf("%d ==> 0",n);
    else
        printf("%d ==> 1",n);

    return 0;
}
