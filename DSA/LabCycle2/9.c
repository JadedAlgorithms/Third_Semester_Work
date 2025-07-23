#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int isOperand(char c) {
    return isalnum(c); // checks if the character is a letter or digit
}

int isRightAssociative(char op) {
    return op == '^'; // exponentiation is right-associative
}

void reverse(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Swap '(' and ')' in a string [helper function for reverse]
void swapBrackets(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

// Convert Infix to Postfix
void infixToPostfix(char* infix, char* postfix) {  //postfix acts as output location
    int j = 0;
    for (int i = 0; infix[i]; i++) { //loops till infix[i] != "\0"
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && isOperator(peek()) &&
                   (precedence(peek()) > precedence(ch) ||
                    (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();
    
    postfix[j] = '\0';
}

// Infix to Prefix
void infixToPrefix(char* infix, char* prefix) {
    char revInfix[MAX], postfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);
    swapBrackets(revInfix);
    top = -1; // reset stack
    infixToPostfix(revInfix, postfix); //postfix takes the output
    reverse(postfix);
    strcpy(prefix, postfix);
}

// ---------- MAIN FUNCTION ---------- //

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    char choice;

    printf("Enter an infix expression (no spaces): ");
    scanf("%s", infix);
    getchar();
    
    printf("Conversion:\n");
    printf("1. To Postfix\n");
    printf("2. To Prefix\n");
    printf("Enter choice: ");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            infixToPostfix(infix, postfix);
            printf("Postfix expression: %s\n", postfix);
            break;
        case '2':
            infixToPrefix(infix, prefix);
            printf("Prefix expression: %s\n", prefix);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
