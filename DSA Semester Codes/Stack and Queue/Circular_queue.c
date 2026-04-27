#include <stdio.h>
#define SIZE 5   // size of queue

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if ((rear + 1) % SIZE == front) {
        printf("Queue is FULL!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &val);

    if (front == -1) front = 0;   // first element
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
    printf("%d enqueued\n", val);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  // queue became empty
    } else {
        front = (front + 1) % SIZE;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element = %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
