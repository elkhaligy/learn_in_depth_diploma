#include<stdio.h>

int main() {
    int *ab;
    int m;
    m = 29;
    printf("Address of m: 0x%p\n", &m);
    printf("Value of m: %d\n", m);

    ab = &m;
    printf("Now ab is assigned with the address of m.\n");
    printf("Address of pointer ab: 0x%p\n",&ab);
    printf("Content of pointer ab: %d\n",*ab);

    *ab=34;
    printf("The value of m is 34 now.\n");
    printf("Address of pointer ab: 0x%p\n",&ab);
    printf("Content of pointer ab: %d\n",*ab);

    *ab=7;
    printf("The value of m is 34 now.\n");
    printf("Address of  m: 0x%p\n",&m);
    printf("Content of m: %d\n",m);
    return 0;
}
