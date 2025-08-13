#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct term {
    int coefficient;
    int exponent;
    struct term *next;
};

struct term *p = NULL;
struct term *q = NULL;
struct term *r = NULL;

void generatePolynomial(struct term **pt, int n) {
    printf("Enter the coefficient and variable exponent in descending order:\n");
    for (int i = 0; i < n; i++) {
        struct term *newterm;
        newterm = (struct term *)malloc(sizeof(struct term));
        printf("Term %d: ", i);
        scanf("%d %d", &newterm->coefficient, &newterm->exponent);
        newterm->next = NULL;

        if (*pt == NULL) {
            *pt = newterm;
        } else {
            struct term *temp = *pt;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newterm;
        }
    }

    struct term *temp = *pt;
    printf("g(x): ");
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
}

void product(struct term *p,struct term *q,struct term **r,int n,int m){
    struct term *h1;
    h1=p;
    
    struct term *h3;
    h3=*r;
    int i=0,j=0;
    while(h1!=NULL){
        struct term *h2;
        h2=q;
        while(h2!=NULL){
            
                int coefficientProduct=(h1->coefficient)*(h2->coefficient);
                int exponent=(h1->exponent)+(h2->exponent);
                //check if h2->exponent exists

                struct term *temp;
                temp=*r;
                while(temp!=NULL && temp->exponent!=(h2->exponent+h1->exponent)){
                    temp=temp->next;
                }
                if(temp){
                    temp->coefficient+=coefficientProduct;
                    //temp->exponent=exponent;
                    h2=h2->next;
                }
                else{
                    struct term *newterm;
                    newterm=(struct term*)malloc(sizeof(struct term));
                    newterm->next=NULL;
                    newterm->coefficient=h1->coefficient*h2->coefficient;
                    newterm->exponent=h1->exponent+h2->exponent;
                    
                    if(*r==NULL){
                    *r=newterm;
                    h3=newterm;
                    }else{
                        h3->next=newterm;
                        h3=newterm;
                    }
                    h2=h2->next;
                }
        }
        h1=h1->next; 
    }
    struct term *temp;
    temp=*r;
    printf("g(x): ");
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) {
            printf("+");
        }
        temp = temp->next;
    }
    printf("\n");
    
}

int main() {
    printf("Enter the no of Terms of the 1st polynomial: ");
    int n = 0;
    scanf("%d", &n);
    generatePolynomial(&p, n);

    printf("Enter the no of Terms of the 2nd polynomial: ");
    int m = 0;
    scanf("%d", &m);
    generatePolynomial(&q, m);

    product(p,q,&r,n,m);
    return 0;
}

