#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push() {
    int data;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nHeap Overflow!\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", data);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("\nStack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nTop element: %d\n", top->data);
}

// Display all elements
void display() {
    if (top == NULL) {
        printf("\nStack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("\nStack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Driver code
int main() {
    int choice;
    printf("\n*** Stack using Linked List ***\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}
