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

struct Node* set_intersection(struct Node* s1, struct Node* s2) {
    struct Node* result = NULL;
    struct Node* t = s1;
    while (t) {
        if (exists(s2, t->data)) {
            insert(&result, t->data);
        }
        t = t->next;
    }
    return result;
}

struct Node* set_union(struct Node* s1, struct Node* s2) {
    struct Node* result = NULL;
    struct Node* t = s1;
    while (t) {
        if (!exists(result, t->data)) {
            insert(&result, t->data);
        }
        t = t->next;
    }
    t = s2;
    while (t) {
        if (!exists(result, t->data)) {
            insert(&result, t->data);
        }
        t = t->next;
    }
    return result;
}

int main() {
    struct Node* set1 = NULL;
    insert(&set1, 1);
    insert(&set1, 2);
    insert(&set1, 3);

    struct Node* set2 = NULL;
    insert(&set2, 2);
    insert(&set2, 3);
    insert(&set2, 4);

    struct Node* unionSet = set_union(set1, set2);
    struct Node* intersectionSet = set_intersection(set1, set2);

    printf("Union: ");
    struct Node* temp = unionSet;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Intersection: ");
    temp = intersectionSet;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
