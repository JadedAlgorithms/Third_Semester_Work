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

void append(int d) {
    struct Node *t = newNode(d);
    if (!head) {
        head = t;
        return;
    }
    struct Node *c = head;
    while (c->next)
        c = c->next;
    c->next = t;
    t->prev = c;
}

void insertBefore(int key, int d) {
    struct Node *c = head;
    while (c && c->data != key)
        c = c->next;
    if (!c)
        return;
    struct Node *t = newNode(d);
    t->next = c;
    t->prev = c->prev;
    if (c->prev)
        c->prev->next = t;
    else
        head = t;
    c->prev = t;
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
    append(1);
    append(3);
    append(4);
    insertBefore(3, 2);
    display();
}
