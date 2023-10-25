#include <stdio.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

void disp_info(struct student s1);

int main() {
    struct student s1;
    printf("Enter information of a student\n");
    printf("Enter name: ");
    gets(s1.name);
    printf("Enter roll number: ");
    scanf("%d", &(s1.roll));
    printf("Enter marks: ");
    scanf("%f", &(s1.marks));
    disp_info(s1);
    return 0;
}

void disp_info(struct student s1) {
    printf("Displaying information\n");
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);
    printf("Marks: %.2f", s1.marks);
}