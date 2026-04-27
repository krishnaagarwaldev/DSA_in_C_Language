#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Pointer to keep track of next node in flattened list
struct Node* prev = NULL;

// Recursive flatten function (reverse preorder: right -> left -> root)
void flatten(struct Node* root) {
    if (root == NULL) return;

    // Recur on right subtree
    flatten(root->right);

    // Recur on left subtree
    flatten(root->left);

    // Update pointers
    root->right = prev;
    root->left = NULL;

    // Move prev to current node
    prev = root;
}

// Print the flattened linked list
void printList(struct Node* root) {
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->right;
    }
    printf("\n");
}

// Driver Code
int main() {
    /*
           1
          / \
         2   5
        / \   \
       3   4   6
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printf("Flattened Linked List: ");
    printList(root); // Expected: 1 2 3 4 5 6

    return 0;
}
