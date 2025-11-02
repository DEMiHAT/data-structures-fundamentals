#include <stdio.h>
#include <stdlib.h>

// ---------- Structure Definition ----------
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// ---------- Global Pointer ----------
struct Node *head = NULL;

// ---------- Function Declarations ----------
void insertBeginning(int);
void insertEnd(int);
void insertPosition(int, int);
void display();

// ---------- Insert at Beginning ----------
void insertBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("%d inserted at the beginning\n", value);
}

// ---------- Insert at End ----------
void insertEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("%d inserted at the end\n", value);
}

// ---------- Insert at Specific Position ----------
void insertPosition(int value, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("%d inserted at position %d\n", value, pos);
}

// ---------- Display Function ----------
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------- Main Function ----------
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
