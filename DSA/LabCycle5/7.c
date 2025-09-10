#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display the list
void displayList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Delete the first node with the smallest value
void deleteSmallest(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *headRef;
    Node* minNode = temp;
    int minVal = temp->data;

    // Find the smallest value
    while (temp != NULL) {
        if (temp->data < minVal) {
            minVal = temp->data;
            minNode = temp;
        }
        temp = temp->next;
    }

    // Now delete the node with minVal (reusing delete by key logic)
    Node* current = *headRef;
    Node* prev = NULL;

    while (current != NULL && current->data != minVal) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Smallest value not found (unexpected).\n");
        return;
    }

    if (prev == NULL) {
        // Node to delete is head
        *headRef = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Deleted node with smallest value: %d\n", minVal);
}

void addAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        addAtEnd(&head, data);
    }
    
    printf("Initial list: ");
    displayList(head);

    deleteSmallest(&head);

    printf("List after deleting smallest element: ");
    displayList(head);

    return 0;
}

