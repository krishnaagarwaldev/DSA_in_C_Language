#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;


void insert_at_begin(){
    int data;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    
    temp->data=data;
    temp->prev=NULL;
    temp->next=head;
    
    if (head!=NULL){
        head->prev=temp;
    }
    head=temp;
}


void insert_at_end(){
    int data;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *trav;
    scanf("%d",&data);
    
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    
    if (head==NULL){
        head=temp;
        return;
    }
    trav=head;
    while (trav->next!=NULL){
        trav = trav->next;
    }
    trav->next=temp;
    temp->prev=trav;
}


void insert_at_pos(){
    int data,pos,i=1;
    struct node *temp,*newnode;
    scanf("%d",&data);
    scanf("%d",&pos);
    if (pos==1){
        insert_at_begin();
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    temp=head;
    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if (temp==NULL){
        free(newnode); //position out of range
        return;
    }
    newnode->next=temp->next;
    if (temp->next!=NULL){
        temp->next->prev=newnode;
    }
    newnode->prev=temp;
    temp->next=newnode;
}


void delete_at_begin(){
    if (head==NULL){
        return;
    }    
    struct node *temp=head;
    head=head->next;
    if (head!=NULL){
        head->prev=NULL;
    }
    free(temp);
}



void delete_at_end(){
    if (head==NULL){
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if (temp->prev!=NULL){
        temp->prev->next=NULL;
    }
    else{
        head=NULL;
    }
    free(temp);
}

/*
void delete_at_pos(){
    if (head==NULL){
        return;
    }
    int pos,i=1;
    struct node*temp,*position;
    scanf("%d",&pos);
    
    if (pos==1){
        delete_at_begin();
        return;
    }
    temp=head;
    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if (temp==NULL || temp->next==NULL){
        //position out of range
        return;
    position=temp->next;
    temp->next=position->next;
    if (position->next!=NULL){
        position->next->prev=temp;
    }
    free(position);
}
*/

void display(){
    if (head==NULL){
        return;
    }
    struct node *temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

/*
void reverse(struct node *temp){
    if (temp==NULL){
        return;
    }
    reverse(temp->next);
    printf("%d ",temp->data);
}
*/

void reverse(){
    struct node *temp=NULL;
    struct node *current = head;
    
    while (current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        
        current=current->prev;
    }
    if (temp!=NULL){
        head=temp->prev;
    }
    
}

int main(){
    int ch;
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert_at_begin();
            break;
            
            case 2:
            insert_at_end();
            break;
            
            case 3:
            insert_at_pos();
            break;
            
            case 4:
            delete_at_begin();
            break;
            
            case 5:
            delete_at_end();
            break;
            
            // case 6:
            // delete_at_pos();
            // break;
            
            case 7:
            display();
            break;
            
            case 8:
            reverse();
            break;
            
            case 9:
            exit(0);
            break;
            
        }
    }
    return 0;
}