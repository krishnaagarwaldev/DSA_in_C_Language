#include<stdio.h>
#include<stdlib.h>
#define Max 100

int q1[Max],q2[Max];
int f1=-1; int r1=-1;
int f2=-1; int r2=-1;

int isEmpty1(){
    return f1==-1;
}

int isEmpty2(){
    return f2==-1;
}

void enqueue1(int x){
    if (r1==(Max-1)){
        return;
    }
    if (f1==-1){
        f1=0;
    }
    q1[++r1]=x;
}
void enqueue2(int x){
    if (r2==(Max-1)){
        return;
    }
    if (f2==-1){
        f2=0;
    }
    q2[++r2]=x;
}

int dequeue1(){
    if (f1==-1){
        return -1;
    }
    int val =q1[f1++];
    //f1++;
    if (f1>r1){
        f1=r1=-1;
    }
    return val;
}

int dequeue2(){
    if (f2==-1){
        return -1;
    }
    int val =q1[f1++];
    //f2++;
    if (f2>r2){
        f2=r2=-1;
    }
    return val;
}

void push(int x){
    enqueue2(x);
    while(!isEmpty1()){
        enqueue2(dequeue1());
    }
    
    f1=f2;
    r1=r2;
    for (int i=f2;i<=r2;i++){
        q1[i]=q2[i];
    }
    f2=r2=-1;
}

int pop(){
    return dequeue1();
}

int peek(){
   return q1[f1]; 
}

    
int main(){
    int ch;
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1:
            int x;
            scanf("%d",&x);
            push(x);
            break;
            
            case 2:
            int element;
            element = pop();
            break; 
            
            case 3:
            printf("%d ",peek());
            break;
            
            case 4:
            exit(0);
        }
    }
    
    
    return 0;
}