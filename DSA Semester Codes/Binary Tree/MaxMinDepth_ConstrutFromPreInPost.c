// Construct Binary Tree from Preorder + Inorder
// Construct Binary Tree from Inorder + Postorder
// Maximum Depth of Binary Tree
// Minimum Depth of Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// -------- 1. Construct from Preorder + Inorder --------
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

//Inorder = [9,3,15,20,7] --> root = 3, left (0,0) = [9], right (2,4) = [15,20,7]
//Preorder = [3,9,20,15,7]
struct Node* buildTreePreIn(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = newNode(preorder[*preIndex]); //node = 3 (search 3 in inorder array) it is at index 1
    (*preIndex)++;

    if (inStart == inEnd) return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->left = buildTreePreIn(inorder, preorder, inStart, inIndex - 1, preIndex); //node->left = buildTreePreIn(inorder, preorder, 0, 0, preIndex); [9]
    node->right = buildTreePreIn(inorder, preorder, inIndex + 1, inEnd, preIndex); //node->right = buildTreePreIn(inorder, preorder, 2, 4, preIndex); [15,20,7]

    return node;
}

// -------- 2. Construct from Inorder + Postorder --------
struct Node* buildTreeInPost(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->right = buildTreeInPost(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeInPost(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// -------- 3. Maximum Depth --------
int maxDepth(struct Node* root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    //return (l > r ? l : r) + 1;
    if (l > r) return l + 1;
    else return r + 1;
}

// -------- 4. Minimum Depth --------
int minDepth(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1; // leaf node
    // if one of the subtrees is NULL, we need to consider the depth of the other subtree

    if (root->left == NULL) return minDepth(root->right) + 1; // if left subtree is NULL, go right
    if (root->right == NULL) return minDepth(root->left) + 1; // if right subtree is NULL, go left

    int l = minDepth(root->left);
    int r = minDepth(root->right);
    //return (l < r ? l : r) + 1;
    if (l < r) return l + 1;
    else return r + 1;
}

// -------- Utility Traversals --------
void inorderPrint(struct Node* root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

int main() {
    // Example for Preorder + Inorder
    int inorder1[] = {4, 2, 5, 1, 6, 3};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n1 = sizeof(inorder1) / sizeof(inorder1[0]);
    int preIndex = 0;
    struct Node* root1 = buildTreePreIn(inorder1, preorder, 0, n1 - 1, &preIndex);

    printf("Inorder of tree (Pre+In): ");
    inorderPrint(root1);
    printf("\nMax Depth: %d\n", maxDepth(root1));
    printf("Min Depth: %d\n\n", minDepth(root1));

    // Example for Inorder + Postorder
    int inorder2[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int n2 = sizeof(inorder2) / sizeof(inorder2[0]);
    int postIndex = n2 - 1;
    struct Node* root2 = buildTreeInPost(inorder2, postorder, 0, n2 - 1, &postIndex);

    printf("Inorder of tree (In+Post): ");
    inorderPrint(root2);
    printf("\nMax Depth: %d\n", maxDepth(root2));
    printf("Min Depth: %d\n", minDepth(root2));

    return 0;
}
