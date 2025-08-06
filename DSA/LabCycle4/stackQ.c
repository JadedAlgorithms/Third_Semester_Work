#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

void push1(int data);
int pop1();
int is_empty1();
int is_full1();

void push2(int data);
int pop2();
int is_empty2();

void enQueue(int data);
int deQueue();
void display();

void push1(int data) {
    if (top1 == MAX - 1) {
        printf("Error: Queue is full!\n");
        return;
    }
    stack1[++top1] = data;
}

int pop1() {
    if (top1 == -1) {
        printf("Error: Stack 1 underflow!\n");
        exit(1);
    }
    return stack1[top1--];
}

int is_empty1() {
    return top1 == -1;
}

int is_full1() {
    return top1 == MAX - 1;
}

void push2(int data) {
    if (top2 == MAX - 1) {
        printf("Error: Stack 2 overflow!\n");
        exit(1);
    }
    stack2[++top2] = data;
}

int pop2() {
    if (top2 == -1) {
        printf("Error: Stack 2 underflow!\n");
        exit(1);
    }
    return stack2[top2--];
}

int is_empty2() {
    return top2 == -1;
}

void enQueue(int data) {
    if (is_full1()) {
        printf("Queue Overflow! Cannot add %d.\n", data);
        return;
    }
    push1(data);
    printf("Enqueued: %d\n", data);
}

int deQueue() {
    if (is_empty1() && is_empty2()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }

    if (is_empty2()) {
        while (!is_empty1()) {
            int temp = pop1();
            push2(temp);
        }
    }

    int dequeued_data = pop2();
    return dequeued_data;
}

void display() {
    if (is_empty1() && is_empty2()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (Front to Rear): ");
    
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Queue using Stacks Menu ---\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enQueue(data);
                break;
            case 2:
                data = deQueue();
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}