#include <stdio.h>
#include <stdlib.h>

// Node structure for each term in polynomial
struct Node {
    int coeff;              // Coefficient
    int pow;                // Power of x
    struct Node* next;      // Pointer to next term
};

// Create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end
void insertEnd(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode; // First term becomes head
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Compare and add terms while both lists have nodes
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) { // Higher power from poly1
            insertEnd(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) { // Higher power from poly2
            insertEnd(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else { // Same power → add coefficients
            insertEnd(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertEnd(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertEnd(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Display polynomial
void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;
    int n1, n2, coeff, pow;

    // Input first polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms in descending order of power:\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d coefficient and power: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertEnd(&poly1, coeff, pow);
    }

    // Input second polynomial
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms in descending order of power:\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d coefficient and power: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertEnd(&poly2, coeff, pow);
    }

    // Display both polynomials
    printf("\nPolynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    // Add polynomials
    sum = addPoly(poly1, poly2);

    // Display result
    printf("Sum: ");
    displayPoly(sum);

    return 0;
}
