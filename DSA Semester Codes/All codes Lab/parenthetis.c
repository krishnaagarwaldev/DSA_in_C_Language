#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;

int main(){
    int top=0;
    int size=100;
    char arr[size+1];
    scanf("%s",arr);
    
    char stack[size];
    for (int i=0;i<5;i++){
        if((arr[i]=='(') || (arr[i] == '{') || (arr[i] == '[')){
            stack[top++] = arr[i];
        }
        i++;
        
        if( ((arr[i] ==  ')') && (stack[top-1] == '(')) || ((arr[i] == '}') && (stack[top-1] == '{')) || ((arr[i] ==  ']') && (stack[top-1] == '['))){
            top = top-1;
        }
        
    }
    
    if (top == 0){
        printf("true");
    }
    else{
        printf("false");
    }
    
    return 0;
}
