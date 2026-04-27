#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

// Function to insert at end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display list
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    //printf("NULL\n");
}

// Function to convert list into array, sort, then update back
void sortList() {
    if (head == NULL) {
        printf("List is empty, nothing to sort.\n");
        return;
    }

    // Count nodes
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Copy into array
    int arr[count], i = 0;
    temp = head;
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    // Sort array (simple bubble sort)
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    // Copy back into linked list
    temp = head;
    i = 0;
    while (temp != NULL) {
        temp->data = arr[i++];
        temp = temp->next;
    }

    printf("List sorted successfully.\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Sort Linked List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                sortList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
