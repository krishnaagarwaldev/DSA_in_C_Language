/*✅ Idea (Reverse + Middle Method)
Use slow & fast pointer to find the middle of the list.
Reverse the second half of the list.
Compare the first half with the reversed second half.
Restore the list (optional).
Decide if it’s palindrome.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at end
void insert() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display list
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse a linked list (helper function)
struct Node* reverseList(struct Node* node) {
    struct Node* prev = NULL;
    struct Node* curr = node;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // new head
}

// Check palindrome using reverse + middle
void checkPalindrome() {
    if (head == NULL || head->next == NULL) {
        printf("Palindrome Linked List ✅\n");
        return;
    }

    // Step 1: Find middle
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct Node* secondHalf = reverseList(slow->next);

    // Step 3: Compare both halves
    struct Node* p1 = head;
    struct Node* p2 = secondHalf;
    int flag = 1;
    while (p2 != NULL) {
        if (p1->data != p2->data) {
            flag = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // Step 4: Restore second half (optional)
    slow->next = reverseList(secondHalf);

    // Step 5: Result
    if (flag)
        printf("Palindrome Linked List\n");
    else
        printf("Not Palindrome\n");
}

// Menu
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Check Palindrome\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: checkPalindrome(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
