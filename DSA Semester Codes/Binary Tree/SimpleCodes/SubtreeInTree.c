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

// Function to check if two trees are identical
int isIdentical(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Function to check if t2 is a subtree of t1
int isSubtree(struct Node* t1, struct Node* t2) {
    if (t2 == NULL)
        return 1; // An empty tree is always a subtree
    if (t1 == NULL)
        return 0; // t2 is not empty but t1 is empty

    // If trees match from current node, return true
    if (isIdentical(t1, t2))
        return 1;

    // Otherwise, check left and right subtrees
    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

int main() {
    // Main tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node* t1 = createNode(1);
    t1->left = createNode(2);
    t1->right = createNode(3);
    t1->left->left = createNode(4);
    t1->left->right = createNode(5);

    // Subtree
    //      2
    //     / \
    //    4   5
    struct Node* t2 = createNode(2);
    t2->left = createNode(4);
    t2->right = createNode(5);

    if (isSubtree(t1, t2))
        printf("t2 is a subtree of t1.\n");
    else
        printf("t2 is not a subtree of t1.\n");

    return 0;
}
