#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top =-1;

int is_empty(){
    return top ==-1;
}

int is_full(){
    return top == MAX-1;
}

void push(int data){
    if (is_full()){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
    printf("Pushed %d \n",data);
}

int pop(){
    if (is_empty()){
        printf("Stack Underflow! \n");
        exit(1);
    }
    printf("Popped  %d \n",stack[top]);
    return stack[--top];
}

int peek(){
    if (is_empty()){
        printf("Stack Underflow!\n");
        exit(1);}
    return stack[top];
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

int main() {
    printf("--- Array-based Stack Demo ---\n");
    push(10);
    push(20);
    push(30);
    display_array_stack(); // Output: Stack (Top to Bottom): 30 20 10 

    printf("Top element: %d\n", peek()); // Output: Top element: 30

    pop(); // Output: Popped: 30
    display_array_stack(); // Output: Stack (Top to Bottom): 20 10 

    pop(); // Output: Popped: 20
    pop(); // Output: Popped: 10
    pop(); // Output: Stack Underflow: Cannot pop from an empty stack. (and exits)

    printf("Is stack empty? %s\n", is_empty() ? "Yes" : "No");

    return 0;
}