#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Global pointers
struct Node *head1 = NULL, *head2 = NULL, *result = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end
void append1() {
    int n;
    scanf("%d", &n);
    struct Node *temp = NULL, *newNode;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        newNode = createNode(val);
        if (head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void append2() {
    int n;
    scanf("%d", &n);
    struct Node *temp = NULL, *newNode;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        newNode = createNode(val);
        if (head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Function to reverse a linked list
void reverse(struct Node** headRef) {
    struct Node *prev = NULL, *curr = *headRef, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *headRef = prev;
}

// Function to add two linked list numbers
void addLists() {
    reverse(&head1);
    reverse(&head2);

    struct Node *p = head1;
    struct Node *q = head2;
    struct Node *temp = NULL, *newNode;
    int carry = 0;

    while (p != NULL || q != NULL || carry) {
        int x = (p != NULL) ? p->data : 0;
        int y = (q != NULL) ? q->data : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        newNode = createNode(sum % 10);

        if (result == NULL) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }

    reverse(&result);
}

// Function to print linked list
void printList() {
    struct Node* temp = result;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("Enter number of digits and digits for first number:\n");
    append1();

    printf("Enter number of digits and digits for second number:\n");
    append2();

    addLists();

    printf("Sum: ");
    printList();

    return 0;
}
