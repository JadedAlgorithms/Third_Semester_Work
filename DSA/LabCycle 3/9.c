#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Tuple;

// Function to read tuple representation
void readTuple(Tuple tuple[]) {
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d %d %d", &tuple[0].row, &tuple[0].col, &tuple[0].value);

    printf("Enter the non-zero elements (row col value):\n");
    for (int i = 1; i <= tuple[0].value; i++) {
        scanf("%d %d %d", &tuple[i].row, &tuple[i].col, &tuple[i].value);
    }
}

// Function to check if symmetric
int isSymmetric(Tuple tuple[]) {
    if (tuple[0].row != tuple[0].col) {
        return 0; // Not square → can't be symmetric
    }

    for (int i = 1; i <= tuple[0].value; i++) {
        int found = 0;
        for (int j = 1; j <= tuple[0].value; j++) {
            if (tuple[i].row == tuple[j].col &&
                tuple[i].col == tuple[j].row &&
                tuple[i].value == tuple[j].value) {
                found = 1;
                break;
            }
        }
        if (!found) return 0; // Matching transpose element not found
    }
    return 1;
}

// Function to display tuple
void displayTuple(Tuple tuple[]) {
    printf("\nRow\tCol\tValue\n");
    for (int i = 0; i <= tuple[0].value; i++) {
        printf("%d\t%d\t%d\n", tuple[i].row, tuple[i].col, tuple[i].value);
    }
}

int main() {
    Tuple tuple[100];

    readTuple(tuple);

    printf("\nTuple Representation:");
    displayTuple(tuple);

    if (isSymmetric(tuple))
        printf("\nThe given matrix is Sparse Symmetric.\n");
    else
        printf("\nThe given matrix is NOT Sparse Symmetric.\n");

    return 0;
}

