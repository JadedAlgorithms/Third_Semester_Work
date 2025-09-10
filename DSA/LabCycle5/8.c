#include <stdio.h>
#define MAX 50
int q[MAX];
int front=-1,rear=-1;

void enque(int data)
{
	if(rear == MAX-1)
		printf("List full");
	else{
		rear++;
		q[rear]=data;
	}
}

int deque()
{
	if( front == rear )
		printf("empty");
	else{
		return q[++front];
		}
}

void display()
{
	if(front == rear)
		printf("empty");
	else{
		printf("List:\n");
		for(int i=front+1;i<=rear;i++)
		{	printf("%d  ",q[i]);}
		printf("\n");
		}
}

//aux stack
int S[MAX];
int top=-1;

void push(int data)
{
	if(top==MAX-1) printf("OverFlow\n");
	else
	{
	top++;
	S[top]=data;
	}
}

int pop()
{
	if(top==-1) printf("UnderFlow\n");
	else
	{
	return S[top--];
	}
}

//reversing
void reverse()
{
	while (front!=rear)
	{
		push(deque());
	}
	front=rear=-1;
	
	while(top!=-1)
	{
		enque(pop());
	}
}

//main
 void main()
 {	printf("push to list: 10 20 30 40\n");
 	enque(10);
 	enque(20);
 	enque(30);
 	enque(40);
 	
 	printf("Original\n");
 	display();
 	
 	printf("Reverse\n");
 	reverse();
 	display();
 }
