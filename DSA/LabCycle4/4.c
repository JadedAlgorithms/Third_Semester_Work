#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* newNode(int d, int p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

int peek(Node** head) {
    return (*head)->data;
}

void pop(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node** head, int d, int p) {
    Node* start = (*head);
    Node* temp = newNode(d, p);

    if ((*head)->priority > p) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

int main() {
    Node* head = newNode(4, 4);
    push(&head, 5, 1);
    push(&head, 11, 3);
    push(&head, 1, 2);

    while (!isEmpty(&head)) {
        printf("%d ", peek(&head));
        pop(&head);
    }

    return 0;
}