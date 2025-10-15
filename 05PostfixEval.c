#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int evaluatePostfix(const char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            switch (ch) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                default: printf("Invalid operator: %c\n", ch); break;
            }
        }
    }
    return pop();
}

void main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
   
    int result = evaluatePostfix(postfix);
    printf("Result of postfix evaluation: %d\n", result);
}
