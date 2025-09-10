#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*prev,*next;};struct Node*head=NULL;

struct Node*newNode(int d){struct Node*t=malloc(sizeof(struct Node));t->data=d;t->prev=t->next=NULL;return t;}
void append(int d){struct Node*t=newNode(d);if(!head){head=t;return;}struct Node*c=head;while(c->next)c=c->next;c->next=t;t->prev=c;}

void deleteSmallest(){if(!head)return;struct Node*c=head,*min=head;while(c){if(c->data<min->data)min=c;c=c->next;}if(min->prev)min->prev->next=min->next;else head=min->next;if(min->next)min->next->prev=min->prev;free(min);}

void display(){struct Node*c=head;while(c){printf("%d ",c->data);c=c->next;}printf("\n");}

int main(){append(3);append(1);append(2);deleteSmallest();display();}
