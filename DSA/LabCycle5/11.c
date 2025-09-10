#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert in sorted order
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Merge two sorted lists into a new sorted list
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy; // temporary head
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
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
    Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int n1, n2, val;

    // Create first sorted list
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements for List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertSorted(&list1, val);
    }

    // Create second sorted list
    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements for List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertSorted(&list2, val);
    }

    // Display both lists
    printf("\nList 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Merge lists
    merged = mergeSortedLists(list1, list2);

    // Display merged list
    printf("\nMerged Sorted List: ");
    displayList(merged);

    return 0;
}

