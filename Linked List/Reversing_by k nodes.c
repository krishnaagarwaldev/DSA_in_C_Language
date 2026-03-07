#include <stdio.h>
#include <stdlib.h>

// Linked list node definition
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper: Get length of list
int getLength(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Reverse nodes in k-group
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k <= 1) return head;

    int length = getLength(head); // Total length of list
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *prevGroupEnd = &dummy, *curr, *prev, *next;
    
    while (length >= k) {
        curr = prevGroupEnd->next; // First node in the group
        prev = NULL;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Adjust pointers to connect reversed part
        struct ListNode* temp = prevGroupEnd->next; // old head becomes tail
        prevGroupEnd->next = prev;                  // link prevGroupEnd to new head
        temp->next = curr;                          // link new tail to next group

        // Move prevGroupEnd to the end of reversed group
        prevGroupEnd = temp;

        length -= k; // Reduce length by processed group
    }

    return dummy.next;
}

// Helper: Print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        head = head->next;
        if (head) printf(" -> ");
    }
    printf("\n");
}

int main() {
    int n, k, val;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d: ", k);
    printList(head);

    return 0;
}
