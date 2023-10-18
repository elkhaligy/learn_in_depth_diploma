//
// Created by Sirito on 18 Oct 23.
//

#include <stdio.h>

int main() {
    float arr_1[2][2], arr_2[2][2];
    printf("Enter first matrix elements:\n");
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf(" %f", &arr_1[i][j]);
        }
    printf("Enter second matrix elements:\n");
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf(" %f", &arr_2[i][j]);
        }
    printf("Sum of the two matrices:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.1f ",arr_1[i][j]+arr_2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
