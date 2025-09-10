#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a node
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

// delete at given position (1-based index)
void deleteAtPosition(Node** headRef, int position) {
    if (position < 1) {
        printf("Invalid position. Must be >= 1.\n");
        return;
    }
    
    Node* temp = *headRef;
    Node* prev = NULL;
    int currentPos = 1;    

    
    if (position == 1) {
        *headRef=temp->next;
        printf("deleted %d at position 1.\n", temp->data);
        free(temp);
        return;
    }
    
    while (temp != NULL && currentPos < position) {
    	  prev=temp;
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d at position %d.\n", temp->data, position);
    free(temp);
}

// Display list
void displayList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    // Manually creating the list: 10 -> 20 -> 30 -> NULL
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Initial list: ");
    displayList(head);

    int position, newData;
    printf("Enter the position to delete (1-n): ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("List after insertion: ");
    displayList(head);

    return 0;
}
