//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>


int string_length(char *s) {
    int cnt = 0;
    while (*(s+cnt) != 0)
        cnt++;
    return cnt-1;
}

int main() {
    char str[100], c;
    int ans;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    fflush(stdin);
    fflush(stdout);
    ans = string_length(str);
    printf("%d", ans);
    return 0;
}