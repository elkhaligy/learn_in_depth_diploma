#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
};
void disp_info(struct student s1[], int size);
int main() {
    int size;
    printf("Enter number of students you want to store: ");
    scanf("%d", &size);
    struct student *s1 = malloc(sizeof(struct student) * size);
    printf("Enter information of students\n");
    for (int i = 0; i < size; ++i) {
        s1[i].roll = i + 1;
        printf("For roll number %d\n", s1[i].roll);
        printf("Enter name: ");
        scanf("%s", s1[i].name);

        printf("Enter marks: ");
        scanf("%f", &(s1[i].marks));
        printf("\n");
    }
    disp_info(s1, size);
    return 0;
}
void disp_info(struct student s1[], int size) {
    printf("Displaying information of students\n");
    for (int i = 0; i < size; ++i) {
        printf("Information for roll number %d\n", s1[i].roll);
        printf("Name: %s\n", s1[i].name);
        printf("Marks: %.2f", s1[i].marks);
        printf("\n");
    }
}