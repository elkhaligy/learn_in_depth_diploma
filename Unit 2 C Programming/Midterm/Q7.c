#include <stdio.h>

int sum_nums(int n);

int main() {
    int n, ans;
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = sum_nums(n);
    printf("%d", ans);
    return 0;
}

int sum_nums(int n) {
    if (n == 0)
        return 0;
    return n + sum_nums(n - 1);
}