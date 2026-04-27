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

// Morris Inorder Traversal
void morrisInorder(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            // No left child → print and move right
            printf("%d ", current->data);
            current = current->right;
        } else {
            // Find inorder predecessor
            struct Node* pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL) {
                // Make current as right child of predecessor
                pre->right = current;
                current = current->left;
            } else {
                // Revert changes (thread) and print current
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

// Driver Code
int main() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Morris Inorder Traversal: ");
    morrisInorder(root); // Expected: 4 2 5 1 3
    printf("\n");

    return 0;
}
