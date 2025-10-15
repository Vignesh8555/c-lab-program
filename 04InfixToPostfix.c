#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    if (top >= 99) {
        printf("Stack Overflow!");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    switch (symbol) {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void main() {
    char infix[100], postfix[100];
    char item, temp;
    int i = 0, j = 0;

    clrscr();

    printf("Enter the infix expression: ");
    gets(infix);

    while (infix[i] != '\0') {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j] = item;
            j++;
        }
        else if (item == '(') {
            push(item);
        }
        else if (item == ')') {
            while ((temp = pop()) != '(') {
                postfix[j] = temp;
                j++;
            }
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j] = pop();
                j++;
            }
            push(item);
        }
        i++;
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("\nPostfix expression is: %s", postfix);

    getch();
}
