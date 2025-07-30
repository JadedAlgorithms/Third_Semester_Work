#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data){
    if(rear == MAX-1){
        printf("Queue overflow!\n");
        return;
    }
    else
    {
        if (front == -1) {
            front = 0;
        }
        rear+=1;
        queue[rear] = data;
        return;
    }
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow!\n");
        return 0;
    }
    else{
        int data = queue[front];
        front+=1;
        return data;
    }
}

int peek(){
    if (front == -1 || front > rear){
        printf("Queue empty\n");
        return 0;
    }
    else{
        return queue[front];
    }
}

void display(){
    if (front == -1 || front > rear){
        printf("Empty Queue\n");
    }
    else{
        for(int i = front; i<=rear;i++){
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    printf("--- Simple Queue Test ---\n\n");

    // 1. Enqueue 3 items and display the queue
    printf("Step 1: Enqueue 10, 20, 30\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("\n");

    // 2. Peek at the front item
    printf("Step 2: Peek at front element\n");
    printf("Front element is: %d\n", peek());
    printf("\n");

    // 3. Dequeue an item and display again
    printf("Step 3: Dequeue one element\n");
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("\n");

    // 4. Empty the queue completely
    printf("Step 4: Emptying the rest of the queue\n");
    dequeue();
    dequeue();
    display();
    printf("\n");

    // 5. Test Underflow (trying to dequeue from an empty queue)
    printf("Step 5: Testing Underflow\n");
    dequeue();
    printf("\n");

    // 6. Test Overflow (filling the queue and trying to add one more)
    printf("Step 6: Testing Overflow\n");
    for (int i = 1; i <= MAX; i++) {
        enqueue(i * 10);
    }
    printf("\nQueue is now full:\n");
    display();
    printf("\nAttempting to enqueue one more element (110):\n");
    enqueue(110);

    printf("\n--- Test Complete ---\n");
    return 0;
}