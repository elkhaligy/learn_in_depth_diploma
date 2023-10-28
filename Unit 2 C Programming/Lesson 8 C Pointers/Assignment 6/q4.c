//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memory_dump(char *start, int size);

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *) calloc(n, sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    int *ptr;
    ptr = &arr[n - 1];
    for (int i = 0; i < n; ++i) {
        printf("%d ", *ptr);
        ptr--;
    }
    return 0;
}

void memory_dump(char *start, int size) {
    for (int i = 0; i < size; ++i) {
        printf("At 0x%p: %x \n", start, (unsigned char) *start);
        start++;
    }
}