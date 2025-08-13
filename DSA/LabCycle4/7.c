#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int data[MAX];
    int front,rear;
}Queue;

void initQueue(Queue* q){
    q -> front = -1;
    q -> rear = -1;

}

int isEmptyQ(Queue* q){
    return q->front == -1;
}

int isFullQ(Queue* q){
    return (q->rear+1)%MAX == q->front;

}

void enqueue(Queue* q, int value) {
    if (isFullQ(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmptyQ(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmptyQ(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}
typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack* s, int value) {
    enqueue(&s->q2, value);
    while (!isEmptyQ(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack* s) {
    if (isEmptyQ(&s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int top(Stack* s) {
    if (isEmptyQ(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->q1.data[s->q1.front];
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", top(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
} 