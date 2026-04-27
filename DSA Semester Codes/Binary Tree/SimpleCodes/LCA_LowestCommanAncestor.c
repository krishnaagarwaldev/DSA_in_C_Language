#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------
// STRUCTURE DEFINITION
// ----------------------------------------------

// Definition of a binary tree node
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

// ----------------------------------------------
// LOWEST COMMON ANCESTOR FUNCTION
// ----------------------------------------------

/*
    🔹 Problem (LeetCode 236):
       Given a binary tree, and two nodes p and q,
       find their **Lowest Common Ancestor (LCA)**.

    🔹 Definition:
       The Lowest Common Ancestor (LCA) of two nodes p and q
       is the **lowest (deepest)** node in the tree
       that has both p and q as **descendants**.
       (A node can be a descendant of itself.)

       Example:
                3
               / \
              5   1
             / \ / \
            6  2 0  8
              / \
             7   4

       LCA(5, 1) = 3
       LCA(6, 4) = 5
*/

// Recursive function to find the LCA
struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    // Base case: if tree is empty or current node is one of p or q
    if (root == NULL || root == p || root == q)
        return root;

    // Recurse for left and right subtrees
    struct Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct Node* rightLCA = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-NULL, current node is the LCA
    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    // Otherwise, return non-null side (either left or right)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// ----------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------
int main() {
    /*
        Example Tree:
                3
               / \
              5   1
             / \ / \
            6  2 0  8
              / \
             7   4
    */

    struct Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->right->left = createNode(0);
    root->right->right = createNode(8);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    // Let's find LCA of 5 and 1
    struct Node* p = root->left;   // Node 5
    struct Node* q = root->right;  // Node 1

    struct Node* lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is: %d\n", p->data, q->data, lca->data);

    // Example 2: LCA of 6 and 4
    p = root->left->left;          // Node 6
    q = root->left->right->right;  // Node 4
    lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is: %d\n", p->data, q->data, lca->data);

    return 0;
}
