//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <string.h>


void reverse(char *str,int len) {
    if(len==0)
        return;
    printf("%c",str[len-1]);
    reverse(str,len-1);
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    reverse(str,strlen(str));
    return 0;
}
