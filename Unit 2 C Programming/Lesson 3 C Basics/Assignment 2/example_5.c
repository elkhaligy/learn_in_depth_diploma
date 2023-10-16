//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        printf("%c is an alphabet", c);
    else
        printf("%c is not an alphabet", c);
    return 0;
}
