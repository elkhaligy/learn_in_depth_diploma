//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>


unsigned long long int fac(int n);

unsigned long long int fac(int n) {
    if(n==0)
        return 1;
    return n*fac(n-1);
}

int main() {
    int n;
    unsigned long long int ans;
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = fac(n);
    printf("%lld",ans);
    return 0;
}
