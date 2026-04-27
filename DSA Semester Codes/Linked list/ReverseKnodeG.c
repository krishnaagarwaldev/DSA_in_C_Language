#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // global head

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
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

// Display linked list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse nodes in groups of k (directly updates global head)
struct Node* reverseKNodes(struct Node* start, int k) {
    struct Node* curr = start;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Count if at least k nodes exist
    struct Node* temp = start;
    int nodeCount = 0;
    while (temp != NULL && nodeCount < k) {
        nodeCount++;
        temp = temp->next;
    }
    if (nodeCount < k)  // less than k nodes, return as is
        return start;

    // Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Connect with remaining part
    start->next = reverseKNodes(next, k);

    return prev; // new head of this block
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

    // 🔥 directly update global head here, no wrapper
    head = reverseKNodes(head, k);

    printf("List after reversing in  🔥 groups of %d: ", k);
    display();

    return 0;
}
