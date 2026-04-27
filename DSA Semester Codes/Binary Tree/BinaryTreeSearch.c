#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *root = NULL;   // global root

// Create new node
struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Insert function
void insert() {
    int x;
    printf("Enter value to insert: ");
    scanf("%d", &x);

    struct Node *newNode = createNode(x);

    if (root == NULL) {
        root = newNode;
        return;
    }

    struct Node *curr = root, *parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (x < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// Inorder Traversal (LNR)
void inorder(struct Node *node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void displayInorder() {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

// Search function
void search() {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node *curr = root;
    while (curr != NULL) {
        if (key == curr->data) {
            printf("Found %d in tree\n", key);
            return;
        }
        else if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    printf("%d not found in tree\n", key);
}

// Find minimum node (for deletion helper)
struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

// Delete function
struct Node* deleteNode(struct Node* node, int key) {
    if (node == NULL) return node;

    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        // Case 1 & 2: node with 0 or 1 child
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        // Case 3: node with 2 children
        struct Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void deleteValue() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("%d deleted (if it existed)\n", key);
}

// Main Menu
int main() {
    int choice;
    printf("\n--- Binary Search Tree Menu ---\n");
    printf("1. Insert\n");
    printf("2. Display (Inorder)\n");
    printf("3. Search\n");
    printf("4. Delete\n");
    printf("5. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: displayInorder(); break;
            case 3: search(); break;
            case 4: deleteValue(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
