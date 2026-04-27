#include <stdio.h>
#include <stdlib.h>

// structure of node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// inorder traversal + sum of nodes
void inorderSum(struct node* root, int *sum) {
    if (root == NULL)
        return;

    inorderSum(root->left, sum);    // traverse left
    *sum += root->data;             // add current node value
    inorderSum(root->right, sum);   // traverse right
}

int sumNodes(struct node* root) {
    if (root == NULL) {
        return 0; // Empty tree has sum 0
    }
    // Sum = current node's data + sum of left subtree + sum of right subtree
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    return root->data + leftSum + rightSum;
    //return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    // create a sample binary tree
    struct node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->right = createNode(60);

    int totalSum = 0;
    inorderSum(root, &totalSum);  // pass by reference
    printf("Sum of all nodes = %d\n", totalSum);

    printf("Sum of all nodes (using return) = %d\n", sumNodes(root));

    return 0;
}
