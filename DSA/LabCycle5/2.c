#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void addAfter(Node** head,int targetData,int value){
    Node *temp = *head;
    while(temp != NULL && temp -> data != targetData){
        temp = temp -> next;
    }
    if (temp == NULL){
        printf("Target not found, ERROR 404\n");
        return;
    }
    Node* newNode = createNode(value);
    newNode -> next = temp -> next;
    temp -> next =  newNode;

    printf("Inserted %d after %d \n",value,targetData);
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
    Node* head = createNode(10);
    head -> next =  createNode(20);
    head -> next -> next = createNode(40);
    printf("list: \n");
    displayList(head);
    int target,value;
    printf("Enter the node data after which node to enter: ");
    scanf("%d",&target);
    printf("Enter the data for insertion: ");
    scanf("%d",&value);
    addAfter(&head,target,value);
    displayList(head);
    return 0;

}