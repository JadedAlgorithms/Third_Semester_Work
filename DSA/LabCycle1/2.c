#include <stdio.h>
#include <stdlib.h>

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
double calculateMean(int arr[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}


double calculateMedian(int arr[], int n) {
    // Create a copy of the array to avoid modifying the original
    int *tempArr = (int *)malloc(n * sizeof(int));
    if (tempArr == NULL) {
        perror("Failed to allocate memory for median calculation");
        exit(EXIT_FAILURE);
    }
    memcpy(tempArr, arr, n * sizeof(int));
    bubbleSort(tempArr, n);
    double median;
    if (n % 2 == 0) {
        median = (double)(tempArr[n / 2 - 1] + tempArr[n / 2]) / 2.0;
    } else {
        
        median = (double)tempArr[n / 2];
    }

    free(tempArr);
    return median;
}
// Weird question, why shouldnt I use empirical formula???

int calculateMode(int arr[], int n) {
    
    int *tempArr = (int *)malloc(n * sizeof(int));
    if (tempArr == NULL) {
        perror("Failed to allocate memory for mode calculation");
        exit(EXIT_FAILURE);
    }
    memcpy(tempArr, arr, n * sizeof(int));
    bubbleSort(tempArr, n);

    int mode = tempArr[0];       
    int maxCount = 1;            
    int currentCount = 1;        
    for (int i = 1; i < n; i++) {
        if (tempArr[i] == tempArr[i-1]) {
            currentCount++;
        } else {
            currentCount = 1;  
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mode = tempArr[i-1]; 
        }
    }

    free(tempArr); 
    return mode;
}


int main() {
    int l[] = {1, 2, 3, 5, 4, 5, 6, 3, 1, 1};
    int n = sizeof(l) / sizeof(l[0]); // Calculate the number of elements

    printf("Original List: {");
    for (int i = 0; i < n; i++) {
        printf("%d", l[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Calculate and print the mean
    double mean = calculateMean(l, n);
    printf("Mean: %.1f\n", mean);

    // Calculate and print the median
    double median = calculateMedian(l, n);
    printf("Median: %.1f\n", median);

    // Calculate and print the mode
    int mode = calculateMode(l, n);
    printf("Mode: %d\n", mode);

    return 0;
}