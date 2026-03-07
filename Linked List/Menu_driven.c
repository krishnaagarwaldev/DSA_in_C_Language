#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Global head pointer

// Function to create a new node with user input
struct Node* createNode() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBegin() {
    struct Node *newNode = createNode();
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertAtEnd() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at end.\n");
}

// Insert at given position
void insertAtPosition() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtBegin();
        return;
    }

    struct Node *newNode = createNode();
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
    printf("Node deleted from end.\n");
}

// Delete from given position
void deleteAtPosition() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        printf("Invalid position or empty list!\n");
        return;
    }
    if (pos == 1) {
        deleteAtBegin();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Node deleted from position %d.\n", pos);
}

// Display list normally
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display list in reverse (recursive)
void displayReverse(struct Node *node) {
    if (node == NULL)
        return;
    displayReverse(node->next);
    printf("%d -> ", node->data);
}

int main() {
    int choice;
        // printf("\n----- Menu -----\n");
        // printf("1. Insert at Beginning\n");
        // printf("2. Insert at End\n");
        // printf("3. Insert at Position\n");
        // printf("4. Delete from Beginning\n");
        // printf("5. Delete from End\n");
        // printf("6. Delete from Position\n");
        // printf("7. Display List\n");
        // printf("8. Display List in Reverse\n");
        // printf("9. Exit\n");
        // printf("Enter choice: ");
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBegin(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteAtBegin(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteAtPosition(); break;
            case 7: displayList(); break;
            case 8:
                if (head == NULL)
                    printf("List is empty!\n");
                else {
                    printf("Reverse Linked List: ");
                    displayReverse(head);
                    printf("NULL\n");
                }
                break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
