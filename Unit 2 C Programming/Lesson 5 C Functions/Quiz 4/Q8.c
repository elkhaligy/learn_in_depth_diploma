//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,t;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    printf("Enter target: ");
    scanf("%d", &t);

    for (int i = n-1; i >= 0; i--) {
        if(arr[i] == t){
            printf("Last occurrence of %d is at index %d",t,i);
            return 0;
        }
    }
    printf("Element not found");
    return 0;
}
