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

// Function to find the height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to find the diameter of the tree
int diameter(struct Node* root) {
    if (root == NULL)
        return 0;

    // Get heights of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Get diameters of left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Diameter = max(leftDiameter, rightDiameter, leftHeight + rightHeight + 1)
    int maxDiameter = leftHeight + rightHeight + 1;
    if (leftDiameter > maxDiameter)
        maxDiameter = leftDiameter;
    if (rightDiameter > maxDiameter)
        maxDiameter = rightDiameter;

    return maxDiameter;
}

int main() {
    //Diameter of a tree is the number of nodes on the longest path between two leaves in the tree. eg. 4-2-1-3 or 5-2-1-3
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

    printf("Diameter of the tree: %d\n", diameter(root));

    return 0;
}
