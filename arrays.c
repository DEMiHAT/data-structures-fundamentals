#include <stdio.h>

void insert(int arr[], int *n);
void deleteElement(int arr[], int *n);
void display(int arr[], int n);
void search(int arr[], int n);

void insert(int arr[], int *n) {
    int pos, elem;
    printf("Enter position to insert (1 to %d): ", *n + 1);
    scanf("%d", &pos);
    printf("Enter element to insert: ");
    scanf("%d", &elem);

    if (pos < 1 || pos > *n + 1)
        printf("Invalid position!\n");
    else {
        for (int i = *n - 1; i >= pos - 1; i--)
            arr[i + 1] = arr[i];
        arr[pos - 1] = elem;
        (*n)++;
        printf("Element inserted successfully.\n");
    }
}

void deleteElement(int arr[], int *n) {
    int pos, elem;
    printf("Enter position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
        printf("Invalid position!\n");
    else {
        elem = arr[pos - 1];
        for (int i = pos - 1; i < *n - 1; i++)
            arr[i] = arr[i + 1];
        (*n)--;
        printf("Deleted element: %d\n", elem);
    }
}

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void search(int arr[], int n) {
    int elem, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &elem);
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found.\n");
}

int main() {
    int arr[50], n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(arr, &n); break;
            case 2: deleteElement(arr, &n); break;
            case 3: display(arr, n); break;
            case 4: search(arr, n); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
