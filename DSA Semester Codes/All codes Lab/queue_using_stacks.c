#include<stdio.h>
#include<stdlib.h>

int main(){
    int top1=0,top2=0;
    int stack1[100];
    int stack2[100];
    int choice;
    while(1){
        scanf("%d",&choice);

        switch(choice){
            
            case 1:
            int input;
            scanf("%d",&input);
            stack1[top1++]=input;
            break;
            
            case 2:
            if (top2==0){
                while(top1>0){
                    stack2[top2++] =  stack1[--top1];
                }
                top2=top2-1;
            }
            else{
                top2=top2-1;
            }
            break;
            
            case 3:
            if (top2==0){
                while(top1>0){
                    stack2[top2++] = stack1[--top1];
                }
                printf("%d\n",stack2[top2-1]);
            }
            else{
                printf("%d",stack2[top2-1]);
            }
            break;
            
            
            case 4:
            exit(0);
            break;
        }
    }
    return 0;
}


/*
#define Max 100

int s1[Max],s2[Max];
int t1=-1,t2=-1;

void push1(int x){
    if (t1<Max-1){
        s1[++t1] = x;
    }
}

void push2(int x){
    if (t2<Max-1){
        s2[++t2] = x;
    }
}


int pop1(){
    if (t1==-1){
        return -1;
    }
    return s1[t1--];
}

int pop2(){
    if (t2==-1){
        return -1;
    }
    return s2[t2--];
}


int isEmpty1(){
    return t1==-1;
}


int isEmpty2(){
    return t2==-1;
}

void enqueue(int x){
    push1(x);
}

int dequeue(){
    if (isEmpty2()){
        while(!isEmpty1()){
            push2(pop1());
        }
    }
    if (isEmpty2()){
        return -1;
    }
    return pop2();
}

int peek(){
    if (t2==-1){
        return -1;
    }
    return s2[t2];
}


int main(){
    
    while (1){
        int ch;
        scanf("%d",&ch);
        
        switch (ch){
            case 1:
            int x;
            scanf("%d",&x);
            enqueue(x);
            break;
             
            case 2:
            int ele;
            ele = dequeue();
            //printf("%d",ele);
            break;
            
            case 3:
            int element = peek();
            printf("%d ",element);
            break;
            
            case 4:
            exit(0);
        }
    }
    
    return 0;
}
*/