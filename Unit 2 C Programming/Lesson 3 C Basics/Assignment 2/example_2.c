//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>
#include <stdbool.h>

int main() {
    char c;
    bool v;
    printf("Enter an alphabet: ");
    scanf("%c", &c);
    v = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if (v)
        printf("%c is a vowel.", c);
    else
        printf("%c is a consonant.", c);

    return 0;
}
