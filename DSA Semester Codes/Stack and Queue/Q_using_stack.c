/*Alright 👍
You want Queue using Stack in C (with arrays).
That means:

Enqueue(x): push into stack1.

Dequeue():

If stack2 is empty → move all elements from stack1 to stack2.

Then pop from stack2.

This way, order is preserved like a real queue (FIFO).*/

#include <stdio.h>
#define MAX 100

// Two stacks
int s1[MAX], s2[MAX];
int t1 = -1, t2 = -1;

// Stack helper functions
void push1(int x) {
    if(t1 == MAX-1) { printf("Stack1 Overflow\n"); return; }
    s1[++t1] = x;
}
void push2(int x) {
    if(t2 == MAX-1) { printf("Stack2 Overflow\n"); return; }
    s2[++t2] = x;
}
int pop1() {
    if(t1 == -1) { return -1; }
    return s1[t1--];
}
int pop2() {
    if(t2 == -1) { return -1; }
    return s2[t2--];
}
int isEmpty1() { return t1 == -1; }
int isEmpty2() { return t2 == -1; }

// Queue functions using stacks
void enqueue(int x) {
    push1(x);
}

int dequeue() {
    if(isEmpty1() && isEmpty2()) {
        printf("Queue Empty\n");
        return -1;
    }
    if(isEmpty2()) {
        while(!isEmpty1()) {
            push2(pop1());
        }
    }
    return pop2();
}

int peek() {
    if(isEmpty1() && isEmpty2()) {
        printf("Queue Empty\n");
        return -1;
    }
    if(isEmpty2()) {
        while(!isEmpty1()) {
            push2(pop1());
        }
    }
    return s2[t2]; // top of s2 is front of queue
}

// Driver
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front: %d\n", peek());     // 10
    printf("Dequeue: %d\n", dequeue()); // 10
    printf("Front: %d\n", peek());     // 20
    printf("Dequeue: %d\n", dequeue()); // 20
    printf("Dequeue: %d\n", dequeue()); // 30
    dequeue(); // Queue empty
    return 0;
}
