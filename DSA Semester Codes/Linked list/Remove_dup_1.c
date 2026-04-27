#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create linked list
void createList() {
    int n, val;
    struct Node *temp, *newNode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

// Function to sort linked list
void sortList() {
    struct Node *p, *q;
    int temp;
    for(p=head; p!=NULL; p=p->next){
        for(q=p->next; q!=NULL; q=q->next){
            if(p->data > q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

// Function to remove duplicates (sorted list)
void removeDuplicatesSorted() {
    struct Node *temp = head;
    struct Node *nextNode;
    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            nextNode = temp->next->next;
            free(temp->next);
            temp->next = nextNode;
        } else {
            temp = temp->next;
        }
    }
}

// Display linked list
void display() {
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createList();
    printf("Original List: ");
    display();
    sortList();
    printf("Sorted List: ");
    display();
    removeDuplicatesSorted();
    printf("After Removing Duplicates: ");
    display();
    return 0;
}
