#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void addAtEnd(Node** headRef, int value); // Function prototype

void insertAtPosition(Node** headRef , int position , int value){
    if (position < 1){
        printf("Invalid position! \n");
        exit(1);
    }

    Node* newNode = createNode(value);
    if (position == 1){
        newNode -> next = *headRef;
        newNode -> data = value;
        *headRef = newNode;
        printf("Inserted %d at position 1\n",value);
        return;
    }

    Node* temp = *headRef; // FIXED: use *headRef
    int currentPos = 1;

    while(temp != NULL && currentPos < position - 1){ // position-1 for correct insertion
        temp = temp -> next;
        currentPos++;        
    }
    if(temp == NULL){
        printf("Position %d is out of bounds\n", position); // FIXED: add position
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    printf("Inserted %d at position %d\n",value,position);
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
        scanf("%d",&data);
        addAtEnd(&head,data);
        printf("\n");
    }
    printf("The display list is:    ");
    displayList(head);
}
void addAtEnd(Node** headRef, int value) {
    Node* newNode = createNode(value);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}