#include <stdio.h>

void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    printf("Intersection: {");
    int firstElement = 1; // Flag to handle comma formatting

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                if (!firstElement) {
                    printf(", ");
                }
                printf("%d", arr1[i]);
                firstElement = 0;
                break;
            }
        }
    }
    printf("}\n");
}
int main() {
    int S1[] = {1, 2, 3, 4};
    int size1 = sizeof(S1) / sizeof(S1[0]);

    int S2[] = {3, 4, 5};
    int size2 = sizeof(S2) / sizeof(S2[0]);

    printf("Set S1: {1, 2, 3, 4}\n");
    printf("Set S2: {3, 4, 5}\n");
    findIntersection(S1, size1, S2, size2);

    return 0;
}