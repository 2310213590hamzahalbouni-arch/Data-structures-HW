#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Singly Linked List Node (for recursive delete)
struct SNode {
    int data;
    struct SNode* next;
};

// Add element at the end of a doubly linked list
void insertEnd(struct DNode** head, int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) { 
        *head = newNode;
        return;
    }

    struct DNode* temp = *head;

    // go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Recursively delete all nodes in a singly linked list
void deleteAllRecursive(struct SNode* head) {
    if (head == NULL)
        return;

    deleteAllRecursive(head->next); // go to end
    free(head); // delete on return
}

// Create singly linked list node
struct SNode* createSNode(int value) {
    struct SNode* n = (struct SNode*)malloc(sizeof(struct SNode));
    n->data = value;
    n->next = NULL;
    return n;
}

// Insert a new node after a given target value (doubly linked list)
void insertAfter(struct DNode* head, int target, int value) {
    struct DNode* temp = head;

    // find target value
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target value not found.\n");
        return;
    }

    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Print doubly linked list
void traverseD(struct DNode* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Print the theory part (normal explanation)
void printTheory() {
    printf("\n--- Difference Between Linked List and Circular Linked List ---\n\n");

    printf("Normal Linked List:\n");
    printf("- Last node points to NULL.\n");
    printf("- Traversal ends when NULL is found.\n\n");

    printf("Circular Linked List:\n");
    printf("- Last node points back to the first node.\n");
    printf("- Traversal continues in a loop.\n\n");

    printf("--- Sorting Algorithm Notes ---\n");
    printf("Bubble Sort: O(n^2) on both arrays and linked lists.\n");
    printf("Selection Sort: O(n^2).\n");
    printf("Insertion Sort: Works better on linked lists because insertion is O(1).\n");
    printf("Merge Sort: Best choice for linked lists.\n");
}

int main() {

    struct DNode* dHead = NULL;

    // Insert elements at end
    insertEnd(&dHead, 10);
    insertEnd(&dHead, 20);
    insertEnd(&dHead, 30);

    printf("After inserting at end:\n");
    traverseD(dHead);

    // Insert between
    insertAfter(dHead, 20, 25);
    printf("After inserting 25 after 20:\n");
    traverseD(dHead);

    // Recursive delete for singly linked list
    struct SNode* sHead = createSNode(1);
    sHead->next = createSNode(2);
    sHead->next->next = createSNode(3);

    printf("\nDeleting all elements of singly linked list recursively...\n");
    deleteAllRecursive(sHead);
    printf("All nodes deleted.\n");

    // Print theory explanation
    printTheory();

    return 0;
}