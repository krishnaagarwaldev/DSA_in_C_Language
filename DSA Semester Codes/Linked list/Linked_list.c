#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBegin() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
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
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
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
        newNode->next = head;
        head = newNode;
    } else {
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
        temp->next = newNode;
    }
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
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
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
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node at position 1.\n");
        return;
    }
    struct Node* temp = head;
    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Deleted node at position %d.\n", pos);
}

// Reverse the linked list
void reverseList() {
    struct Node* prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed.\n");
}

// Display linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Display in reverse order (without reversing list)
/*void displayReverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Reverse Display: ");
    // recursive logic inside this function only
    struct Node* temp = head;
    // stack simulation using recursion
    void rev(struct Node* node) {
        if (node == NULL) return;
        rev(node->next);
        printf("%d ", node->data);
    }
    rev(temp);
    printf("\n");
}*/

void displayReverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    displayReverse(temp->next);
    printf("%d ", temp->data);
}

// Menu
int main() {
    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Display Reverse\n");
        printf("9. Reverse Linked List\n");
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
            case 8: displayReverse(head); break;
            case 9: reverseList(); break;
            case 10: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
