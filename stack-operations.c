#include <stdio.h>
#define SIZE 50

int stack[SIZE];
int top = -1;

void push();
void pop();
void display();

void push() {
    int elem;
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter element to push: ");
        scanf("%d", &elem);
        top++;
        stack[top] = elem;
        printf("Element %d pushed onto stack.\n", elem);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
