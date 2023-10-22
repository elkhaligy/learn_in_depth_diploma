#include <stdio.h>

int sum_of_digits(int n);
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d", sum_of_digits(n));
    return 0;
}

int sum_of_digits(int n){
    int rem, sum = 0;
    while (n != 0) {
        rem = n % 10;
        n = n / 10;
        sum += rem;
    }
    return sum;
}