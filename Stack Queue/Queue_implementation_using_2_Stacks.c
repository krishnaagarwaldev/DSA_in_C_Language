#include <stdio.h>
#define MAX 100   // maximum size of the queue

// ---------- Global Variables ----------
int stack1[MAX], stack2[MAX];  // Two stacks implemented as arrays
int top1 = -1;  // Top pointer for stack1
int top2 = -1;  // Top pointer for stack2

// ---------- Helper Functions for Stack ----------
// Push into stack1
void push1(int val) {
    stack1[++top1] = val;   // increment top1 and insert value
}

// Push into stack2
void push2(int val) {
    stack2[++top2] = val;   // increment top2 and insert value
}

// Pop from stack1
int pop1() {
    return stack1[top1--];  // return top element and decrease top1
}

// Pop from stack2
int pop2() {
    return stack2[top2--];  // return top element and decrease top2
}

// Check if stack1 is empty
int isEmpty1() {
    return top1 == -1;
}

// Check if stack2 is empty
int isEmpty2() {
    return top2 == -1;
}

// ---------- Queue Functions ----------

// Enqueue: Insert element into queue
void enqueue(int val) {
    push1(val);  // Always insert into stack1
    printf("%d enqueued into queue.\n", val);
}

// Dequeue: Remove front element from queue
void dequeue() {
    // Case 1: Both stacks empty
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }

    // Case 2: If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    // Pop from stack2 (front of queue)
    printf("%d dequeued from queue.\n", pop2());
}

// Peek: See front element without removing
void peek() {
    // Case 1: Both stacks empty
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is EMPTY! Nothing to peek.\n");
        return;
    }

    // Case 2: If stack2 is empty, transfer elements first
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    // Front element is at top of stack2
    printf("Front element is: %d\n", stack2[top2]);
}

// Display: Show all queue elements from front to rear
void display() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements (front to rear): ");

    // First, print elements from stack2 (front elements)
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    // Then print elements from stack1 (rear elements)
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }

    printf("\n");
}


// ---------- Main Function ----------
int main() {
    int choice, val;
    printf("\n--- Queue Using Two Stacks ---\n");
    printf("1. Enqueue (Insert)\n");
    printf("2. Dequeue (Remove)\n");
    printf("3. Peek (Front Element)\n");
    printf("4. Display (Show Queue)\n");
    printf("5. Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
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
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

/*Enqueue (Insert) :-
Push elements to stack1.
This preserves the order of arrival.


Dequeue (Remove) :-
When removing, we need the oldest element (front of the queue).
To get that, we move all elements from stack1 to stack2 (which reverses the order).
Now, the oldest element is on top of stack2.
Pop from stack2.


How Display Works?
Elements in stack2 are older entries (front of queue), so we print them first from top to bottom.
Elements still in stack1 are newer entries (rear of queue), so we print them from bottom to top.
This ensures the queue order (front → rear) is shown correctly.

stack1: [ ]  
stack2: [ ]

Enqueue 10, 20, 30
stack1: [10, 20, 30]   (top is 30)
stack2: [ ]

stack1: [ ]
stack2: [30, 20, 10]   (top is 10)

stack1: [ ]
stack2: [30, 20]   (top is 20)

Enqueue 40
stack1: [40]
stack2: [30, 20]

stack1: [40]
stack2: [30]   (removed 20)

stack1: [40]
stack2: [ ]

stack1: [ ]
stack2: [40]

*/
