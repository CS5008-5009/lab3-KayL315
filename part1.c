/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

// Function to search for a given element in the linked list
int searchElement(struct Node* head, int element) {
    struct Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->value == element) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1;
}

// Insert an element in the linked list
void insertElement(struct Node** head, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        int currentPosition = 1;

        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Insert an element at the head
void insertAtHead(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = *head;
    *head = newNode;
}

// Insert an element at the end
void insertAtEnd(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

// Delete an element
void deleteElement(struct Node** head, int element) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current != NULL && current->value == element) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->value != element) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Delete the head
void deleteHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete the last element
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
}

// Print all elements
void printAll(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, element, position;

    insertAtEnd(&head, 23);
    insertAtEnd(&head, 52);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 100);

    while (1) {
        printf("1. Search for a given element\n");
        printf("2. Insert element in the middle\n");
        printf("3. Insert element at the head of the linked list\n");
        printf("4. Insert element at the end\n");
        printf("5. Delete element from the middle\n");
        printf("6. Delete head of the linked list\n");
        printf("7. Delete last element of the linked list\n");
        printf("8. Print all the elements\n");
        printf("9. Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a numnber to search: ");
                scanf("%d", &element);
                position = searchElement(head, element);
                if (position == -1) {
                    printf("Element not found in the list.\n");
                } else {
                    printf("Element found at position %d.\n", position);
                }
                break;
            case 2:
                printf("Enter a numnber to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(&head, element, position);
                break;
            case 3:
                printf("Enter a numnber to insert at the head: ");
                scanf("%d", &element);
                insertAtHead(&head, element);
                break;
            case 4:
                printf("Enter a numnber to insert at the end: ");
                scanf("%d", &element);
                insertAtEnd(&head, element);
                break;
            case 5:
                printf("Enter a numnber to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;
            case 6:
                deleteHead(&head);
                break;
            case 7:
                deleteLast(&head);
                break;
            case 8:
                printAll(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
