#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int front = -1, rear = -1;
int deque[MAX];

bool isEmpty(void) {
    return front == -1;
}

bool isFull(void) {
    return ((rear + 1) % MAX) == front;
}

void insertfront(int data) {
    if (isFull()) {
        printf("Error! Deque is full.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = data;
    printf("Item inserted at front.\n");
}

void insertrear(int data) {
    if (isFull()) {
        printf("Error! Deque is full.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = data;
    printf("Item inserted at rear.\n");
}

int deletefront(void) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted element from front: %d\n", data);
    return data;
}

int deleterear(void) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
    printf("Deleted element from rear: %d\n", data);
    return data;
}

void display(void) {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (true) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main(void) {
    int choice, item;

    for (;;) {
        printf("\n***** MENU *****\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                if (scanf("%d", &item) == 1) insertfront(item);
                else { printf("Invalid input.\n"); exit(1); }
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                if (scanf("%d", &item) == 1) insertrear(item);
                else { printf("Invalid input.\n"); exit(1); }
                break;
            case 3:
                deletefront();
                break;
            case 4:
                deleterear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}



