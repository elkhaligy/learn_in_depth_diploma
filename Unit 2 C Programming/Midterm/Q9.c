#include <stdio.h>
#include <string.h>

void rev_str(char *str);

int main() {
    char str[100];
    gets(str);
    printf("String before reverse: %s\n", str);
    rev_str(str);
    printf("String after reverse: %s\n", str);
    return 0;
}
void rev_str(char *str) {
    char *token;
    char str_rev[100];
    token = strtok(str, " "); // strtok function is used to separate each sub string in a string
    int tok_len;
    int cnt;

    // Reverse each word in the string: Ex -> Hello world -> olleH dlrow
    cnt = 0;
    while (token != NULL) {
        tok_len = (int) strlen(token);
        for (int i = tok_len - 1; i >= 0; i--) {
            str_rev[cnt] = token[i];
            cnt += 1;
            //printf("%c", token[i]);
        }
        str_rev[cnt] = ' ';
        cnt += 1;
        //printf(" ");
        token = strtok(NULL, " ");
    }
    //printf("\n%s", str_rev);

    // Reverse the whole string: Ex ->  world Hello
    cnt = 0;
    //printf("\n");
    for (int j = (int) strlen(str_rev) - 2; j >= 0; j--) {
        str[cnt] = str_rev[j];
        cnt += 1;
        //  printf("%c", str_rev[j]);
    }
    str[cnt] = 0;
}
