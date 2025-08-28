#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    int i = 0;
    char ch;
    int val;

    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        } else if (ch == ' ') {
            continue;  // Skip spaces
        } else {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter a postfix expression (e.g., 53+82-*): ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';  // Remove newline character

    int result = evaluatePostfix(expr);
    printf("Result of postfix expression: %d\n", result);
    return 0;
}

