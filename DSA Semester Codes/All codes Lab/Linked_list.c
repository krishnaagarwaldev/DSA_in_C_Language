#include<stdio.h>
#include<stdlib.h>



struct node{
    int data;
    struct node* next;
};

/*
struct node *head;
head=NULL;
*/
struct node *head=NULL;

// struct node* create_node(int data){
//     struct node* newNode=(struct node*) malloc(sizeof(struct node));
//     newNode->data=data;
//     newNode->next=NULL;
//     return newNode;
// }

void insert_at_begin(void){
    struct node* temp;
    temp = struct node*malloc(sizeof(struct node)); 
     scanf("%d",&temp->data);
     if (head==NULL){
         head=temp;
         head->next=NULL;
     }
     else{
         temp->next=head;
         head=temp;
     }
    
}

void insert_at_end(void){
    struct node* temp,*p;
    temp = struct node*malloc(sizeof(struct node));  
    scanf("%d",&temp->data); 
    p=head;
    
    if (head==NULL){
       head=temp;
       head->next=NULL;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
    }
 
}

/*
void insert_at_end(void){
        int data;     
        struct node *temp,*p;
        scanf("%d",&data);
        temp = struct node*malloc(sizeof(struct node));
        if (head==NULL){
            head=temp;
            temp->data=data;
            head->next=NULL;
        }
}
*/

void insert_at_position(){
    struct node* temp,*p; 
    int index;
    temp = struct node*malloc(sizeof(struct node));  
    scanf("%d",&temp->data);  
    scanf("%d",&index);
    p=head;
     if (head==NULL){
       head=temp; 
       head->next=NULL;
    } 
    else{
         for (int i=1;i<index;i++){
             p=p->next;
             if(p==NULL){
                 return;
             }
             temp->next=p->next;
             p->next=temp;
         }
    }
    
}

void delete_at_begin(void){
    struct node *p;
    p=head;
    if (head==NULL){
        return;
    }
    else{
        head=head->next;
        free(p)
    }

// void delete_at_position(struct node **head){
//     int data;
//     scanf("%d",&data); 
//     int pos;
//     scanf("%d",&data); 
    
//     if (*head==NULL){
//         return;
//     }
//     struct node *temp=*head;
//     for (int i=0;temp!=NULL && i<(pos-1);i++){
//         temp=temp->next;
//         if (temp==NULL || temp->next==NULL){
//             return;
//         }
//     }
        
//     }

/*
void insert_at_begin(){
    struct node *temp;
    struct node *head;
    temp = (struct node*) malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
*/

void delete_at_end(void){
    struct node *p,*q;
    p=head;
    q=head;
        if (head==NULL){
        return; }
        
        else if (head->next==NULL){
            free(head);
            head=NULL;
            return;
            
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        free(p);
        }
  


void display(void){
    struct node *p;
    p=head;
    while (p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}


void reverse(struct node *p){
    // struct node* p=(struct node*) malloc(sizeof(struct node));
    // p=head;
    struct node *q;
    q=p;
    if (q==NULL){
        return;
    }
    // struct node* p=(struct node*) malloc(sizeof(struct node));
    // p=head;
    reverse(q->next);
    printf("%d ",q->data);
}


 

int main()
{
    while(1){
    int choice;
    scanf("%d",&choice);

    
    
    switch(choice){
        case 1:
        insert_at_begin());
        break;
    
    
        case 2:
        insert_at_end();
        break;
    
    
       
        case 3:
        insert_at_position();
        break;
         
        case 4:
        delete_at_begin();
        break;
    
        
        case 5:
        delete_at_end();
        break;
       
        // case 6:
        // delete_at_position();
        // break;
        
    
        case 7:
        display();
        break;
    
        
        case 8:
        reverse(head);
        break;
       
        case 9:
        exit(0);
        break;
    
        
        default:
        exit(0);
        break;
    }}
    
    
    return 0;
}