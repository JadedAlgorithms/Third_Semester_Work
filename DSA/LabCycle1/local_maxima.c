#include <stdio.h>
#include <stdbool.h>

void findAllLocalMaximums(int arr[], int n) {
    bool found_any_maxima = false;

    printf("Array: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    printf("Local Maximums found: ");

    if (n <= 0) {
        printf("None (Array is empty).\n");
        return;
    }
    if (n == 1) {
        printf("%d (Single element is always a local max by this definition).\n", arr[0]);
        return;
    }

    if (arr[0] > arr[1]) {
        printf("%d ", arr[0]);
        found_any_maxima = true;
    }

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            printf("%d ", arr[i]);
            found_any_maxima = true;
        }
    }

    if (arr[n - 1] > arr[n - 2]) {
        printf("%d ", arr[n - 1]);
        found_any_maxima = true;
    }

    if (!found_any_maxima) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int arr1[] = {3, 2, 5, 7, 8, 1, 6, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    findAllLocalMaximums(arr1, n1);

    printf("\n--- Test Cases ---\n");

    int arr2[] = {10, 5, 20, 15, 25};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    findAllLocalMaximums(arr2, n2);

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    findAllLocalMaximums(arr3, n3);

    int arr4[] = {5, 4, 3, 2, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    findAllLocalMaximums(arr4, n4);

    int arr5[] = {7};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    findAllLocalMaximums(arr5, n5);

    int arr6[] = {};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    findAllLocalMaximums(arr6, n6);

    int arr7[] = {1, 1, 1, 1};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    findAllLocalMaximums(arr7, n7);

    int arr8[] = {50, 10, 60, 20, 70, 30};
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    findAllLocalMaximums(arr8, n8);

    return 0;
}