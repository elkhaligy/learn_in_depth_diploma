//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>
#include <string.h>

int main() {
    char users[3][20] = {"Ahmed", "Shehab", "Omar"};
    char str[100];
    gets(str);
    for (int i = 0; i < 3; ++i) {
        if(!strcmp(str,users[i])) {
            printf("Name found!");
            return 0;
        }
    }
    printf("Name not found!");

    return 0;
}
