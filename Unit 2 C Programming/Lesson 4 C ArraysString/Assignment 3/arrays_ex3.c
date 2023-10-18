//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    float **arr = malloc(sizeof(float *) * r);
    for (int i = 0; i < r; ++i)
        arr[i] = malloc(sizeof(float) * c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%f", &arr[i][j]);
        }

    printf("Entered Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.1f ", arr[i][j]);
        }
        printf("\n");
    }

    float **ans = malloc(sizeof(float *) * c);
    for (int i = 0; i < c; ++i)
        ans[i] = malloc(sizeof(float) * r);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            ans[j][i] = arr[i][j];
        }

    printf("Transpose Matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%.1f ", ans[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; ++i) {
        free(arr[i]);
    }
    for (int i = 0; i < c; ++i) {
        free(ans[i]);
    }
    free(arr);
    free(ans);
    return 0;
}
