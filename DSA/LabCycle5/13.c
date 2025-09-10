#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    return t;
}

void insert(struct Node** head, int data) {
    struct Node* t = newNode(data);
    t->next = *head;
    *head = t;
}

void removeDuplicates(struct Node* head) {
    struct Node *cur = head, *prev, *temp;
    while (cur && cur->next) {
        prev = cur;
        while (prev->next) {
            if (cur->data == prev->next->data) {
                temp = prev->next;
                prev->next = prev->next->next;
                free(temp);
            } else prev = prev->next;
        }
        cur = cur->next;
    }
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 3); insert(&head, 2); insert(&head, 3); insert(&head, 1); insert(&head, 2);
    removeDuplicates(head);
    printList(head);
}
