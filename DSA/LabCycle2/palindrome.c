#include <stdio.h>
#include <stdlib.h>

#define MAX 11

char arr[MAX];
int top = -1;

int isEmpty(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
    }

int isFull(){
    if (top == MAX-2){   // Last space to store null terminator
        return 1;
    }
    else{
        return 0;
    }
}

void push(char data){
    if(isFull()){
        printf("Stack Overflow \n");
        return;
    }
    arr[++top] = data;
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow! \n");
    }
    printf("Popped element! %d \n",arr[top]);
    return arr[--top];
}