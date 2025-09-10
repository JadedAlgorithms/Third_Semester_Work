#include <stdio.h>

struct Sparse{
    int row;
    int col;
    int value;
};

int main(){
    int matrix[4][5] ={
        {0,0,0,1,0},
        {2,0,0,0,0},
        {0,3,0,0,0},
        {0,0,0,0,4}
    };
    struct Sparse sparse[20];
    int rows = 4;
    int cols = 5;
    int k = 1;
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = 0;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols;j++){
            if (matrix[i][j]!= 0){
                sparse[k].row = i+1;
                sparse[k].col = j+1;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0].value = k-1;
    printf("Row Col Value\n");
for (int i = 0; i < k; i++) {
printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
}
return 0;
}
