#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
struct node {
    int info;
    struct node *next;
};
struct node* start = NULL;

// Forward traversal
void traverse() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = start;
    printf("\nForward Traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse printing using recursion
void printReverseRec(struct node* temp) {
    if (temp == NULL) return;
    printReverseRec(temp->next);
    printf("%d ", temp->info);
}

void reverseRecursion() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nReverse Print (Recursion):\n");
    printReverseRec(start);
    printf("\n");
}

// Completely reverse the linked list (iterative method)
void reverseList() {
    struct node *prev = NULL, *current = start, *next = NULL;

    while (current != NULL) {
        next = current->next;   // save next node
        current->next = prev;   // reverse link
        prev = current;         // move prev forward
        current = next;         // move current forward
    }
    start = prev;
    printf("\nLinked List completely reversed!\n");
}

// Insert at front
void insertAtFront() {
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = start;
    start = temp;
}

// Insert at end
void insertAtEnd() {
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        return;
    }
    trav = start;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = temp;
}

// Insert at specific position
void insertAtPosition() {
    int data, pos, i = 1;
    struct node *temp, *newnode;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertAtFront();
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;

    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete first node
void deleteFirst() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = start;
    start = start->next;
    free(temp);
}

// Delete end node
void deleteEnd() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node* temp = start;
    if (start->next == NULL) {  // Only one node
        free(start);
        start = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete specific position
void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFirst();
        return;
    }

    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    position = temp->next;
    temp->next = position->next;
    free(position);
}

// Driver code
int main() {
    int choice;
    printf("\n*** Singly Linked List Operations ***\n");
    printf("1  Traverse Forward\n");
    printf("2  Insert at Front\n");
    printf("3  Insert at End\n");
    printf("4  Insert at Position\n");
    printf("5  Delete First\n");
    printf("6  Delete End\n");
    printf("7  Delete at Position\n");
    printf("8  Reverse Print (Recursion)\n");
    printf("9  Reverse Entire Linked List\n");
    printf("10 Exit\n");

    while (1) {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: traverse(); break;
            case 2: insertAtFront(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: deleteFirst(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: reverseRecursion(); break;
            case 9: reverseList(); break;
            case 10: exit(0);
            default: printf("Incorrect Choice. Try Again.\n");
        }
    }
    return 0;
}

