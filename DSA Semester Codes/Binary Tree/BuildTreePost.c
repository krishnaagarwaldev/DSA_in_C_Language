#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    if(data == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int postorder[] = {-1, -1, 2, -1, -1, 3, 1}; // example
    int n = sizeof(postorder)/sizeof(postorder[0]);
    int index = n - 1;

    Node* root = buildTreePost(postorder, &index);

    printf("Inorder traversal of tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
