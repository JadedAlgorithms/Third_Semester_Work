#include <stdio.h>
#include <time.h> 

void bubblesort(int array[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int array[5] = {15, 5, 20, 25, 10};
    int n = 5; 
    int i;

    printf("Array before sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    clock_t start_time = clock();

    bubblesort(array, n);
    clock_t end_time = clock();

    printf("Array after sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken for sorting: %f seconds\n", elapsed_time);

    return 0;
}