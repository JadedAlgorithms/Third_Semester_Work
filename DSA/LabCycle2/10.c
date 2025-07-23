#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100
int stack[MAX];
int top = -1;

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char expr[]) {
    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }
    return pop();
}

// Evaluate prefix expression
int evaluatePrefix(char expr[]) {
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }
    return pop();
}

int main() {
	char postfix[MAX], prefix[MAX];
    char choice;
    
    printf("Conversion:\n");
    printf("1. Postfix evaluation\n");
    printf("2. Prefix evaluation\n");
    printf("Enter choice: ");
    scanf("%c", &choice);
    getchar();

    switch (choice) {
        case '1':
            printf("Enter a postfix expression [single digits]: ");
            scanf("%s",postfix);
            printf("Solution: %d\n",evaluatePostfix(postfix));            
            break;
        case '2':
            printf("Enter a prefix expression [single digits]: ");
            scanf("%s",prefix);
            printf("Solution: %d\n",evaluatePrefix(postfix));
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
