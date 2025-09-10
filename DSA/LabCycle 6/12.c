#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int start;
    int size;
    int pid;
    struct Block* prev;
    struct Block* next;
} Block;

Block* head = NULL;

Block* newBlock(int start, int size, int pid){
    Block* b = (Block*)malloc(sizeof(Block));
    b->start = start;
    b->size = size;
    b->pid = pid;
    b->prev = b->next = NULL;
    return b;
}

void appendBlock(Block** h, Block* nb){
    if(!*h){ *h = nb; return; }
    Block* c = *h;
    while(c->next) c = c->next;
    c->next = nb;
    nb->prev = c;
}

void initMemory(int total){
    head = newBlock(0, total, 0);
}

void allocate(int reqSize, int pid){
    Block* c = head;
    while(c){
        if(c->pid==0 && c->size>=reqSize){
            if(c->size == reqSize){
                c->pid = pid;
                return;
            } else {
                Block* alloc = newBlock(c->start, reqSize, pid);
                Block* rem = newBlock(c->start + reqSize, c->size - reqSize, 0);
                alloc->prev = c->prev;
                if(c->prev) c->prev->next = alloc; else head = alloc;
                alloc->next = rem;
                rem->prev = alloc;
                rem->next = c->next;
                if(c->next) c->next->prev = rem;
                free(c);
                return;
            }
        }
        c = c->next;
    }
}

void deallocate(int pid){
    Block* c = head;
    while(c){
        if(c->pid == pid){
            c->pid = 0;
            if(c->next && c->next->pid==0){
                Block* nxt = c->next;
                c->size += nxt->size;
                c->next = nxt->next;
                if(nxt->next) nxt->next->prev = c;
                free(nxt);
            }
            if(c->prev && c->prev->pid==0){
                Block* prv = c->prev;
                prv->size += c->size;
                prv->next = c->next;
                if(c->next) c->next->prev = prv;
                free(c);
            }
            return;
        }
        c = c->next;
    }
}

void printMemory(){
    Block* c = head;
    printf("start\tsize\tpid\n");
    while(c){
        printf("%d\t%d\t%d\n", c->start, c->size, c->pid);
        c = c->next;
    }
    printf("----\n");
}

void compact(){
    Block* c = head;
    int nextStart = 0;
    Block* newHead = NULL;
    int freeTotal = 0;
    while(c){
        Block* nxt = c->next;
        if(c->pid != 0){
            Block* moved = newBlock(nextStart, c->size, c->pid);
            appendBlock(&newHead, moved);
            nextStart += c->size;
        } else {
            freeTotal += c->size;
        }
        free(c);
        c = nxt;
    }
    if(freeTotal > 0){
        Block* freeBlock = newBlock(nextStart, freeTotal, 0);
        appendBlock(&newHead, freeBlock);
    }
    head = newHead;
}

int main(){
    initMemory(1000);
    allocate(120, 1);
    allocate(200, 2);
    allocate(80, 3);
    allocate(150, 4);
    printMemory();
    deallocate(2);
    deallocate(4);
    printMemory();
    compact();
    printMemory();
    return 0;
}
