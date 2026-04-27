#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Maximum width function using recursion with position indexing
void maxWidthRec(struct Node* root, int level, unsigned int index, unsigned int firstIndex[], int *maxW) {
    if (!root) return;

    // If first node at this level, store its index
    if (firstIndex[level] == -1) firstIndex[level] = index;

    // Compute width at this level
    int width = index - firstIndex[level] + 1;
    if (width > *maxW) *maxW = width;

    // Recur for left and right children
    maxWidthRec(root->left, level + 1, 2 * index, firstIndex, maxW);
    maxWidthRec(root->right, level + 1, 2 * index + 1, firstIndex, maxW);
}

// Driver Code
int main() {
    /*
            1
           / \
          3   2
         / \   \
        5   3   9
    */

    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(9);

    int maxW = 0;
    unsigned int firstIndex[1000]; // assuming max depth <= 1000
    for (int i = 0; i < 1000; i++) firstIndex[i] = -1;

    maxWidthRec(root, 0, 1, firstIndex, &maxW);

    printf("Maximum width of the tree = %d\n", maxW); // Output: 4

    return 0;
}
