#include <stdio.h>
#include <stdlib.h>

struct node {
    int base;
    int power;
    struct node* next;
};

// Function to sort polynomial terms in descending order of power
void sort(struct node* head) {
    struct node* i;
    struct node* j;
    int temp1, temp2;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->power < j->power) {
                // Swap coefficients
                temp1 = i->base;
                i->base = j->base;
                j->base = temp1;

                // Swap powers
                temp2 = i->power;
                i->power = j->power;
                j->power = temp2;
            }
        }
    }
}

// Function to add two polynomials and print result
void add(struct node* head1, struct node* head2) {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->power == temp2->power) {
            printf("%d %d ", temp1->base + temp2->base, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->power > temp2->power) {
            printf("%d %d ", temp1->base, temp1->power);
            temp1 = temp1->next;
        } else {
            printf("%d %d ", temp2->base, temp2->power);
            temp2 = temp2->next;
        }
    }

    while (temp1) {
        printf("%d %d ", temp1->base, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2) {
        printf("%d %d ", temp2->base, temp2->power);
        temp2 = temp2->next;
    }
}

int main() {
    struct node *p1 = NULL, *p2 = NULL;
    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp1, *temp2;
    int size1, size2;

    // Input for polynomial 1
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        p1 = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d", &p1->base, &p1->power);
        p1->next = NULL;
        if (head1 == NULL) {
            head1 = p1;
            temp1 = p1;
        } else {
            temp1->next = p1;
            temp1 = p1;
        }
    }

    // Input for polynomial 2
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        p2 = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d", &p2->base, &p2->power);
        p2->next = NULL;
        if (head2 == NULL) {
            head2 = p2;
            temp2 = p2;
        } else {
            temp2->next = p2;
            temp2 = p2;
        }
    }

    // Sort both polynomials
    sort(head1);
    sort(head2);

    // Add and display the result
    add(head1, head2);

    return 0;
}
