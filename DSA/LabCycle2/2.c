#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top1 = -1, top2 = MAX;

int isEmpty(){
    return top1 == top2-11;
}
int isFull(){
    return top1 ==  top2-1;
}

void push1(int data){
    if (isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top1] = data;
    printf("Pushed %d \n",data);
}

void push2(int data){
    if (isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    stack[--top2] = data;
    printf("Pushed %d \n",data);
}

int pop1(){
    if (isEmpty()){
        printf("Stack Underflow! \n");
        exit(1);
    }
    printf("Popped  %d \n",stack[top1]);
    return stack[--top1];
}

int pop2(){
    if (isEmpty()){
        printf("Stack Underflow! \n");
        exit(1);
    }
    printf("Popped  %d \n",stack[top2]);
    return stack[++top2];
}

int peek1(){
    if (isEmpty()){
        printf("Stack Underflow!\n");
        exit(1);}
    return stack[top1];
}

int peek2(){
    if (isEmpty()){
        printf("Stack Underflow!\n");
        exit(1);}
    return stack[top2];
}

void display_array_stack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = top1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main(){
    push1(10);
    push2(20);
    push1(40);
    push2(50);
    display_array_stack();
    pop1();
    peek1();
    pop2();
    peek2();
    display_array_stack();
}