#include <stdio.h>

int prime(int num);


int main() {
    int n1, n2;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    printf("Prime numbers between %d and %d are: ", n1, n2);
    for (int i = n1; i < n2; ++i)
        if (!prime(i))
            printf("%d ", i);
    return 0;
}


int prime(int num) {
    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0)
            return 1;
    return 0;
}