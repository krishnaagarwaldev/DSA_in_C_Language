#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
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

// Function to print all nodes at Kth level
void printKthLevel(struct Node* root, int k) {
    if (root == NULL)
        return;

    if (k == 1) {
        // Current node is at Kth level
        printf("%d ", root->data);
        return;
    }

    // Recur for left and right subtrees with level reduced by 1
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

int main() {
    // Example tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4  5  6  7

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int k;
    printf("Enter level K: ");
    scanf("%d", &k);

    printf("Nodes at level %d: ", k);
    printKthLevel(root, k);
    printf("\n");

    return 0;
}
