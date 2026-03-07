#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------------- STACK FOR VALUES ----------------
int valStack[MAX];
int valTop = -1;

void pushVal(int val) {
    valStack[++valTop] = val;
}

int popVal() {
    if (valTop == -1) {
        printf("Error: Value stack underflow!\n");
        exit(1);
    }
    return valStack[valTop--];
}

int peekVal() {
    if (valTop == -1) return -1;
    return valStack[valTop];
}

// ---------------- STACK FOR OPERATORS ----------------
char opStack[MAX];
int opTop = -1;

void pushOp(char op) {
    opStack[++opTop] = op;
}

char popOp() {
    if (opTop == -1) {
        printf("Error: Operator stack underflow!\n");
        exit(1);
    }
    return opStack[opTop--];
}

char peekOp() {
    if (opTop == -1) return '\0';
    return opStack[opTop];
}

// ---------------- UTILITY FUNCTIONS ----------------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            exit(1);
        }
        return a / b;
    }
    return 0;
}

// Apply the top operator to top two values
void processTop() {
    int b = popVal();
    int a = popVal();
    char op = popOp();
    pushVal(applyOp(a, b, op));
}

// ---------------- EVALUATE EXPRESSION ----------------
int evaluate(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // Skip spaces
        if (ch == ' ') continue;

        // If digit, build the number
        if (ch >= '0' && ch <= '9') {
            int num = 0;
            while (exp[i] >= '0' && exp[i] <= '9') {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            pushVal(num);
        }
        // Opening parenthesis
        else if (ch == '(') {
            pushOp(ch);
        }
        // Closing parenthesis
        else if (ch == ')') {
            while (opTop != -1 && peekOp() != '(') {
                processTop();
            }
            if (opTop == -1) {
                printf("Error: Mismatched parentheses!\n");
                exit(1);
            }
            popOp(); // remove '('
        }
        // Operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (opTop != -1 && precedence(peekOp()) >= precedence(ch)) {
                processTop();
            }
            pushOp(ch);
        }
        else {
            printf("Error: Invalid character '%c'!\n", ch);
            exit(1);
        }
    }

    // Process remaining operators
    while (opTop != -1) {
        if (peekOp() == '(') {
            printf("Error: Mismatched parentheses!\n");
            exit(1);
        }
        processTop();
    }

    return popVal();
}

// ---------------- MAIN ----------------
int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    fgets(exp, MAX, stdin);

    int result = evaluate(exp);
    printf("Result: %d\n", result);

    return 0;
}
 