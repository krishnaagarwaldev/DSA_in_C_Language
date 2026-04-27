#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *createnode(int x){
    struct node *n =  (struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->left =  NULL;
    n->right =  NULL;
    return n;
}



struct node* insert(struct node* root , int key){
    if (root == NULL){
        return createnode(key);
    }
    else if (key < root->data){
        root->left = insert(root->left , key);
    }
    else if (key > root->data){
        root->right = insert(root->right , key);
    }
    return root;
}


void search(struct node* root) {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct node *curr = root;
    while (curr != NULL) {
        if (key == curr->data) {
            printf("Found %d in tree\n", key);
            return;
        }
        else if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    printf("%d not found in tree\n", key);
}


void inorder(struct node* Node){
    if (Node == NULL){
        return;
    }
    inorder(Node->left);
    printf("%d ",Node->data);
    inorder(Node->right);
}


void postorder(struct node* Node){
    if (Node == NULL){
        return;
    }
    postorder(Node->left);
    postorder(Node->right);
    printf("%d ",Node->data);
}

void preorder(struct node* Node){
    if (Node == NULL){ 
        return;
    } 
    printf("%d ",Node->data);
    preorder(Node->left);
    preorder(Node->right);
}




struct node* findMax(struct node* Node){
    while (Node && Node->right!=NULL){ // go to the rightmost node
        Node = Node->right;
    }
    return Node;
}

struct node* deleteNode_InPredecessor(struct node* node, int key){
    if (node == NULL){
        return node;
    }

    if (node->right == NULL && node->left == NULL){
        return NULL;
    }

    else if (key < node->data){ // key is smaller than root's key
        node->left = deleteNode_InPredecessor(node->left, key); // go to left subtree
    }
    else if (key > node->data){ // key is greater than root's key
        node->right = deleteNode_InPredecessor(node->right, key); // go to right subtree
    }

    else{
        struct node* temp = findMax(node->left); // node with only one child or no child
        node->data = temp->data; // copy the inorder predecessor's content to this node
        node->left = deleteNode_InPredecessor(node->left,temp->data); // delete the inorder predecessor
    }
    return node;
}





struct node* findMin(struct node* Node){
    while (Node && Node->left != NULL){
        Node = Node->left;
    }
    return Node;
}
struct node* deleteNode_InSuccessor(struct node* node, int key){
    if (node == NULL) return node;

    // Case 1: Leaf node
    if (node->left == NULL && node->right == NULL){
        return NULL;
    }

    // Go left
    else if (key < node->data){
        node->left = deleteNode_InSuccessor(node->left, key);
    }
    // Go right
    else if (key > node->data){
        node->right = deleteNode_InSuccessor(node->right, key);
    }

    // Case 3: Two children
    else {
        struct node* temp = findMin(node->right); // successor
        node->data = temp->data;                  // copy successor’s value
        node->right = deleteNode_InSuccessor(node->right, temp->data); // delete successor
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
            search(root);
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
            root = deleteNode_InPredecessor(root,key); //delete the node 
            break;
            
            case 7:
            scanf("%d", &key);
            root = deleteNode_InSuccessor(root, key);
            break;

            case 8:
            exit(0);
            break;
        }
    }
    return 0;
}







