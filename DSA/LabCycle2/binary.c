#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int stack[MAX];
int top =-1;

int is_empty(){
    return top ==-1;
}

int is_full(){
    return top == MAX-1;
}

void push(int data){
    if(is_full()){
        printf("Stack Overflow! \n");
        return;
    }
    stack[++top] = data;
    printf("Pushed %d \n", data);
}

void display_array_stack() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void binary_conv(int decimal){
    int data;
    while(decimal!=0){
        data=decimal%2;
        push(data);
        decimal /= 2;
    }
    display_array_stack();
}

void main(){
    int decimal;
    printf("Enter the decimal value! \n");
    scanf("%d",&decimal);
    binary_conv(decimal);
}