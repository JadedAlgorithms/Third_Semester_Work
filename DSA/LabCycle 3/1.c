#include <stdio.h>

int Polynomial(int degree) {
    int n = degree + 1;
    double coeff[n];
    int i;
    double x, result;

    printf("Enter Coefficients in decreasing power order:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &coeff[i]);
    }

    printf("Given polynomial: ");
    for (i = 0; i < n - 1; i++) {
        printf("%.2lfX**%d + ", coeff[i], degree - i);
    }
    printf("%.2lf\n", coeff[n - 1]);

    printf("Enter value of X: ");
    scanf("%lf", &x);


    result = coeff[0];
    for (i = 1; i < n; i++) {
        result = result * x + coeff[i];
    }

    printf("P(%.2lf) = %.2lf\n", x, result);

    return 0;
}

int main() {
    int degree;
    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);
    Polynomial(degree);
    return 0;
}
