#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX-1) { printf("Overflow\n"); return; }
    stack[++top] = x;
}
int pop() {
    if(top == -1) { printf("Underflow\n"); return -1; }
    return stack[top--];
}
int peek() {
    if(top == -1) { printf("Empty\n"); return -1; }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Top: %d\n", peek());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    return 0;
}
