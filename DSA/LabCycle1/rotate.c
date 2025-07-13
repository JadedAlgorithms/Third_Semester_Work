#include <stdio.h>

void reverse(int a[], int start, int end) {
    while (start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

/*
 * Rotates array 'a' of size 'n' by 'cnt' positions in direction 'dir' ('l' for left, 'r' for right).
 * If cnt > n, it is reduced modulo n.
 */
void rotate(int a[], int n, char dir, int cnt){
    cnt = cnt % n; // Reduce cnt if greater than n
    if(cnt == 0) {
        printf("Printing the rotated array: \n");
        for(int i = 0; i < n; i++){
            printf(" %d ", a[i]);
        }
        printf("\n");
        return;
    }
    if(dir == 'l'){
        reverse(a, 0, cnt - 1);
        reverse(a, cnt, n - 1);
        reverse(a, 0, n - 1);
    }
    else if(dir == 'r'){
        reverse(a, 0, n - 1);
        reverse(a, 0, cnt - 1);
        reverse(a, cnt, n - 1);
    }
    printf("Printing the rotated array: \n");
    for(int i = 0; i < n; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, cnt;
    char dir;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter direction (l for left, r for right): ");
    scanf(" %c", &dir);
    printf("Enter number of positions to rotate: ");
    scanf("%d", &cnt);

    rotate(arr, n, dir, cnt);

    return 0;
}