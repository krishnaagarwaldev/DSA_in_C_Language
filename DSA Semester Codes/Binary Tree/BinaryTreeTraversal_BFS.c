#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert in binary tree (not BST, just build using input)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    int choice;
    printf("Insert %d to left(1) or right(2) of %d ? ", data, root->data);
    scanf("%d", &choice);
    if (choice == 1) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Inorder Traversal (LNR)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal (NLR)
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (LRN)
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level order traversal using queue i.e BFS(Breadth First Search)
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* x) {
    queue[++rear] = x;
}
struct Node* dequeue() {
    return queue[++front];
}
int isEmpty() {
    return front == rear;
}

// Level order traversal -- BFS (Breadth First Search)
void levelorder(struct Node* root) {
    if (root == NULL) return;
    front = rear = -1;  // reset queue
    enqueue(root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left != NULL) enqueue(temp->left);
        if (temp->right != NULL) enqueue(temp->right);
    }
}
/*void levelorder(struct Node* root) {
    if (root == NULL) return;
    front = rear = -1;  // reset queue
    enqueue(root);
    enqueue(NULL);  // marker for new line

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        if (temp == NULL) {
            printf("\n"); // end of a level
            if (!isEmpty())
                enqueue(NULL); // add marker for next level
        } else {
            printf("%d ", temp->data);
            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}
*/

/*void levelorderLevelWise(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = -1, rear = -1;

    // enqueue root
    queue[++rear] = root;

    while (front != rear) {
        int nodeCount = rear - front; // number of nodes in current level

        // print all nodes of this level
        while (nodeCount > 0) {
            struct Node* temp = queue[++front];
            printf("%d ", temp->data);

            if (temp->left) queue[++rear] = temp->left;
            if (temp->right) queue[++rear] = temp->right;

            nodeCount--;
        }
        printf("\n"); // new line for next level
    }
}
*/

void reverseLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    front = rear = -1;   // reset queue
    enqueue(root);

    while (!isEmpty()) {
        struct Node* temp = dequeue();
        stack[++top] = temp;   // push into stack

        // enqueue right first, then left (important!)
        if (temp->right) enqueue(temp->right);
        if (temp->left)  enqueue(temp->left);
    }

    // print in reverse order
    while (top != -1) {
        printf("%d ", stack[top--]->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("\n--- MENU ---\n");
    printf("1. Insert\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Levelorder Traversal\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            if (root == NULL)
                root = createNode(data);
            else
                insert(root, data);
            break;
        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Levelorder: ");
            levelorder(root);
            printf("\n");
            break;
        
        case 6:
            reverseLevelOrder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
