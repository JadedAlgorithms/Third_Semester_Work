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

// Insert at given position (1-based index)
void search(Node** headRef,int key) {
    Node* temp = *headRef;
    int currentPos = 0;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
        currentPos++;
    }
    
    if(temp == NULL){
    	printf("Not found\n");
    	return;
    }
    printf("Found %d at position %d.\n", temp->data, currentPos);
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

    int key;
    printf("Enter Key to search: ");
    scanf("%d", &key);

    search(&head,key);

    return 0;
}
