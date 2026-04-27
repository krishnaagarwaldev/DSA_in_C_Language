#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for(int i=start;i<=end;i++)
        if(inorder[i]==value) return i;
    return -1;
}

// Build tree from preorder and inorder
Node* buildTreePreIn(int preorder[], int inorder[], int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int curr = preorder[*preIndex];
    (*preIndex)++;
    Node* node = createNode(curr);

    if (inStart == inEnd) return node;

    int inIndex = search(inorder, inStart, inEnd, curr);

    node->left = buildTreePreIn(preorder, inorder, preIndex, inStart, inIndex-1);
    node->right = buildTreePreIn(preorder, inorder, preIndex, inIndex+1, inEnd);

    return node;
}

void inorderPrint(Node* root) {
    if(root==NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int inorder[]  = {4, 2, 5, 1, 6, 3};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    int preIndex = 0;

    Node* root = buildTreePreIn(preorder, inorder, &preIndex, 0, n-1);

    printf("Inorder traversal: ");
    inorderPrint(root);
    printf("\n");

    return 0;
}
