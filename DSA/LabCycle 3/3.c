#include <stdio.h>

#define MAX 100

void displayPoly(int poly[],int degree){
    for(int i = degree;i>=0;i--){
        if(poly[1]!=0){
            printf("%d",poly[i]);
            if(i>0){printf("x^%d",i);}
            if(i>0){printf(" + ");}
        }
    }
    printf("\n");
}
int main() {
    int poly1[MAX] = {0}, poly2[MAX] = {0}, sum[MAX] = {0};
    int deg1, deg2, maxDeg;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients for first polynomial (from constant term to x^%d):\n", deg1);
    for (int i = 0; i <= deg1; i++) {
        scanf("%d", &poly1[i]);
    }
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients for second polynomial (from constant term to x^%d):\n", deg2);
    for (int i = 0; i <= deg2; i++) {
        scanf("%d", &poly2[i]);
    }
    maxDeg = (deg1 > deg2) ? deg1 : deg2;
    for (int i = 0; i <= maxDeg; i++) {
        sum[i] = poly1[i] + poly2[i];
    }
    printf("\nFirst Polynomial: ");
    displayPoly(poly1, deg1);

    printf("Second Polynomial: ");
    displayPoly(poly2, deg2);

    printf("Sum Polynomial: ");
    displayPoly(sum, maxDeg);

    return 0;
}