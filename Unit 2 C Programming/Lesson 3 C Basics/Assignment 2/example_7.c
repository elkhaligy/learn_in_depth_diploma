//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long ans=1;
    if (n < 0)
        return 0;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    int a;
    unsigned long long ans;
    printf("Enter an integer:");
    scanf("%d", &a);
    ans = factorial(a);
    if (ans == 0)
        printf("Error, Factorial of a negative number doesn't exist!");
    else
        printf("Factorial %lld", ans);
    return 0;
}