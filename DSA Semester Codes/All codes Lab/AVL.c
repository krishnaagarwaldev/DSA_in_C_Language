#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node* left;
    struct Node* right;
    int key;
    int height;
};

int max(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int height(struct Node* n){
    if (n==NULL){
        return 0;
    }
    return n->height;
}

struct Node* newNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node *y){
    struct Node*x = y->left;
    struct Node*t2 = x->right;
    
    x->right = y;
    y->left = t2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

struct Node* leftRotate(struct Node *x){
    struct Node*y = x->right;
    struct Node*t2 = y->left;
    
    y->left = x;
    x->right = t2;
    
    x->height = max(height(x->left), height(x->right)) + 1; //order matter otherwise no o/p
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

int getBalance(struct Node* n){
    if (n==NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}

void preorder(struct Node* node){
    if (node==NULL){
        return;
    }
    printf("%d ",node->key);
    preorder(node->left);
    preorder(node->right);
}

struct Node* insertNode(struct Node* node, int key){
    if (node==NULL){
        return newNode(key);
    }
    
    if (key < node->key){
        node->left = insertNode(node->left,key);
    }
    else if (key > node->key){
        node->right = insertNode(node->right,key);
    }
    else{
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    
    if (balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    return node;
    
}


// struct Node* findMax(struct Node* root){
//     while (root && root->right!=NULL){
//         root = root->right;
//     }
//     return root;
// }

// struct Node* findMin(struct Node* root){
//     while (root && root->left!=NULL){
//         root = root->left;
//     }
//     return root;
// }

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while (current->left!=NULL){
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node *root, int key){
    
    if (root == NULL){
        return root;
    }
    if(key<root->key){
        root->left =  deleteNode(root->left, key);
    }
    else if(key>root->key){
        root->right =  deleteNode(root->right, key);
    }
    
    else{
        if ((root->left == NULL) || (root->right == NULL)){
            struct Node* temp;
            if (root->left!=NULL) temp = root->left;
            else temp = root->right;
            
            if (temp==NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            free(temp);
        }
        else{
            struct Node* temp =  minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    
    // else{
    //     struct Node* temp = findMax(root->left);
    //     root->key = temp->key;
    //     root->left = deleteNode(root->left, temp->key);
    // }
    // else{
    //     struct Node* temp = findMin(root->right);
    //     root->key = temp->key;
    //     root->right = deleteNode(root->right, temp->key);
    // }
    
    if (root==NULL){
        return root;
    }
    
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left)>=0){
        return rightRotate(root);
    }
    
    if (balance > 1 && getBalance(root->left)<0){ 
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right)<=0){ 
        return leftRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right)>0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}



int main(){
    struct Node* root = NULL;
    
    int ch;
    int key;
    
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1:
            scanf("%d",&key);
            root = insertNode(root,key); 
            break;
            
            case 2:
            scanf("%d",&key);
            root = deleteNode(root,key); 
            break;
            
            case 3:
            preorder(root);
            break;
            
            case 4:
            exit(0);
        }
    }

    return 0;
}