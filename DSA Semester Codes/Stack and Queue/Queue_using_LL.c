#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int x) { //Insert at the end
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if(rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}
int dequeue() { //Delete from the beginning
    if(front == NULL) { 
        printf("Underflow\n"); 
        return -1; 
    }
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(temp);
    return val;
}
int peek() {
    if(front == NULL) { printf("Empty\n"); return -1; }
    return front->data;
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
