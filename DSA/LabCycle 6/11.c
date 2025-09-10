#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void initMemory(int totalSize){
    head = newBlock(0, totalSize, 0);
}

void insertAfter(Block* pos, Block* nb){
    nb->next = pos->next;
    nb->prev = pos;
    if(pos->next) pos->next->prev = nb;
    pos->next = nb;
}

void replaceBlockWith(Block* old, Block* first, Block* second){
    if(old->prev) old->prev->next = first;
    else head = first;
    first->prev = old->prev;
    first->next = second;
    if(second) second->prev = first;
    free(old);
}

void splitAndAllocate(Block* freeBlock, int reqSize, int pid){
    if(freeBlock->size == reqSize){
        freeBlock->pid = pid;
        return;
    }
    Block* allocated = newBlock(freeBlock->start, reqSize, pid);
    Block* remaining = newBlock(freeBlock->start + reqSize, freeBlock->size - reqSize, 0);
    if(freeBlock->prev) freeBlock->prev->next = allocated;
    else head = allocated;
    allocated->prev = freeBlock->prev;
    allocated->next = remaining;
    remaining->prev = allocated;
    remaining->next = freeBlock->next;
    if(freeBlock->next) freeBlock->next->prev = remaining;
    free(freeBlock);
}

void mergeIfPossible(Block* b){
    if(!b) return;
    if(b->next && b->pid==0 && b->next->pid==0){
        Block* nxt = b->next;
        b->size += nxt->size;
        b->next = nxt->next;
        if(nxt->next) nxt->next->prev = b;
        free(nxt);
    }
    if(b->prev && b->pid==0 && b->prev->pid==0){
        Block* prv = b->prev;
        prv->size += b->size;
        prv->next = b->next;
        if(b->next) b->next->prev = prv;
        free(b);
    }
}

int allocate_first_fit(int reqSize, int pid){
    Block* c = head;
    while(c){
        if(c->pid==0 && c->size>=reqSize){
            splitAndAllocate(c, reqSize, pid);
            return 1;
        }
        c = c->next;
    }
    return 0;
}

int allocate_best_fit(int reqSize, int pid){
    Block* c = head;
    Block* best = NULL;
    while(c){
        if(c->pid==0 && c->size>=reqSize){
            if(!best || c->size < best->size) best = c;
        }
        c = c->next;
    }
    if(best){
        splitAndAllocate(best, reqSize, pid);
        return 1;
    }
    return 0;
}

int allocate_worst_fit(int reqSize, int pid){
    Block* c = head;
    Block* worst = NULL;
    while(c){
        if(c->pid==0 && c->size>=reqSize){
            if(!worst || c->size > worst->size) worst = c;
        }
        c = c->next;
    }
    if(worst){
        splitAndAllocate(worst, reqSize, pid);
        return 1;
    }
    return 0;
}

void deallocate(int pid){
    Block* c = head;
    while(c){
        if(c->pid == pid){
            c->pid = 0;
            mergeIfPossible(c);
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

int main(){
    initMemory(1000);
    allocate_first_fit(100, 1);
    allocate_first_fit(200, 2);
    allocate_best_fit(150, 3);
    allocate_worst_fit(50, 4);
    printMemory();
    deallocate(2);
    printMemory();
    allocate_best_fit(120, 5);
    printMemory();
    deallocate(1);
    deallocate(3);
    mergeIfPossible(head);
    printMemory();
    return 0;
}
