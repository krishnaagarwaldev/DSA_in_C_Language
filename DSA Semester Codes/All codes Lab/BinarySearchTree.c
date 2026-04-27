#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node *createnode(int x){
    struct node *n =  (struct node*)malloc(sizeof(struct node));
    n->key = x;
    n->left =  NULL;
    n->right =  NULL;
    return n;
}



struct node* insert(struct node* root , int key){
    if (root == NULL){
        return createnode(key);
    }
    else if (key < root -> key){
        root -> left = insert(root -> left , key);
    }
    else if (key > root -> key){
        root -> right = insert(root -> right , key); 
    }
    return root;
}

bool search(struct node* root , int key){
    if (root == NULL){
        return false;
    }
    else if (root -> key == key){
        return true;
    }
    else if (key < root -> key){
        return search(root -> left , key);
    }
    else{
        return search(root -> right , key);
    }
}

void inorder(struct node* Node){
    if (Node == NULL){
        return;
    }
    inorder(Node->left);
    printf("%d ",Node->key);
    inorder(Node->right);
}


void postorder(struct node* Node){
    if (Node == NULL){
        return;
    }
    postorder(Node->left);
    postorder(Node->right);
    printf("%d ",Node->key);
}

void preorder(struct node* Node){
    if (Node == NULL){ 
        return;
    } 
    printf("%d ",Node->key);
    preorder(Node->left);
    preorder(Node->right);
}


struct node* findMax(struct node* Node){
    while (Node && Node->right!=NULL){ // go to the rightmost node
        Node = Node->right;
    }
    return Node;
}

struct node* deleteNode(struct node* node, int key){
    if (node == NULL){
        return node;
    }

    if (node -> right == NULL && node -> left == NULL){
        return NULL;
    }

    else if (key < node->key){ // key is smaller than root's key
        node->left = deleteNode(node->left, key); // go to left subtree
    }
    else if (key > node->key){ // key is greater than root's key
        node->right = deleteNode(node->right, key); // go to right subtree
    }

    else{
        struct node* temp = findMax(node->left); // node with only one child or no child
        node->key = temp->key; // copy the inorder predecessor's content to this node
        node->left = deleteNode(node->left,temp->key); // delete the inorder predecessor
    }
    return node;
}

    
struct node* findMin(struct node* Node){
    while (Node && Node->left!=NULL){ // go to the leftmost node
        Node = Node->left;
    }
    return Node;
}
struct node* deleteNode2(struct node* node, int key){
    if (node == NULL){
        return node;
    }

    if (node -> right == NULL && node -> left == NULL){
        return NULL;
    }

    else if (key < node->key){ // key is smaller than root's key
        node->left = deleteNode2(node->left, key); // go to left subtree
    }
    else if (key > node->key){ // key is greater than root's key
        node->right = deleteNode2(node->right, key); // go to right subtree
    }

    else{
        struct node* temp = findMin(node->right); // node with only one child or no child
        node->key = temp->key; // copy the inorder successor's content to this node
        node->right = deleteNode2(node->right,temp->key); // delete the inorder successor
    }
    return node;
}

int main(){
    struct node *root =  NULL; 
    int ch;
    int key;
    while (1){
        scanf("%d",&ch);
        switch(ch){
            case 1:
            scanf("%d" , &key);
            root = insert(root , key);
            break;
            
            case 2:
            scanf("%d" , &key);
            if (search(root , key)){
                printf("Found\n");
            }
            else{
                printf("Not Found\n");
            }
            break;

            case 3:
            inorder(root);
            break;
            
            case 4:
            preorder(root);
            break;
            
            case 5:
            postorder(root);
            break;
            
            case 6:
            scanf("%d", &key);
            root = deleteNode(root , key);
            break;
            
            case 7:
            exit(0);
            break;

            case 8:
            scanf("%d", &key);
            root = deleteNode2(root , key);
            break;
        }
    }
    return 0;
}







