#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *front = NULL, *rear = NULL;

struct Node *newNode(int d) {
    struct Node *t = malloc(sizeof(struct Node));
    t->data = d;
    t->prev = t->next = NULL;
    return t;
}

void insertFront(int d) {
    struct Node *t = newNode(d);
    if (!front) {
        front = rear = t;
        return;
    }
    t->next = front;
    front->prev = t;
    front = t;
}
void insertRear(int d) {
    struct Node *t = newNode(d);
    if (!rear) {
        front = rear = t;
        return;
    }
    rear->next = t;
    t->prev = rear;
    rear = t;
}
void deleteFront() {
    if (!front) return;
    struct Node *t = front;
    front = front->next;
    if (front)
        front->prev = NULL;
    else
        rear = NULL;
    free(t);
}
void deleteRear() {
    if (!rear) return;
    struct Node *t = rear;
    rear = rear->prev;
    if (rear)
        rear->next = NULL;
    else
        front = NULL;
    free(t);
}

void display() {
    struct Node *c = front;
    while (c) {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}

int main() {
    insertRear(1);
    insertRear(2);
    insertFront(0);
    display();
    deleteRear();
    display();
}
