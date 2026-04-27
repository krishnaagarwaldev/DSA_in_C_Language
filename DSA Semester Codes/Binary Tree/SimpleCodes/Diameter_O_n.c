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

// Global variable to store the diameter
int ans = 0;

// Function to calculate height and update diameter
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Update global diameter 
    // Max diameter at this node = leftHeight + rightHeight + 1
    if (leftHeight + rightHeight + 1 > ans)
        ans = leftHeight + rightHeight + 1;

    // Return height of current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Wrapper function to calculate diameter
int diameter(struct Node* root) {
    ans = 0; // Reset for safety
    height(root);
    return ans;
}

int main() {
    // Creating a sample tree
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

    printf("Diameter of the tree: %d\n", diameter(root));

    return 0;
}
