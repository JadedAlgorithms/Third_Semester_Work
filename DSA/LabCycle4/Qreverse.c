#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data){
    if(rear == MAX-1){
        printf("Queue overflow!\n");
        return;
    }
    else
    {
        if (front == -1) {
            front = 0;
        }
        rear+=1;
        queue[rear] = data;
        return;
    }
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow!\n");
        return 0;
    }
    else{
        int data = queue[front];
        front+=1;
        return data;
    }
}

int peek(){
    if (front == -1 || front > rear){
        printf("Queue empty\n");
        return 0;
    }
    else{
        return queue[front];
    }
}

void display(){
    if (front == -1 || front > rear){
        printf("Empty Queue\n");
    }
    else{
        for(int i = front; i<=rear;i++){
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
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

void reverse(){
    
}