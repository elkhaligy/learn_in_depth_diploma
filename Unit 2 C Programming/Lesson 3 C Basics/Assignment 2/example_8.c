//
// Created by Sirito on 17 Oct 23.
//
#include <stdio.h>

int main() {
    float n1, n2, res;
    char op = 1;
    printf("Enter operator + or - or * or / :");
    scanf(" %c", &op);
    printf("Enter two operands: ");
    scanf("%f %f", &n1, &n2);
    switch (op) {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            if (n2 == 0) {
                printf("Can't divide by zero!");
                return 0;
            }
            res = n1 / n2;
            break;
        default:
            printf("Wrong Operator");
            return 0;
    }
    printf("\n%.2f %c %.2f = %.2f", n1, op, n2, res);
    return 0;
}