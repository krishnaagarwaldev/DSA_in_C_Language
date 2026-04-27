#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// pop function
char pop() {
    if (top == -1) return '\0'; // empty stack
    return stack[top--];
}

// function to check matching pair
int match(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// function to check valid parenthesis
int isValid(char exp[]) {
    top = -1;  // reset stack

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c); // push opening bracket
        }
        else if (c == ')' || c == '}' || c == ']') {
            char temp = pop();
            if (!match(temp, c)) return 0; // not matching
        }
    }

    // if stack is empty => valid
    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isValid(exp))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}
