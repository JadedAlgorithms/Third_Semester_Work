#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    temp->next = *head;
    *head = temp;
}

int exists(struct Node* head, int data) {
    while (head) {
        if (head->data == data) return 1;
        head = head->next;
    }
    return 0;
}

struct Node* Union(struct Node* s1, struct Node* s2) {
    struct Node* result = NULL;
    struct Node* t = s1;
    while (t) {
        if (!exists(result, t->data)) insert(&result, t->data);
        t = t->next;
    }
    t = s2;
    while (t) {
        if (!exists(result, t->data)) insert(&result, t->data);
        t = t->next;
    }
    return result;
}

struct Node* Intersection(struct Node* s1, struct Node* s2) {
    struct Node* result = NULL;
    struct Node* t = s1;
