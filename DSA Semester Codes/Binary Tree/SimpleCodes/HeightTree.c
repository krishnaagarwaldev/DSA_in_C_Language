#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0; // An empty tree has height 0
    }
    int leftHeight = height(root->left);   // Height of left subtree
    int rightHeight = height(root->right); // Height of right subtree

    // Height of tree = max(leftHeight, rightHeight) + 1
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    // Creating a simple tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of the tree: %d\n", height(root));

    return 0;
}
