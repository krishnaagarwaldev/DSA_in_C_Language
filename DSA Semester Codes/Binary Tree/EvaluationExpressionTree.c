#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// ----- Stack Implementation -----
struct stack {
    int top;
    struct node* arr[100];
} s;

void push(struct node* n) {
    s.arr[++s.top] = n;
}

struct node* pop() {
    return s.arr[s.top--];
}

// ----- Build Expression Tree from Postfix -----
struct node* buildTree(char postfix[]) {
    s.top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {  // operand is a digit
            push(newNode(ch));
        } else {            // operator
            struct node* t = newNode(ch);
            t->right = pop();
            t->left = pop();
            push(t);
        }
    }
    return (s.top == -1) ? NULL : pop();
}

// ----- Evaluate Expression Tree -----
int evaluate(struct node* root) {
    if (root == NULL) return 0;

    // if leaf node (operand), convert char -> int
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    // evaluate left and right subtrees
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);

    // apply operator
    switch (root->data) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
        case '^': return (int)pow(left_val, right_val);
    }
    return 0;
}

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct node* root = buildTree(postfix);

    if (root == NULL) {
        printf("Expression tree is empty.\n");
        return 0;
    }

    printf("Result of Expression = %d\n", evaluate(root));

    return 0;
}
