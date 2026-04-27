#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int isEmpty() {
    return top == -1;
}

void sortedInsert(int x) {
    if (isEmpty() || x > stack[top]) {
        push(x);
        return;
    }
    int temp = pop();
    sortedInsert(x);
    push(temp);
}

void sortStack() {
    if (!isEmpty()) {
        int x = pop();
        sortStack();
        sortedInsert(x);
    }
}

void display() {
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void displayAscending() {
    printf("Stack (bottom to top): ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}


int main() {
    push(30);
    push(-5);
    push(18);
    push(14);
    push(-3);

    printf("Original Stack: ");
    display();

    sortStack();
    printf("Sorted Stack: ");
    display();
    displayAscending();
    return 0;
}
