//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>


int main() {
    int arr[100], n, a, l;
    printf("Enter number of data: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &a);
    printf("Enter the location: ");
    scanf("%d", &l);
    for (int i = n; i >= l; i--)
        arr[i] = arr[i - 1];
    n++;
    arr[l - 1] = a;

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    return 0;
}
