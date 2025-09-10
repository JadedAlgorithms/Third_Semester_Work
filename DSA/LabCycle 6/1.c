#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* newNode(int data) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data; t->prev = t->next = NULL;
    return t;
}

void append(int data) {
    struct Node* t = newNode(data);
    if (!head) { head = t; return; }
    struct Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = t; t->prev = cur;
}

void display() {
    struct Node* cur = head;
    while (cur) { printf("%d ", cur->data); cur = cur->next; }
    printf("\n");
}

int main() {
    int n, x; scanf("%d", &n);
    for (int i=0;i<n;i++){ scanf("%d",&x); append(x); }
    display();
}
