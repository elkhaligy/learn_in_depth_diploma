//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>


int main() {
    char str[100];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%hhx", &str[i]);
//    for (int i = 0; i < n; ++i)
//        printf("%c ", str[i]);

    unsigned int result = 0;
    for (int i = 0; i < n; ++i)
        result = result * 10 + (str[i] - '0');
    printf("%u", result);
    return 0;
}
