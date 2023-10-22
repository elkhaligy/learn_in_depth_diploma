#include <stdio.h>
#include <stdlib.h>

unsigned int unq_elements(const int *arr, int size);
int main() {
    int n;
    unsigned int ans;

    printf("Enter number of data: ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    ans = unq_elements(arr, n);
    printf("%d", ans);
    free(arr);
    return 0;
}
unsigned int unq_elements(const int *arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; ++i)
        ans ^= arr[i];
    return ans;
}