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

// Function to count nodes in the binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0; // No node in an empty tree
    }
    // Count of nodes = 1 (current node) + nodes in left subtree + nodes in right subtree
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return 1 + leftCount + rightCount;
    //return 1 + countNodes(root->left) + countNodes(root->right);
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

    printf("Total number of nodes in the tree: %d\n", countNodes(root));

    return 0;
}
