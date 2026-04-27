#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push function
void push(char c) {
    stack[++top] = c;
}

// Pop function
char pop() {
    return stack[top--];
}

// Peek top of stack
char peek() {
    return stack[top];
}

// Return precedence of operator
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check right associativity
int isRightAssociative(char op) {
    if (op == '^') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop();  // remove '('
        }
        else { // operator
            while (top != -1 && precedence(peek()) > 0 &&
                  ((isRightAssociative(ch) == 0 && precedence(ch) <= precedence(peek())) ||
                   (isRightAssociative(ch) == 1 && precedence(ch) < precedence(peek())))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Reverse string and swap brackets (for prefix)
void reverseAndSwap(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

// Convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[SIZE], tempPostfix[SIZE];
    strcpy(revInfix, infix);

    reverseAndSwap(revInfix);           // Step 1: reverse infix
    infixToPostfix(revInfix, tempPostfix); // Step 2: postfix of reversed
    reverseAndSwap(tempPostfix);        // Step 3: reverse postfix → prefix

    strcpy(prefix, tempPostfix);
}

int main() {
    char infix[SIZE], postfix[SIZE], prefix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
