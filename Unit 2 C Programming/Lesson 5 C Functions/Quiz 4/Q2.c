//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>

void swap(int *a, int *b, int *a_size, int *b_size);
void prnt_arr(int *a, int size);



int main() {
    int a[100], b[100], tmp[100], a_size, b_size;
    printf("Enter number of elements of array (a): ");
    scanf("%d", &a_size);
    printf("Enter elements of array (a): ");
    for (int i = 0; i < a_size; ++i)
        scanf("%d", &a[i]);
    printf("Enter number of elements of array (b): ");
    scanf("%d", &b_size);
    printf("Enter elements of array (b): ");
    for (int i = 0; i < b_size; ++i)
        scanf("%d", &b[i]);

    printf("Array (a) before swapping: ");
    prnt_arr(a, a_size);
    printf("\n");
    printf("Array (b) before swapping: ");
    prnt_arr(b, b_size);

    swap(a, b, &a_size, &b_size);


    printf("\n");
    printf("Array (a) after swapping: ");
    for (int i = 0; i < a_size; ++i)
        printf("%d ", a[i]);

    printf("\n");
    printf("Array (b) after swapping: ");
    for (int i = 0; i < b_size; ++i)
        printf("%d ", b[i]);
    return 0;
}

void swap(int *a, int *b, int *a_size, int *b_size) {
    int tmp[100];
    for (int i = 0; i < *a_size; ++i)
        tmp[i] = a[i];
    for (int i = 0; i < *b_size; ++i)
        a[i] = b[i];
    for (int i = 0; i < *a_size; ++i)
        b[i] = tmp[i];
    int temp_len = *a_size;
    *a_size = *b_size;
    *b_size = temp_len;
}

void prnt_arr(int *a, int size) {

    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
}