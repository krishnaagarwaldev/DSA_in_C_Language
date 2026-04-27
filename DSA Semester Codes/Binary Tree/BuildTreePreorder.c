#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    if(data == -1) return NULL; // -1 represents NULL
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to build tree from preorder array
Node* buildTree(int preorder[], int* index, int n) {
    if (*index >= n) return NULL;

    int value = preorder[*index];
    (*index)++;

    if (value == -1) return NULL;

    Node* root = createNode(value);
    root->left = buildTree(preorder, index, n);
    root->right = buildTree(preorder, index, n);

    return root;
}

// Build tree from postorder
Node* buildTreePost(int postorder[], int* index) {
    if (*index < 0) return NULL;

    int value = postorder[*index];
    (*index)--;

    if (value == -1) return NULL;

    Node* root = createNode(value);
    // Important: right subtree first, then left
    root->right = buildTreePost(postorder, index);
    root->left = buildTreePost(postorder, index);

    return root;
}


// Function to print tree in inorder for verification
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int preorder[] = {1, 2, -1, -1, 3, -1, -1};
    int n1 = sizeof(preorder) / sizeof(preorder[0]);
    int index1 = 0;

    Node* root1 = buildTree(preorder, &index1, n1);

    printf("Inorder traversal of the tree: ");
    inorder(root1);
    printf("\n");
    
    
    
    int postorder[] = {-1, -1, 2, -1, -1, 3, 1}; // example
    int n2 = sizeof(postorder)/sizeof(postorder[0]);
    int index2 = n2 - 1;

    Node* root2 = buildTreePost(postorder, &index2);

    printf("Inorder traversal of the tree: ");
    inorder(root2);
    printf("\n");

    return 0;
}
