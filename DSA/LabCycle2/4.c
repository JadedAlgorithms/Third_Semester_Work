#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Creating a self referencial structure

typedef struct {
    int top;
    unsigned capacity;
    char* data;
}Stack;

Stack* createStack(unsigned capacity)    {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(Stack* stack, char item)    {
    stack->data[++stack->top] = item;
}

char pop(Stack* stack){
    if (stack->top == -1) return '\0';
    return stack->data[stack->top--];
}

bool isPalindrome(char* str) {
    int length = strlen(str);
    Stack* stack = createStack(length);
    int mid = length / 2;
    for (int i = 0; i < mid; i++) {
        push(stack, str[i]);
    }
    int startIndex = mid + (length % 2);
    for (int i = startIndex; i < length; i++) {
        if (str[i] != pop(stack)) {
            free(stack->data);
            free(stack);
            return false;
        }
    }
    free(stack->data);
    free(stack);
    return true;
}
int main() {
    char str1[] = "racecar";
    printf("'%s' is %s\n", str1, isPalindrome(str1) ? "a palindrome." : "not a palindrome.");

    char str2[] = "jadedalgorithms";
    printf("'%s' is %s\n", str2, isPalindrome(str2) ? "a palindrome." : "not a palindrome.");

    return 0;
}