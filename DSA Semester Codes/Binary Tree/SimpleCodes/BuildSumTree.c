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

// Function to convert the tree into a Sum Tree
// and return the total sum of subtree rooted at 'root'
int toSumTree(struct Node* root) {
    // Base condition
    if (root == NULL)
        return 0;

    // Recursively convert left and right subtrees
    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    
    int old_val = root->data;
    root->data = leftSum + rightSum;

    // Return sum of values under this subtree (including old value)
    return root->data + old_val;
}

// Inorder Traversal to print tree
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver Code
int main() {
    /*
           10
          /  \
         -2   6
        / \   / \
       8  -4 7   5
    */

    struct Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    printf("Inorder before Sum Tree: ");
    inorder(root);
    printf("\n");

    toSumTree(root);

    printf("Inorder after Sum Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
