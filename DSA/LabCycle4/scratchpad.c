#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
int cqueue[MAX];
int rear=0, front=0;

bool isEmpty(){
    return front==rear;
}

bool isFull(){
    return (rear+1)%MAX==front;
}

void enqueue(){
    int value;
    if (isFull()){
        printf("queue overflow\n");
    }
    else{
        printf("Enter value to enqueue: \n");
        scanf("%d", &value);
        cqueue[rear]=value;
        rear=(rear+1) % MAX;
    }
}

void dequeue(){
    if (isEmpty()){
        printf("queue underflow\n");
    }else{
        int value = cqueue[front];
        front = (front + 1) % MAX;
        printf("Dequeued value: %d\n", value);
    }
}

int peek(){
    if (isEmpty()){
        printf("Queue is empty\n");
        return -1; // Indicating empty queue
    } else {
        return cqueue[front];
    }
}
void display(){
    if (isEmpty()){
        printf("Queue is empty\n");
    }else{
        printf("Queue elements are: ");
        for(int i=front; i!=rear; i=(i+1)%MAX){
            printf("%d ", cqueue[i]);
        }
        printf("\n");
    }
}
int main(){
    int choice;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            int value = peek();
            if (value != -1) {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}