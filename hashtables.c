#include <stdio.h>
#define SIZE 10   

void insert(int hashTable[], int key);
void display(int hashTable[]);

void insert(int hashTable[], int key) {
    int index = key % SIZE;
    int i, flag = 0;

    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            flag = 1;
            break;
        }
    }

    if (flag)
        printf("Element %d inserted successfully.\n", key);
    else
        printf("Hash table is full! Insertion failed.\n");
}

void display(int hashTable[]) {
    printf("\n--- HASH TABLE ---\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> EMPTY\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    int choice, key;

    // Initialize hash table with -1 (indicating empty slots)
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    do {
        printf("\n--- HASHING OPERATIONS ---\n");
        printf("1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                insert(hashTable, key);
                break;

            case 2:
                display(hashTable);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
