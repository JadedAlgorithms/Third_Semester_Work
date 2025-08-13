#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int power;
    struct Term* next;
} Term;

Term* createTerm(int coeff, int power) {
    Term* newNode = (Term*)malloc(sizeof(Term));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Term **poly, int coeff, int power) {
    if (coeff == 0) return; // skip zero terms
    Term *newNode = createTerm(coeff, power);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    Term *temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPoly(Term *poly) {
    while (poly != NULL) {
        printf("%d", poly->coeff);
        if (poly->power != 0) printf("x^%d", poly->power);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

Term* addPoly(Term *p1, Term *p2) {
    Term *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            insertTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            insertTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}

int main() {
    Term *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int deg1, deg2, coeff;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients for first polynomial (from highest degree to constant term):\n");
    for (int i = deg1; i >= 0; i--) {
        scanf("%d", &coeff);
        insertTerm(&poly1, coeff, i);
    }

    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients for second polynomial (from highest degree to constant term):\n");
    for (int i = deg2; i >= 0; i--) {
        scanf("%d", &coeff);
        insertTerm(&poly2, coeff, i);
    }

    sum = addPoly(poly1, poly2);

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    printf("Sum Polynomial: ");
    displayPoly(sum);

    return 0;
}
