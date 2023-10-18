//
// Created by Sirito on 18 Oct 23.
//


#include <stdio.h>

unsigned long long int power(int n, int p);

unsigned long long int power(int n, int p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    return n * power(n, p - 1);
}

int main() {
    int n, p;
    unsigned long long int ans;
    printf("Enter base number: ");
    scanf("%d", &n);
    printf("Enter power: ");
    scanf("%d", &p);
    ans = power(n, p);
    printf("%d^%d = %lld", n,p, ans);
    return 0;
}
