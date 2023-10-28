//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <string.h>

void memory_dump(char *start, int size);

int main() {
    char str[100], ans[100];
    char *str_p = str, *rev_p = ans;

    printf("Enter a string: ");
    gets(str);

    int len = (int) strlen(str);
    int i = len;
    while (i >= 0) {
        *rev_p = *(str_p + i - 1);
        rev_p++;
        i--;
    }
    printf("%s\n", ans);
    return 0;
}

void memory_dump(char *start, int size) {
    for (int i = 0; i < size; ++i) {
        printf("At 0x%p: %x \n", start, (unsigned char) *start);
        start++;
    }
}