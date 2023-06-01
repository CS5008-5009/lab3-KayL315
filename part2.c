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
    struct Node* prev;
};

// Search for a given element
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
        newNode->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
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
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}


// Insert an element at the head
void insertAtHead(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert an element at the end
void insertAtEnd(struct Node** head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        newNode->prev = current;
        current->next = newNode;
    }
}

// Delete an element
void deleteElement(struct Node** head, int element) {
    struct Node* current = *head;

    while (current != NULL) {
        if (current->value == element) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }

    printf("Element not found.\n");
}

// Delete the head
void deleteHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Delete the last element
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
}

// Print all elements in reverse order
void printReverse(struct Node* head) {
    struct Node* current = head;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    printf("Print all elements in reverse order: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
    
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, element, position;

    // Creating the initial linked list
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
        printf("8. Print all the elements in reverse order\n");
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
                printf("Enter the position: ");
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
                printReverse(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
