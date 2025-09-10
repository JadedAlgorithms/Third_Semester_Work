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

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node** node = &result;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }
        carry = sum / 10;
        *node = newNode(sum % 10);
        node = &((*node)->next);
    }
    return result;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* l1 = NULL; struct Node* l2 = NULL;
    insert(&l1, 1); insert(&l1, 2); insert(&l1, 3);
    insert(&l2, 9); insert(&l2, 9);
    struct Node* sum = addLists(l1, l2);
    printList(sum);
}
