//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float avg = 0;
    printf("Enter number of data: ");
    scanf("%d", &n);
    float *arr = malloc(sizeof(float) * n);
    for (int i = 0; i < n; ++i) {
        printf("%d. Enter number: ", i + 1);
        scanf("%f", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        avg += (float) arr[i];
    }
    avg /= (float) n;
    printf("%.2f", avg);
    free(arr);
    return 0;
}
