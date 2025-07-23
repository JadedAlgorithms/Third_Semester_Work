#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isEmpty(Stack* stack) { return stack->top == -1; }
void push(Stack* stack, int item) { stack->array[++stack->top] = item; }
int pop(Stack* stack) { return stack->array[stack->top--]; }

bool searchStack(Stack* mainStack, int target) {
    if (isEmpty(mainStack)) {
        return false;
    }

    Stack* auxStack = createStack(mainStack->capacity);
    bool found = false;

    while (!isEmpty(mainStack)) {
        int temp = pop(mainStack);
        if (temp == target) {
            found = true;
            break;
        }
        push(auxStack, temp);
    }

    while (!isEmpty(auxStack)) {
        push(mainStack, pop(auxStack));
    }

    free(auxStack->array);
    free(auxStack);

    return found;
}

int main() {
    Stack* myStack = createStack(10);
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    push(myStack, 40);

    int target1 = 30;
    if (searchStack(myStack, target1)) {
        printf("Element %d found in the stack.\n", target1);
    } else {
        printf("Element %d not found in the stack.\n", target1);
    }

    int target2 = 99;
    if (searchStack(myStack, target2)) {
        printf("Element %d found in the stack.\n", target2);
    } else {
        printf("Element %d not found in the stack.\n", target2);
    }

    free(myStack->array);
    free(myStack);

    return 0;
}