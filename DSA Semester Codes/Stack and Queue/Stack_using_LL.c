#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int x) { //Insert at the beginning
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}
int pop() { //Delete from the beginning
    if(top == NULL) { printf("Underflow\n"); return -1; }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}
int peek() {
    if(top == NULL) { printf("Empty\n"); return -1; }
    return top->data;
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
