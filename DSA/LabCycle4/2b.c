#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

static Node* tail = NULL;

int isEmpty(void) {
    return tail == NULL;
}

void enqueue(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed\n");
        return;
    }
    node->data = value;
    if (tail == NULL) {
        node->next = node;
        tail = node;
    } else {
        node->next = tail->next; // new node points to head
        tail->next = node;       // old tail points to new node
        tail = node;             // update tail
    }
    printf("Enqueued: %d\n", value);
}

int dequeue(int* out) {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return 0;
    }
    Node* head = tail->next;
    int value = head->data;

    if (head == tail) {
        // Only one node
        tail = NULL;
    } else {
        tail->next = head->next; // bypass old head
    }
    free(head);
    if (out) *out = value;
    printf("Dequeued: %d\n", value);
    return 1;
}

int front(int* out) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return 0;
    }
    if (out) *out = tail->next->data; // head is tail->next
    return 1;
}

int size(void) {
    if (isEmpty()) return 0;
    int count = 0;
    Node* cur = tail->next; // start at head
    do {
        count++;
        cur = cur->next;
    } while (cur != tail->next);
    return count;
}

void display(void) {
    if (isEmpty()) {
        printf("Queue: [empty]\n");
        return;
    }
    printf("Queue (front -> rear): ");
    Node* cur = tail->next; // head
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != tail->next);
    printf("\n");
}

void clear(void) {
    while (!isEmpty()) {
        dequeue(NULL);
    }
}

int main(void) {
    int choice, x, ok;
    for (;;) {
        printf("\nCircular Queue (SLL)\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Size\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Invalid value\n");
                    break;
                }
                enqueue(x);
                break;
            case 2:
                ok = dequeue(&x);
                break;
            case 3:
                ok = front(&x);
                if (ok) printf("Front: %d\n", x);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Size: %d\n", size());
                break;
            case 0:
                clear();
                return 0;
            default:
                printf("Unknown choice\n");
        }
    }
}
