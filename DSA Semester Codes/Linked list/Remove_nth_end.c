#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// insert at end
void insert(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

// display
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// remove N-th node from end
void removeNthFromEnd(int n) {
    int len = 0;
    struct Node* temp = head;

    // 1. find length
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    // if deleting head
    if (n == len) {
        struct Node* del = head;
        head = head->next;
        free(del);
        return;
    }
    // 2. move to (len-n)th node
    temp = head;
    for (int i = 1; i < len - n; i++) {
        temp = temp->next;
    }
    // 3. delete next node
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printf("Original list: ");
    display();

    removeNthFromEnd(2);  // remove 2nd node from end

    printf("After removal: ");
    display();

    return 0;
}
