#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    int size=100;
    int top=0;
    char arr[size+1];
    scanf("%s",arr);
    char stack[size];
    
    for (int i=0;i<size;i++){
        if (arr[i]>='1' && arr[i]<='9'){
            stack[top]=(int)arr[i] - (int)'0';
            top++;
        }
        else if(arr[i]=='+'){
            float result = (float)stack[top-1] + (float) stack[top-2];
            top = top - 2;
            stack[top] =  result;
            top++;
        }
        else if(arr[i]=='-'){
            float result = (float)stack[top-2] - (float) stack[top-1];
            top = top - 2;
            stack[top] =  result;
            top++;
        }
        else if(arr[i]=='*'){
            float result = (float)stack[top-1] * (float) stack[top-2];
            top = top - 2;
            stack[top] =  result;
            top++;
        }
        else if(arr[i]=='/'){
            float result = (float)stack[top-1] / (float) stack[top-2];
            top = top - 2;
            stack[top] =  result;
            top++;
        }
        
        else if(arr[i]=='^'){
            float result = (float)pow(stack[top-1], stack[top-2]);
            top = top - 2;
            stack[top] =  result;
            top++;
        }
    }
    printf("%d",stack[top-1]);
    return 0;
}
 