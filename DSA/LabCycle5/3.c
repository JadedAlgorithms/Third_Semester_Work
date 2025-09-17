#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node with 'value' before the node with 'targetData'
void addPrev(Node** head, int targetData, int value) {
    if (*head == NULL) {
        printf("List is empty. ERROR 404\n");
        return;
    }
    // If the target is at the head
    if ((*head)->data == targetData) {
        Node* newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d before %d\n", value, targetData);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != targetData) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Target not found, ERROR 404\n");
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d before %d\n", value, targetData);
}

void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(40);
    printf("list:\n");
    displayList(head);
    int target, value;
    printf("Enter the node data before which to insert: ");
    scanf("%d", &target);
    printf("Enter the data for insertion: ");
    scanf("%d", &value);
    addPrev(&head, target, value);
    displayList(head);
    return 0;
}