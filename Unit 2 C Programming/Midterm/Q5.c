#include <stdio.h>

unsigned int cnt_bin(int n);

int main() {
    int n;
    unsigned int cnt;
    printf("Enter a number: ");
    scanf("%d", &n);
    cnt = cnt_bin(n);
    printf("Number of 1's in %d is %d", n, cnt);
    return 0;
}

unsigned int cnt_bin(int n) {
    unsigned int ans = 0;
    while (n != 0) {
        if (n & 1)
            ans++;
        n = n >> 1;
    }
    return ans;
}