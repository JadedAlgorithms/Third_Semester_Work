#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    double coef;
    int pow;
    struct Node* next;
} Node;

Node* createNode(double coef, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void addTerm(Node** head, double coef, int pow) {
    Node* newNode = createNode(coef, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->coef < 0) {
            printf(" - %.2lf", fabs(temp->coef));
        } else {
            if (temp != head) printf(" + ");
            printf("%.2lf", temp->coef);
        }
        if (temp->pow != 0) {
            printf("x");
            if (temp->pow != 1) printf("^%d", temp->pow);
        }
        temp = temp->next;
    }
    printf("\n");
}

double evaluatePolynomial(Node* head, double x) {
    double result = 0;
    Node* temp = head;
    while (temp != NULL) {
        result += temp->coef * pow(x, temp->pow);
        temp = temp->next;
    }
    return result;
}

int main() {
    Node* poly = NULL;
    int degree;
    double coef, x;
    
    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);
    
    printf("Enter coefficients in decreasing power order:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &coef);
        addTerm(&poly, coef, i);
    }
    
    printf("The polynomial is: ");
    displayPolynomial(poly);
    
    printf("Enter value of x: ");
    scanf("%lf", &x);
    
    double result = evaluatePolynomial(poly, x);
    printf("P(%.2lf) = %.2lf\n", x, result);
    
    return 0;
}
