#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Creating a self referencial structure

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front;
Node* rear;
Node* temp;

// Creating a node

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int value){
    Node* newNode = createNode(value);
    if (front == NULL){
        front = rear = newNode;
    }
    else{
        newNode -> next = front;
        front = newNode;
    }
}

void insertRear(int value){
    Node* newNode = createNode(value);
    if (rear == NULL){
        front = rear = newNode;
    }
    else{
        rear -> next = newNode;
        rear = newNode;
    }
}
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = front;
    printf("Deleted from front: %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}


void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    Node* temp = front;
    if (front == rear) {
        printf("Deleted from rear: %d\n", temp->data);
        free(temp);
        front = rear = NULL;
        return;
    }

    while (temp->next != rear) {
        temp = temp->next;
    }

    printf("Deleted from rear: %d\n", rear->data);
    free(rear);
    rear = temp;
    rear->next = NULL;
}


void display() {
    Node* temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    int choice, item;
    while (1) {
        printf("\n***** MENU *****\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}