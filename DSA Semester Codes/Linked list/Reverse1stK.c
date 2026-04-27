#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // global head

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse first k nodes
void reverseByK(int k) {
    if (head == NULL || k <= 1) return;

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Connect old head (now last in reversed part) to remaining nodes
    head->next = curr;

    // Update head to new head
    head = prev;
}

// Driver code
int main() {
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(val);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original List: ");
    display();

    reverseByK(k);

    printf("List after reversing first %d nodes: ", k);
    display();

    return 0;
}
