#include <stdio.h>
#include <stdlib.h>

// Creating a self referencial structure!

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *top = NULL;

//pushing into the stack

void push(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}


void displayStack(){
    if(top==NULL){
        printf("Stack empty!\n");
    }
    else{
        Node* temp = top;
        printf("Stack content \n");
        while(temp!=NULL){
            printf("%d |-->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

}

//popping an element from the stack

void pop(){
    if (top == NULL){
        printf("Stack Underflow!");
        return;
    }
    Node* temp = top;
    printf("Popped element : %d \n", temp->data);
    top =  top->next;
    free(temp);
}

void peek(){
    if (top == NULL){
        printf("Stack Empty!\n");
    }
    Node* temp = top;
    printf("Last element: %d\n",temp->data);
}

int main(){
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    peek();
    return 0;
}   