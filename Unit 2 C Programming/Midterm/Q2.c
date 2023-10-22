#include <stdio.h>

double sqr_root(int n);

int main() {
    int n;
    double ans;
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = sqr_root(n);
    printf("%.3lf", ans);
    return 0;
}

double sqr_root(int n) {
    float i;
    for (i = 0.0001f; i * i < (double)n; i += 0.0001f);
    return i;
}