//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100], ans[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    unsigned long long int len = strlen(str);
    for (int i = 0; i < len; ++i)
        ans[i] = str[len - i - 2];
    ans[len]='\0';
    printf("Reverse is: %s", ans);
    return 0;
}
