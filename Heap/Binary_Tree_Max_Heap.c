// Q-1 => Time Complexity = O(n)
// Q-2 => Time Complexity = O(n)
// Q-3 => Time Complexity = O(n)
// Q-4 => Time Complexity = O(n)
// Q-5 => Time Complexity = O(log(n))
// Q-6 => Time Complexity = O(log(n))

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}


//Q-1 => Time complexity = O(n)
int getHeight(struct node* root){
    if (root==NULL){
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (left > right){
        return left+1 ;
    }
    else{
        return right+1 ; 
    }
}

//Q-2 => Time complexity = O(n)
int findMax(struct node* root){
    if (root == NULL){
        return -1;
    }
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    if (leftMax > max){
        max = leftMax;
    }
    if (rightMax > max){
        max = rightMax;
    }
    // else{
    //     max = rightMax;
    // }
    return max;
}




int countNodes(struct node* root){
    if (root==NULL){
        return 0;
    }
    return (1 + countNodes(root->left) + countNodes(root->right)) ;
}

//Q-3 => Time complexity = O(n)
int isComplete(struct node* root, int index, int number_nodes){
    if (root==NULL){
        return 1;
    }
    if (index >= number_nodes){
        return 0;
    }
    return (isComplete(root->left, 2*index+1, number_nodes) &&
            isComplete(root->right, 2*index+2, number_nodes));
}


int isMaxHeapProp(struct node* root){
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    
    if (root->right == NULL){
        return (root->data >= root->left->data);
    }
    
    if (root->data >= root->left->data && root->data >= root->right->data){
        return (isMaxHeapProp(root->left) && isMaxHeapProp(root->right));
    }
    return 0;
}

//Q-4 => Time complexity = O(n)
int isMaxHeap(struct node* root){
    if (root == NULL){
        return 1;
    }
    int node_count = countNodes(root);
    if (isComplete(root, 0, node_count) && isMaxHeapProp(root)){
        return 1;
    }
    return 0;
}

//Q-5 => Time complexity = O(log(n))
int isArrayMaxHeap(int arr[], int n){
    for(int i=0; i<=(n-2)/2 ; i++){
        if (arr[i] < arr[2*i + 1]){
            return 0;
        }
        if (2*i+2 < n && arr[i]<arr[2*i+2]){
            return 0;
        }
    }
    return 1;
}

//Q-6 => Time complexity = O(log(n))
int getArrayHeight(int n){
    int height = 0;
    while(n>0){
        height++;
        n = n/2;
    }
    return height;
}


int main(){
    struct node* root = newnode(90);
    root->left = newnode(15);
    root->right = newnode(10);
    root->left->left = newnode(7);
    root->left->right = newnode(12);
    root->right->left = newnode(2);
    
    printf("Tree Height : %d\n", getHeight(root));
    printf("Maximum Element : %d\n", findMax(root));
    
    int nodeCount = countNodes(root);
    if (isComplete(root, 0, nodeCount)){
        printf("Complete Binary Tree : Yes\n");
    }
    else{
        printf("CBT : No\n");
    }
    
    if (isMaxHeap(root)){
        printf("Yes : Max Heap\n");
    }
    else{
        printf("No : Max Heap\n");
    }
    int arr[] = {90, 15, 10, 7, 12, 2};
    int n = sizeof(arr) / sizeof(arr[0]) ;
    
    if (isArrayMaxHeap(arr, n)){
        printf("Yes this array is maxheap\n");
    }
    else{
        printf("No not an maxheap\n");
    }
    printf("Arr Tree Height : %d\n", getArrayHeight(n));
    return 0;
}