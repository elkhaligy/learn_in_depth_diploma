//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int max_length = 100, cnt = 0;
    char c;
    char str[100];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    fflush(stdin);
    fflush(stdout);
    printf("Enter character to find the frequency of it: ");
    scanf("%c", &c);
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == c)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}
