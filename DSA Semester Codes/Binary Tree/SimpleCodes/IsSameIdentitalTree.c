#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if two trees are identical
int isIdentical(struct Node* root1, struct Node* root2) {
    // Both empty -> identical
    if (root1 == NULL && root2 == NULL)
        return 1;

    // One empty, one not -> not identical
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Check current node data and recursively check left & right subtrees
    bool isLeftSame = isIdentical(root1->left, root2->left);
    bool isRightSame = isIdentical(root1->right, root2->right);

    return (root1->data == root2->data) && isLeftSame && isRightSame;
}

int main() {
    // Creating first tree
    //        1
    //       / \
    //      2   3
    struct Node* tree1 = createNode(1);
    tree1->left = createNode(2);
    tree1->right = createNode(3);

    // Creating second tree
    //        1
    //       / \
    //      2   3
    struct Node* tree2 = createNode(1);
    tree2->left = createNode(2);
    tree2->right = createNode(3);

    if (isIdentical(tree1, tree2))
        printf("The trees are identical.\n");
    else
        printf("The trees are not identical.\n");

    return 0;
}
