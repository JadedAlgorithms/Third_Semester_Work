#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

struct Node *newNode(int d) {
    struct Node *t = malloc(sizeof(struct Node));
    t->data = d;
    t->prev = t->next = NULL;
    return t;
}

void insertAtPos(int pos, int d) {
    struct Node *t = newNode(d);
    if (pos == 1) {
        t->next = head;
        if (head)
            head->prev = t;
        head = t;
        return;
    }
    struct Node *c = head;
    for (int i = 1; c && i < pos - 1; i++)
        c = c->next;
    if (!c)
        return;
    t->next = c->next;
    t->prev = c;
    if (c->next)
        c->next->prev = t;
    c->next = t;
}

void display() {
    struct Node *c = head;
    while (c) {
        printf("%d ", c->data);
        c = c->next;
    }
    printf("\n");
}

int main() {
    insertAtPos(1, 1);
    insertAtPos(2, 2);
    insertAtPos(2, 3);
    display();
}
