#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue (Insert)
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue (Remove)
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Recursive function to reverse queue
void reverseQueue() {
    if (isEmpty())
        return;
    int x = dequeue();
    reverseQueue();   // Reverse remaining elements
    enqueue(x);       // Add removed element at the end
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}
