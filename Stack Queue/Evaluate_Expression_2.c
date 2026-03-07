#include <stdio.h>
#include <math.h>
#define SIZE 100

int numStack[SIZE];
int numTop = -1;

char opStack[SIZE];
int opTop = -1;

// Check if character is digit
int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Check if operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

// Push/Pop for numbers
void pushNum(int value) { numStack[++numTop] = value; }
int popNum() { return numStack[numTop--]; }

// Push/Pop for operators
void pushOp(char op) { opStack[++opTop] = op; }
char popOp() { return opStack[opTop--]; }

// Operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Perform operation
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '%') return a % b;
    if (op == '^') return (int)pow(a, b);
    return 0;
}

// For debugging (optional)
void printStacks() {
    printf("\nNumbers stack: ");
    for (int i = 0; i <= numTop; i++) printf("%d ", numStack[i]);
    printf("\nOperators stack: ");
    for (int i = 0; i <= opTop; i++) printf("%c ", opStack[i]);
    printf("\n");
}

// Main evaluation logic
int evaluate(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == ' ') continue;  // Skip spaces

        // If number
        if (isDigit(ch)) {
            pushNum(ch - '0');
        }
        // If opening parenthesis
        else if (ch == '(') {
            pushOp(ch);
        }
        // If closing parenthesis
        else if (ch == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                int b = popNum();
                int a = popNum();
                char op = popOp();
                pushNum(applyOp(a, b, op));
            }
            popOp();  // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(ch)) {
                int b = popNum();
                int a = popNum();
                char op = popOp();
                pushNum(applyOp(a, b, op));
            }
            pushOp(ch);
        }

        // Debugging view
        printStacks();
    }

    // Apply remaining operators
    while (opTop != -1) {
        int b = popNum();
        int a = popNum();
        char op = popOp();
        pushNum(applyOp(a, b, op));
        printStacks();
    }

    return popNum();
}

int main() {
    char exp[SIZE];

    printf("Enter expression (supports +, -, *, /, ^, %%, parentheses): ");
    scanf("%[^\n]s", exp);

    int result = evaluate(exp);
    printf("\nFinal Result = %d\n", result);

    return 0;
}
