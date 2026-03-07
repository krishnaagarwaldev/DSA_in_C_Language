#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Create new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending power order and merge if same power exists
void insertSorted(struct Node** poly, int coeff, int pow) {
    if (coeff == 0) return; // skip zero terms

    struct Node* newNode = createNode(coeff, pow);

    // If list is empty or new term has higher power than head
    if (*poly == NULL || pow > (*poly)->pow) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    struct Node* temp = *poly;
    struct Node* prev = NULL;

    // Traverse to find correct position
    while (temp != NULL && temp->pow > pow) {
        prev = temp;
        temp = temp->next;
    }

    // If same power found, merge coefficients
    if (temp != NULL && temp->pow == pow) {
        temp->coeff += coeff;
        free(newNode); // no need for duplicate node
    } else {
        // Insert in between or at end
        newNode->next = temp;
        if (prev != NULL) prev->next = newNode;
    }
}

// Add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Copy all terms from poly1
    while (poly1 != NULL) {
        insertSorted(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    // Copy all terms from poly2
    while (poly2 != NULL) {
        insertSorted(&result, poly2->coeff, poly2->pow);
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

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Term %d (coeff power): ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertSorted(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Term %d (coeff power): ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertSorted(&poly2, coeff, pow);
    }

    printf("\nPolynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    displayPoly(sum);

    return 0;
}
