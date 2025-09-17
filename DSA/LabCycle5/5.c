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

void deleteByKey(Node** headRef, int key){
    Node* temp = *headRef;
    Node* prev = NULL;

    if(temp != NULL && temp -> data ==key){
        *headRef = temp -> next;
        free(temp);
        printf("Deleted node with key %d ",key);
        return;
    }

    while(temp != NULL && temp -> data != key){
        prev = temp;
        temp = temp -> next;
    }

    if(temp == NULL){
        printf("Key not found! \n");
        return;
    }

    prev -> next = temp -> next;
    free(temp);
    printf("Deleted node with key %d\n", key);

}

int main(){
    Node* head =  createNode(10);
    head -> next = createNode(20);
    head -> next = createNode(30);
    printf("Initial list: ");
    displayList(head);

    int key;
    printf("Enter key to delete node: ");
    scanf("%d \n", &key);
    deleteByKey(&head,key);

    return 0;
}