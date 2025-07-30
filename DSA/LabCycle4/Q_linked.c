#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL;
Node *rear = NULL;
Node *temp;

void enque(int data) {
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (rear == NULL) { //empty
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printf("Pushed %d\n", data);
}

void deque() {
    if (front == NULL) {
        printf("Q underflow!\n");
    } else {
        temp = front;
        int data = temp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
        printf("Dequed %d\n", data);
    }
}

void display() {
    temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Pushing elements into the Q
    enque(10);
    enque(20);
    enque(30);
    display();
    // DQing elements! "Heheehe" :P
    deque();
    deque();
    display();
    return 0;
}