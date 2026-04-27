/*Got it 👍
You want Stack using Queue (with arrays) but also with a peek() function that returns the top element without removing it.

👉 Reminder:
We implement Stack (LIFO) using two queues:

push(x): enqueue into q2, move everything from q1 to q2, swap q1 and q2.

pop(): dequeue from q1.

peek(): just return q1[front] (since top is always at the front of q1).*/

#include <stdio.h>
#define MAX 100

// Queue 1
int q1[MAX], f1=-1, r1=-1;
// Queue 2
int q2[MAX], f2=-1, r2=-1;

// Queue helpers
int isEmpty1() { return f1==-1; }
int isEmpty2() { return f2==-1; }

void enqueue1(int x) {
    if(r1==MAX-1) { printf("Queue1 Overflow\n"); return; }
    if(f1==-1) f1=0;
    q1[++r1]=x;
}
int dequeue1() {
    if(isEmpty1()) { printf("Queue1 Underflow\n"); return -1; }
    int val=q1[f1++];
    if(f1>r1) f1=r1=-1;
    return val;
}

void enqueue2(int x) {
    if(r2==MAX-1) { printf("Queue2 Overflow\n"); return; }
    if(f2==-1) f2=0;
    q2[++r2]=x;
}
int dequeue2() {
    if(isEmpty2()) { printf("Queue2 Underflow\n"); return -1; }
    int val=q2[f2++];
    if(f2>r2) f2=r2=-1;
    return val;
}

// Stack functions
void push(int x) {
    // Step 1: enqueue new element into q2
    enqueue2(x);
    // Step 2: move all from q1 to q2
    while(!isEmpty1()) {
        enqueue2(dequeue1());
    }
    // Step 3: copy q2 -> q1
    f1=f2; r1=r2;
    for(int i=f2;i<=r2;i++) q1[i]=q2[i];
    // Reset q2
    f2=r2=-1;
}

int pop() {
    return dequeue1();
}

int peek() {
    if(isEmpty1()) {
        printf("Stack Empty\n");
        return -1;
    }
    return q1[f1];  // front of q1 is top of stack
}

// Driver
int main() {
    push(10);
    push(20);
    push(30);

    printf("Peek: %d\n", peek());  // should be 30
    printf("Pop: %d\n", pop());    // remove 30
    printf("Peek: %d\n", peek());  // now top = 20
    return 0;
}
