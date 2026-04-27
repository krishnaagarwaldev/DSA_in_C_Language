#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure of a Tree Node
struct Node {
    char *val;                // stores operator or operand
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(char *val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = strdup(val);
    node->left = node->right = NULL;
    return node;
}

// Stack implementation for building tree
struct Node* stack[100];
int top = -1;

// Push node to stack
void push(struct Node* node) {
    stack[++top] = node;
}

// Pop node from stack
struct Node* pop() {
    return stack[top--];
}

// Check if a token is an operator
int isOperator(char *s) {
    return (!strcmp(s, "+") || !strcmp(s, "-") || !strcmp(s, "*") || !strcmp(s, "/"));
}

// Build Expression Tree from Postfix Expression
struct Node* buildTree(char *tokens[], int n) {
    for (int i = 0; i < n; i++) {
        char *token = tokens[i];

        // If operand → create node and push
        if (!isOperator(token)) {
            push(newNode(token));
        } 
        // If operator → pop two nodes and make them children
        else {
            struct Node* right = pop();
            struct Node* left = pop();
            struct Node* node = newNode(token);
            node->left = left;
            node->right = right;
            push(node);
        }
    }
    // Top of stack is root
    return pop();
}

// Evaluate the expression tree recursively
int evaluate(struct Node* root) {
    // If it's a leaf node (operand)
    if (!root->left && !root->right)
        return atoi(root->val); // convert string to int

    // Evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply the operator
    if (!strcmp(root->val, "+")) return leftVal + rightVal;
    if (!strcmp(root->val, "-")) return leftVal - rightVal;
    if (!strcmp(root->val, "*")) return leftVal * rightVal;
    if (!strcmp(root->val, "/")) return leftVal / rightVal;

    return 0;
}

// Driver Code (Example)
int main() {
    // Example: postfix expression ["3","4","+","2","*","7","/"]
    char *tokens[] = {"3", "4", "+", "2", "*", "7", "/"};
    int n = sizeof(tokens) / sizeof(tokens[0]);

    struct Node* root = buildTree(tokens, n);

    printf("Result = %d\n", evaluate(root)); // Expected: ((3+4)*2)/7 = 2

    return 0;
}
