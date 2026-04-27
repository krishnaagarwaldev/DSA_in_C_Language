#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at beginning
void insertBegin() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("Inserted at beginning.\n");
}

// Insert at end
void insertEnd() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted at end.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted at end.\n");
}

// Insert at position
void insertMiddle() {
    int pos, value, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        head = newNode;
        printf("Inserted at position %d.\n", pos);
        return;
    }

    struct Node* temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    printf("Inserted at position %d.\n", pos);
}

// Delete at beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted from beginning.\n");
}

// Delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

// Delete at position
void deleteMiddle() {
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        printf("Deleted node at position 1.\n");
        return;
    }

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Deleted node at position %d.\n", pos);
}

// Display forward
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display reverse without changing list
void displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Completely reverse the list
void reverseList() {
    struct Node* curr = head;
    struct Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("List reversed completely.\n");
}

// Menu
int main() {
    int choice;
    while (1) {
        printf("\n--- MENU (Doubly Linked List) ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Reverse\n");
        printf("9. Reverse Entire List\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: insertMiddle(); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: deleteMiddle(); break;
            case 7: display(); break;
            case 8: displayReverse(); break;
            case 9: reverseList(); break;
            case 10: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
