#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 100

int marks[MAX_STUDENTS];
int num_marks = 0;

void printArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Marks: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void bubbleSortDescending(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void insert(int m) {
    if (num_marks >= MAX_STUDENTS) {
        printf("Error: Array is full. Cannot insert more marks.\n");
        return;
    }

    int i = num_marks - 1;
    while (i >= 0 && marks[i] < m) {
        marks[i + 1] = marks[i];
        i--;
    }

    marks[i + 1] = m;
    num_marks++;
    printf("Mark %d inserted successfully.\n", m);
}


int main() {
    marks[0] = 85;
    marks[1] = 92;
    marks[2] = 78;
    marks[3] = 95;
    marks[4] = 70;
    num_marks = 5;

    printf("Original marks:\n");
    printArray(marks, num_marks);

    bubbleSortDescending(marks, num_marks);
    printf("\nMarks after Bubble Sort (Descending):\n");
    printArray(marks, num_marks);

    printf("\n--- Demonstrating insert() function ---\n");

    insert(88);
    printArray(marks, num_marks);

    insert(99);
    printArray(marks, num_marks);

    insert(65);
    printArray(marks, num_marks);

    insert(80);
    printArray(marks, num_marks);

    return 0;
}