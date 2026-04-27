#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;
struct Node* mergedHead = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Display function
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at end for List 1
void insertList1() {
    int value;
    printf("Enter value to insert into List 1: ");
    scanf("%d", &value);
    struct Node* newNode = createNode(value);
    if (head1 == NULL) {
        head1 = newNode;
    } else { //Insert at end
        struct Node* temp = head1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Insert at end for List 2
void insertList2() {
    int value;
    printf("Enter value to insert into List 2: ");
    scanf("%d", &value);
    struct Node* newNode = createNode(value);
    if (head2 == NULL) {
        head2 = newNode;
    } else { //Insert at end
        struct Node* temp = head2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Insert a node into merged list in sorted order
void insertSorted(int value) {
    struct Node* newNode = createNode(value);
    //Insert at beginning or before head
    if (mergedHead == NULL || value < mergedHead->data) {
        newNode->next = mergedHead;
        mergedHead = newNode;
        return;
    }
    //Insert in the "middle" or end
    struct Node* temp = mergedHead;
    while (temp->next != NULL && temp->next->data < value) //eg. 1,3,5 and value=4
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Merge two lists into sorted mergedHead
void mergeLists() {
    mergedHead = NULL; // clear previous merged list
    struct Node* temp = head1;
    while (temp != NULL) {
        insertSorted(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        insertSorted(temp->data);
        temp = temp->next;
    }
    printf("Merged sorted list: ");
    display(mergedHead);
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Merge Lists (sorted)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertList1(); break;
            case 2: insertList2(); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: mergeLists(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n"); break;
        }
    }
    return 0;
}
