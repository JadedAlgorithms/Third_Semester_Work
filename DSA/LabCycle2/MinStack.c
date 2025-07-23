#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
    int top;
    unsigned capacity;
    char* data;
}Stack;

Stack* unsigned createStack(unsigned capacity)    {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack-> array =(char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack* stack, char item)    {
    stack-> array[++stack->top] = item;
}

char pop(Stack* stack){
    if (stack->top == -1) return '\0';
    return stack->array[stack->top--];
}

typedef struct {
    Stack* mainStack;
    Stack* minStack;
} MinStack;


MinStack* createMinStack(unsigned capacity) {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->mainStack = createStack(capacity);
    minStack->minStack = createStack(capacity);
    return minStack;
}


void minStackPush(MinStack* s, int value) {
    push(s->mainStack, value);
    if (isEmpty(s->minStack) || value <= peek(s->minStack)) {
        push(s->minStack, value);
    }
}


int minStackPop(MinStack* s) {
    int popped_val = pop(s->mainStack);
    if (popped_val == peek(s->minStack)) {
        pop(s->minStack);
    }
    return popped_val;
}


int getMin(MinStack* s) {
    if (isEmpty(s->minStack)) {
        return INT_MAX;
    }
    return peek(s->minStack);
}

void freeMinStack(MinStack* s) {
    free(s->mainStack->array);
    free(s->mainStack);
    free(s->minStack->array);
    free(s->minStack);
    free(s);
}

int main() {
    MinStack* s = createMinStack(10);

    minStackPush(s, 5);
    minStackPush(s, 3);
    minStackPush(s, 4);
    minStackPush(s, 2);

    printf("Current minimum is: %d\n", getMin(s));

    minStackPop(s);
    printf("After popping, current minimum is: %d\n", getMin(s));

    minStackPop(s);
    printf("After popping again, current minimum is: %d\n", getMin(s));
    freeMinStack(s);

    return 0;
}