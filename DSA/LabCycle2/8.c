#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}

char pop() {
    if (top >= 0)
        return stack[top--];
    else
        return '\0';  // Stack underflow
}

int isEmpty() {
    return top == -1;
}

int isAccepted(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isEmpty()||input[i]==stack[top]) {
            push(input[i]);
        } else if(input[i]!=stack[top]){
            pop(); // Match a 1 with a 0
        } else {
            return 0; // Invalid character
        }
    }

    return isEmpty(); // Accepted only if stack is empty
}

int main() {
    char input[100];
    printf("Enter a binary string (only 0s and 1s): ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("The string is accepted by the PDA.\n");
    else
        printf("The string is NOT accepted by the PDA.\n");

    return 0;
}

