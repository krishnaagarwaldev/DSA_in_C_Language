#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find height of the tree
int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Count number of nodes at a given level
int countWidth(struct Node* root, int level) {
    if (root == NULL) return 0;
    if (level == 1) return 1;
    return countWidth(root->left, level - 1) + countWidth(root->right, level - 1);
}

// Maximum width of the tree
int maxWidth(struct Node* root) {
    int h = height(root);
    int maxW = 0;
    for (int i = 1; i <= h; i++) {
        int w = countWidth(root, i);
        if (w > maxW) maxW = w;
    }
    return maxW;
}

// Driver Code
int main() {
    /*
           1
          / \
         2   3
        / \   \
       4   5   8
                \
                 9
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);

    printf("Maximum width of the tree = %d\n", maxWidth(root));
    return 0;
}
