#include <stdio.h>
#define MAX 100

int queue[MAX], front=-1, rear=-1;

void enqueue(int x) {
    if(rear == MAX-1) { printf("Overflow\n"); return; }
    if(front == -1) front = 0;
    queue[++rear] = x;
}
int dequeue() {
    if(front == -1) { printf("Underflow\n"); return -1; }
    int val = queue[front++];
    if(front > rear) front = rear = -1; // reset
    return val;
}
int peek() {
    if(front == -1) { printf("Empty\n"); return -1; }
    return queue[front];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Front: %d\n", peek());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    return 0;
}
