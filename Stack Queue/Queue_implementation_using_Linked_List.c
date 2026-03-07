/*
1. Front and Rear in Queue

Front → Points to the first element of the queue (head of linked list).
Rear → Points to the last element of the queue (tail of linked list).

2. Operations in Terms of Linked List
Queue Operation	What It Does in Linked List	Explanation
Enqueue (Insert)	              Insert at the end (rear)	                New node is linked to rear and rear is updated.
Dequeue (Remove)	           Delete from the beginning (front)	        Removes node pointed by front and moves front to next node.
Peek (Front Element)	Displays the value of the node pointed by front     Shows the value at front without removing it.



3. Queue vs Stack

Feature	                    Queue	                                 stack
Principle	                FIFO (First In, First Out)	             LIFO (Last In, First Out)
Insertion	                At rear	                                 At top
Deletion	                From front	                             From top
Linked List Mapping	        Enqueue → Insert at end	                 Push → Insert at beginning (or end)
                            Dequeue → Delete at beginning	         Pop → Delete from beginning (or end)
Use Cases                   Scheduling, printers, CPU processes	     Undo operations, recursion calls

*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Global front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to enqueue (insert) an element
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        // First element in the queue
        front = rear = newNode;
    } else {
        // Link new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued successfully.\n", value);
}

// Function to dequeue (remove) an element
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d dequeued successfully.\n", front->data);
    front = front->next;

    if (front == NULL) {
        // Queue became empty
        rear = NULL;
    }
    free(temp);
}

// Function to peek (view front element)
void peek() {
    if (front == NULL) {
        printf("Queue is empty! Nothing to peek.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Function to display all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu-driven interface
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
