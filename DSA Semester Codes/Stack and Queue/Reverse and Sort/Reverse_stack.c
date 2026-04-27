#include <stdio.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int x){ stack[++top] = x; }
int pop(){ return stack[top--]; }
int isEmpty(){ return top == -1; }

void insertBottom(int x) {
    if (isEmpty()) { push(x); return; }
    int temp = pop();
    insertBottom(x);
    push(temp);
}

void reverse() {
    if (!isEmpty()) {
        int temp = pop();
        reverse();
        insertBottom(temp);
    }
}

void display(){
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main(){
    push(1); push(2); push(3); push(4); push(5);
    printf("Original Stack: ");
    display();
    reverse();
    printf("Reversed Stack: ");
    display();
}
