#include<stdio.h>


int main() {
    char alphabits[27];
    char *ptr = alphabits;
    for (char i = 0; i < 26; i++) {
        *ptr = i + 'A';
        ptr++;
    }
    ptr = alphabits;
    printf("The alphabets are: \n");
    for (int i = 0; i < 26; ++i) {
        printf("%c ", *ptr);
        ptr++;
    }
    return 0;
}
