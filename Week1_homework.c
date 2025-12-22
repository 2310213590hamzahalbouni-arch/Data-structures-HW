#include <stdio.h>

#define MAX 100

// Function to display the array
void display(int arr[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert an element at a given position
int insert(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos > n || n >= MAX) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return n + 1;
}

// Delete element at a given position
int delete(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

// Search for a value
void search(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Value %d found at index %d\n", value, i);
            return;
        }
    }
    printf("Value not found.\n");
}

// Update a value at a specific index
void update(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    arr[pos] = value;
}

int main() {
    int arr[MAX], n, choice, pos, value;

    // take initial array input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n===== ARRAY OPERATIONS MENU =====\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                n = insert(arr, n, pos, value);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(arr, n, value);
                break;

            case 5:
                printf("Enter position to update: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(arr, n, pos, value);
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}