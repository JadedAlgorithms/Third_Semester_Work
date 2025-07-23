#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (stack->top == stack->capacity - 1) return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) return CHAR_MIN;
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) return CHAR_MIN;
    return stack->array[stack->top];
}

bool isValid(char* s) {
    int len = strlen(s);

    if (len == 0) {
        return true;
    }

    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char current_char = s[i];

        if (current_char == '0') {
            push(stack, current_char);
        }
        else if (current_char == '1') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return false;
            }

            char top_char = peek(stack);
            if (top_char == '0') {
                pop(stack);
            } else {
                free(stack->array);
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);

    free(stack->array);
    free(stack);

    return result;
}

int main() {
    printf("'01' is %s\n", isValid("01") ? "valid" : "invalid");
    printf("'0011' is %s\n", isValid("0011") ? "valid" : "invalid");
    printf("'0101' is %s\n", isValid("0101") ? "valid" : "invalid");
    printf("'10' is %s\n", isValid("10") ? "valid" : "invalid");
    printf("'001' is %s\n", isValid("001") ? "valid" : "invalid");

    return 0;
}