#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at front – O(1)
void insertFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end – O(n)
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert in middle (after a specific value) – O(n)
void insertAfter(struct Node* head, int target, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target value not found!\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from front – O(1)
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end – O(n)
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {  // only one node
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
}

// Delete a specific value – O(n)
void deleteValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (prev == NULL) { // first node
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Traversal – O(n)
void traverse(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Traverse\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at End\n");
        printf("4. Insert After Value\n");
        printf("5. Delete Front\n");
        printf("6. Delete End\n");
        printf("7. Delete Specific Value\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(head);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 4:
                printf("Insert after which value? ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfter(head, target, value);
                break;

            case 5:
                deleteFront(&head);
                break;

            case 6:
                deleteEnd(&head);
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(&head, value);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}