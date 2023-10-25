#include <stdio.h>

#define PI 3.14
#define area(r) (PI*r*r)
int main() {
    float r;
    float area;
    printf("Enter radius of a circle: ");
    scanf("%f",&r);
    area = area(r);
    printf("Area of the circle = %.2f",area);
    return 0;
}