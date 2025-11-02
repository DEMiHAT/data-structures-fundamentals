#include <stdio.h>
#define SIZE 5

// ---------- Function Declarations ----------
void enqueue(int);
int dequeue();
void display();

// ---------- Global Variables ----------
int queue[SIZE];
int front = -1, rear = -1;

// ---------- Enqueue Function ----------
void enqueue(int item) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = item;
    printf("%d inserted into queue\n", item);
}

// ---------- Dequeue Function ----------
int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int item = queue[front];
    if (front == rear)
        front = rear = -1;
    else if (front == SIZE - 1)
        front = 0;
    else
        front++;

    printf("%d deleted from queue\n", item);
    return item;
}

// ---------- Display Function ----------
void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

// ---------- Main Function ----------
int main() {
    int choice, item;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
}
