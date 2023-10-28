#include<stdio.h>

struct employee {
    char *name;
    int id;
};

int main() {
    struct employee emp1 = {"Alex", 1000}, emp2 = {"John", 2000};

    // Array which contents are pointers to structure ✅
    struct employee *arr[] = {&emp1, &emp2};

    // Pointer to the above array ✅
    // pointer p to array of 2 elements of type struct employee pointer
    struct employee *(*p)[2] = &arr;

    printf("Second Employee name: %s\n",(*(*p+1))->name);
    printf("Second Employee ID: %d",(*(*p+1))->id);

    return 0;
}
