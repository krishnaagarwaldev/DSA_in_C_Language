#include <stdio.h>
#include <stdlib.h>

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper function to print a path
void printPath(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++) {
        printf("%d", path[i]);
        if (i != pathLen - 1) printf("->");
    }
    printf("\n");
}

// Recursive function to find all root-to-leaf paths
void binaryTreePathsUtil(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;

    // Add current node to path
    path[pathLen] = root->data;
    pathLen++;

    // If it's a leaf, print the path
    if (root->left == NULL && root->right == NULL) {
        printPath(path, pathLen);
    } 
    else {
        // Recur for left and right subtrees
        binaryTreePathsUtil(root->left, path, pathLen);
        binaryTreePathsUtil(root->right, path, pathLen);
    }
}

// Function to start path finding
void binaryTreePaths(struct Node* root) {
    int path[1000];  // assuming max path length <= 1000
    binaryTreePathsUtil(root, path, 0);
}

// Driver Code
int main() {
    /*
           1
          / \
         2   3
          \
           5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("All root-to-leaf paths:\n");
    binaryTreePaths(root);

    return 0;
}
