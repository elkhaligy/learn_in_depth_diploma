#include <stdio.h>
#include <limits.h>

#define MAX(a, b) (((a)>(b))?(a):(b))

int max_ones(int n);

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("%d", max_ones(n));
    return 0;
}

int max_ones(int n) {
    int ans = 0;
    int max = INT_MIN;
    while (n != 0) {
        if (!(n & 1)) {
            n = n >> 1;
            while (n & 1) {
                ans++;
                n = n >> 1;
            }
            max = MAX(ans,max);
            ans=0;
        }
    }
    return max;
}