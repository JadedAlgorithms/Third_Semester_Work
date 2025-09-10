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
    while (c->next) c = c->next;
    c->next = t;
    t->prev = c;
}

void deleteKey(int key) {
    struct Node *c = head;
    while (c && c->data != key) c = c->next;
    if (!c) return;
    if (c->prev)
        c->prev->next = c->next;
    else
        head = c->next;
    if (c->next) c->next->prev = c->prev;
    free(c);
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
    append(2);
    append(3);
    deleteKey(2);
    display();
}
