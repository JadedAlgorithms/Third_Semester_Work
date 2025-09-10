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

void insertAtPosition(Node** headRef , int position , int value){
    if (position < 1){
        printf("Invalid position! \n");
        exit(1);
    }

    Node* newNode = createNode(value);
    if (position == 1){
        newNode -> data = headRef;
        *headRef = newNode;
        printf("Inserted %d at position \n",value);
        return;
    }

    Node* temp = headRef;
    int currentPos = 1;

    while(temp != NULL && currentPos < position){
        temp = temp -> next;
        currentPos++;        
    }
    if(temp == NULL){
        printf("Position %d is out of bounds");
        free(newNode);
        return;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    printf("inserted %d at position %d\n",value,currentPos);
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