#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int Q[MAX];
int front = 0;
int rear = 0;

bool isEmpty(front,rear);
bool isFull();
void deque();
void enque(int data);
void peek();

    bool isEmpty(front,rear)
