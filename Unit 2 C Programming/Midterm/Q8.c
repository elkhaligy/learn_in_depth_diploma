#include <stdio.h>
#include <stdlib.h>

void rev_arr(int *arr, int n);

int main() {
    int n;
    printf("Enter number of data: ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    printf("Array before reversal: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    rev_arr(arr, n);

    printf("\nArray after reversal: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    return 0;
}

void rev_arr(int *arr, int n) {
    int tmp;
    for (int i = 0; i < n/2; ++i) {
        tmp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=tmp;
    }
}