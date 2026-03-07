#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int data;
    struct node *prev, *next;
};
struct node* head = NULL;

// Traverse forward
void traverse() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = head;
    printf("\nForward Traversal:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse printing using recursion
void printReverseRec(struct node* temp) {
    if (temp == NULL) return;
    printReverseRec(temp->next);
    printf("%d ", temp->data);
}

void reverseRecursion() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nReverse Print (Recursion):\n");
    printReverseRec(head);
    printf("\n");
}

// Reverse printing using prev traversal
void reverseTraversal() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) // move to last node
        temp = temp->next;

    printf("\nReverse Traversal (Using prev):\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Completely reverse DLL by swapping next and prev
void reverseDLL() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = NULL, *current = head;

    while (current != NULL) {
        // swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // move forward
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev; // update head
    }
    printf("\nDoubly Linked List completely reversed!\n");
}

// Insert at front
void insertAtFront() {
    int data;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

// Insert at end
void insertAtEnd() {
    int data;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }
    trav = head;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = temp;
    temp->prev = trav;
}

// Insert at position
void insertAtPosition() {
    int data, pos, i = 1;
    struct node *temp, *newnode;
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos == 1) {
        insertAtFront();
        return;
    }

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    temp = head;
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
    if (temp->next != NULL)
        temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;
}

// Delete first
void deleteFirst() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

// Delete end
void deleteEnd() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}

// Delete position
void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nEnter position : ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFirst();
        return;
    }

    temp = head;
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
    if (position->next != NULL)
        position->next->prev = temp;
    free(position);
}

// Driver Code
int main() {
    int choice;
    printf("\n*** Doubly Linked List Operations ***\n");
    printf("1  Traverse Forward\n");
    printf("2  Insert at Front\n");
    printf("3  Insert at End\n");
    printf("4  Insert at Position\n");
    printf("5  Delete First\n");
    printf("6  Delete End\n");
    printf("7  Delete at Position\n");
    printf("8  Reverse Print (Recursion)\n");
    printf("9  Reverse Print (Using prev)\n");
    printf("10 Reverse Entire DLL\n");
    printf("11 Exit\n");

    while (1) {
        printf("\nEnter Choice : ");
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
        case 9: reverseTraversal(); break;
        case 10: reverseDLL(); break;
        case 11: exit(0);
        default: printf("Incorrect Choice. Try Again.\n");
        }
    }
    return 0;
}
