#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create linked list
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

// Remove duplicates using 2 loops
void removeDuplicatesTwoLoops() {
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;
        while(ptr2->next != NULL){
            if(ptr1->data == ptr2->next->data){
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
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
    removeDuplicatesTwoLoops();
    printf("After Removing Duplicates: ");
    display();
    return 0;
}
