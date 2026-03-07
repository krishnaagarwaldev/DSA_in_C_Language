#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push() {
    int data;
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &data);
    //or top++ then stack[top] = data;
    stack[++top] = data; //++top first increase then assign eg, top=5 then stack[6]=data; and top=6;
    printf("%d pushed onto stack.\n", data);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nTop element: %d\n", stack[top]);
}

// Display all elements
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nStack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

// Driver code
int main() {
    int choice;
    printf("\n*** Stack using Array ***\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}


/*
Operator	    What Happens	                   Example (top = 5)	 First	 Final Value
top++	     Use value first, then increment	     x = top++ → x=5	     5	 6
++top	     Increment first, then use value	     x = ++top → x=6	     6	 6 
top--	     Use value first, then decrement	     x = top-- → x=5	     5	 4
--top	     Decrement first, then use value	     x = --top → x=4	     4	 4
*/