#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
int front = -1, rear = -1;
int queue[MAX];

bool isEmpty(){
    if(front == rear == -1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if((rear+1%MAX) == front){
        return true;
    }
    else{
        return false;
    }

}

void insertfront(int data){
    if(isFull()){
        printf("Error! Queue is full,\n ");
    }
    if(isEmpty){
        front = rear = 0;
    }
    else{
        front = (front-1+MAX)%MAX;
    }
    if(front = 0 ){
        front = MAX-1;
    }
    else{
        front = front -1;
    }
    queue[front] = data;
    printf("Item has been inserted \n");
}

void insertrear(int data){
    if(isFull()){
        printf("Error! Queue is full,\n ");
    }
    if(isEmpty){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%MAX;
    }
    queue[rear] = data;
    printf("Item inserted \n");
}

int deletefront(){
    if(isEmpty()){
        printf("Queue is empty! \n");
        return -1;
    }
    printf("Deleted element from Queue %d \n",queue[front]);
    if (front == rear) {
        front = rear = -1; // Only one element was present
    } else {
        front = (front + 1) % MAX;
    }
}

void deleterear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from rear.\n");
        return;
    }
    printf("Deleted element from rear: %d\n", queue[rear]);
    if (front == rear) {
        front = rear = -1; 
    } else {    
        if (rear==0)
            rear=MAX-1;
        else
            rear=rear-1;
    }
}

void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty! \n");
    }
    i = front;
    printf("Queue elements! \n");
    while(1){
        printf("%d ",queue[i]);
        if(i == rear){
            break;}
        i = (i+1)%MAX;
        
    }
    printf("\n");
}
int main() {
    int choice, item;
    while (1) {
        printf("\n***** MENU *****\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertfront(item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insertrear(item);
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}



