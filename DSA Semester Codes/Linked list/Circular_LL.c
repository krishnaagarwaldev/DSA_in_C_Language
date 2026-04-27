#include <stdio.h>
#include <stdlib.h>

// Structure for node
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the last node
struct Node* last = NULL;

// Function to insert at beginning
void insertBegin() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    newNode->data = val;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted at beginning.\n");
}

// Function to insert at end
void insertEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    int val;
    printf("Enter data: ");
    scanf("%d", &val);
    newNode->data = val;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted at end.\n");
}

// Function to insert at a given position
void insertPosition() {
    int pos, val, count = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;

    if (last == NULL) {
        printf("List empty, inserting as first node.\n");
        insertBegin();
        return;
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &val);
    newNode->data = val;

    // Count nodes
    temp = last->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    if (pos <= 1) {
        insertBegin();
        free(newNode);
        return;
    }

    if (pos > count) {
        insertEnd();
        free(newNode);
        return;
    }

    temp = last->next;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == last)
        last = newNode;

    printf("Inserted at position %d.\n", pos);
}

// Function to delete from beginning
void deleteBegin() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;

    if (last->next == last)
        last = NULL;
    else
        last->next = temp->next;

    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

// Function to delete from end
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next, *prev = NULL;

    if (temp == last) {
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        last = NULL;
        return;
    }

    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = last->next;
    printf("Deleted node: %d\n", temp->data);
    free(temp);
    last = prev;
}

// Function to delete at a specific position
void deletePosition() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos, count = 1;
    struct Node *temp = last->next, *prev = NULL;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Count total nodes
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    if (pos <= 1) {
        deleteBegin();
        return;
    }

    if (pos >= count) {
        deleteEnd();
        return;
    }

    temp = last->next;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node* del = temp->next;
    temp->next = del->next;

    if (del == last)
        last = temp;

    printf("Deleted node: %d\n", del->data);
    free(del);
}

// Function to display the list
void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Function to reverse circular linked list
/*
void reverse() {
    if (last == NULL || last->next == last) {
        printf("List reversed (empty or single node).\n");
        return;
    }

    struct Node *prev = last, *curr = last->next, *nextNode;

    do {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != last->next);

    last = curr->next;
    printf("List reversed successfully.\n");
}
*/

// Fixed reverse for circular linked list
void reverse() {
    if (last == NULL || last->next == last) {
        // empty or single-node list: nothing to do
        printf("List reversed (empty or single node).\n");
        return;
    }

    // 1) break the circle to make it a normal singly linked list
    struct Node *head = last->next; // original head
    last->next = NULL;              // break circular link

    // 2) reverse the singly-linked list
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // 3) 'prev' is new head (old last). 'head' (old head) is now tail.
    last = head;        // new last is the old head
    last->next = prev;  // close the circle: tail->next = new head

    printf("List reversed successfully.\n");
}


// Menu
int main() {
    int choice;
    printf("\n--- Circular Linked List Menu ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from Position\n");
    printf("7. Display\n");
    printf("8. Reverse\n"); //Not working properly
    printf("9. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: display(); break;
            case 8: reverse(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
