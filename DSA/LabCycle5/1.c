#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void addAtEnd(Node** head,int value){
    Node* newNode = createNode(value);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void displayList(Node* head){
    Node* temp = head;

    if (temp == NULL){
        printf("List is empty \n");
    }
    while(temp != NULL){
        printf("%d ->", temp ->data);
        temp = temp-> next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = NULL;
    int n,data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i = 0; i<n ;i++){
        printf("Enter element: ");
        scanf("%d ",&data);
        addAtEnd(&head,data);
        printf("\n");
    }
    printf("The display list is:    ");
    displayList(head);
}