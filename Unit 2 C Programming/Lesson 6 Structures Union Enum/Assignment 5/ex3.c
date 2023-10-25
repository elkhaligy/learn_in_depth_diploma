#include <stdio.h>

struct num {
    float real;
    float img;
};
struct num add_cmplx(struct num n1, struct num n2);
int main() {
    struct num n1, n2, ans;
    printf("Enter information of 1st complex number\n");
    printf("Enter real and imaginary: ");
    scanf("%f%f", &(n1.real), &(n1.img));

    printf("Enter information of 2st complex number\n");
    printf("Enter real and imaginary: ");
    scanf("%f%f", &(n2.real), &(n2.img));

    ans = add_cmplx(n1, n2);
    printf("Sum=%.1f+%.1fi", ans.real, ans.img);
    return 0;
}

struct num add_cmplx(struct num n1, struct num n2) {
    struct num tmp;
    tmp.real = n1.real + n2.real;
    tmp.img = n1.img + n2.img;
    return tmp;
}

