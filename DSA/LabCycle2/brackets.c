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

    if (len == 0) {
        return true;
    }

    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char current_char = s[i];

        if (current_char == '(' || current_char == '{' || current_char == '[') {
            push(stack, current_char);
        }
        else if (current_char == ')' || current_char == '}' || current_char == ']') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return false;
            }
            char top_char = peek(stack);
            if ((current_char == ')' && top_char == '(') ||
                (current_char == '}' && top_char == '{') ||
                (current_char == ']' && top_char == '[')) {
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
    printf("'()[]{}' is %s\n", isValid("()[]{}") ? "valid" : "invalid");
    printf("'(]' is %s\n", isValid("(]") ? "valid" : "invalid");
    printf("'{[]}' is %s\n", isValid("{[]}") ? "valid" : "invalid");
    printf("')(' is %s\n", isValid(")(") ? "valid" : "invalid");
    printf("An empty string '' is %s\n", isValid("") ? "valid" : "invalid");
    printf("'[' is %s\n", isValid("[") ? "valid" : "invalid");

    return 0;
}


