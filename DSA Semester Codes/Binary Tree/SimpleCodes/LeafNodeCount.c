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

// inorder traversal + count leaf nodes
void inorderCountLeaf(struct node* root, int *count) {
    if (root == NULL)
        return;

    // inorder => left, root, right
    inorderCountLeaf(root->left, count);

    // check if leaf node
    if (root->left == NULL && root->right == NULL) {
        (*count)++;
    }

    inorderCountLeaf(root->right, count);
}

int main() {
    // make a simple binary tree
    struct node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->right = createNode(60);

    int leafCount = 0;
    inorderCountLeaf(root, &leafCount);

    printf("Number of leaf nodes = %d\n", leafCount);

    return 0;
}
