#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

// ---------- Function Declarations ----------
void push(char);
char pop();
int precedence(char);
void infixToPostfix(char infix[], char postfix[]);

// ---------- Global Variables ----------
char stack[SIZE];
int top = -1;

// ---------- Push Function ----------
void push(char ch) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

// ---------- Pop Function ----------
char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

// ---------- Precedence Function ----------
int precedence(char ch) {
    switch (ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// ---------- Infix to Postfix Conversion ----------
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch))  // operand
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// ---------- Main Function ----------
int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter Infix Expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
