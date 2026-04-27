#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>
#include <math.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push function
void push(int val) {
    stack[++top] = val;
}

// Pop function
int pop() {
    return stack[top--];
}

int main() {
    char postfix[SIZE];
    int i, op1, op2, result;

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        // If operand → push to stack
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');  // convert char to int
        }
        else { // operator → pop two operands
            op2 = pop();
            op1 = pop();

            switch(postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = (int)pow(op1, op2); break;
            }

            push(result); // push result back to stack
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}
