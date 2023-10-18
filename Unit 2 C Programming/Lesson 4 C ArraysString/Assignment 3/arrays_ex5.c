//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
    int n;
    float t;
    printf("Enter number of data: ");
    scanf("%d", &n);
    float *arr = malloc(sizeof(float) * n);

    printf("Enter data: ");
    for (int i = 0; i < n; ++i)
        scanf("%f", &arr[i]);

    printf("Enter element to be searched: ");
    scanf("%f", &t);

    for (int i = 0; i < n; ++i) {
        if(arr[i]==t){
            printf("Element found at location: %d",i+1);
            break;
        }
    }
    free(arr);
    return 0;
}
