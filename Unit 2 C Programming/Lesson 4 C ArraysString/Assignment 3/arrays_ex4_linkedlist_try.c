//
// Created by Sirito on 18 Oct 23.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_list(struct node *head) {
    struct node* cur=head;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
}

int main() {
    struct node* head=NULL;
    int n,data;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&data);
        insert_at_end(&head,data);
    }
    display_list(head);
    return 0;
}
