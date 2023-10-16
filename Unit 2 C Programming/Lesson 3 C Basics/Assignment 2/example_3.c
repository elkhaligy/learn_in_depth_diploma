//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    float n1, n2, n3,ans;
    printf("Enter three numbers: ");
    scanf("%f %f %f", &n1, &n2, &n3);
    ans = ((n1>n2) ? (((n1>n3) ? n1:n3)) : ((n2>n3) ? n2:n3));
    printf("%f",ans);
    return 0;
}
