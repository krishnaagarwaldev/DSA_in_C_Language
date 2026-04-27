#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

struct node* buildTree(char postfix[]) {
    struct node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            stack[++top] = newNode(ch);
        } else {
            struct node* t = newNode(ch);
            t->right = stack[top--];
            t->left = stack[top--];
            stack[++top] = t;
        }
    }
    //return (top == -1) ? NULL : stack[top];
    if (top == -1) {
        return NULL;
    } else {
        return stack[top];
    }
}

void inorder(struct node* root) {
    if (root == NULL) return;
    if (root->left != NULL) printf("(");
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
    if (root->right != NULL) printf(")");
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
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

    //Invalid postfix expression
    if (root->left == NULL && root->right == NULL) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    printf("Infix Expression   : ");
    inorder(root);
    printf("\n");

    printf("Prefix Expression  : ");
    preorder(root);
    printf("\n");

    printf("Postfix Expression : ");
    postorder(root);
    printf("\n");

    return 0;
}
