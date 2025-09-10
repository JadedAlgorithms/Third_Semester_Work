#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* prev; struct Node* next; };
struct Node* head = NULL;

struct Node* newNode(int d){ 
    struct Node* t=malloc(sizeof(struct Node)); 
    t->data=d; 
    t->prev=t->next=NULL; 
    return t; }

void insertFront(int d){ 
    struct Node* t=newNode(d);
    if(head){ 
        t->next=head; 
        head->prev=t; } 
    head=t; }

void displayForward(){ 
    struct Node* c=head; 
    while(c){ 
        printf("%d ",c->data); 
        c=c->next; } 
    printf("\n"); }
void displayBackward(){ 
    struct Node* c=head; 
    while(c&&c->next) c=c->next;
    while(c){ 
        printf("%d ",c->data); 
        c=c->prev; } 
    printf("\n"); }

int main(){ 
    insertFront(3); 
    insertFront(2); 
    insertFront(1); 
    displayForward(); 
    displayBackward(); }
