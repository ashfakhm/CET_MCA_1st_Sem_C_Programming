#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_element();
void delete_element();
void insert_at_beginning();
void insert_at_end();
void insert_at_position();
void delete_at_beginning();
void delete_at_end();
void delete_at_position();
void search();
void display();
void free_list();

int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_element();
                break;

            case 2:
                delete_element();
                break;

            case 3:
                display();
                break;

            case 4:
                search();
                break;

            case 5:
                free_list();
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

void insert_element() {
    int option;
    printf("\n1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1)
        insert_at_beginning();
    else if (option == 2)
        insert_at_end();
    else if (option == 3)
        insert_at_position();
    else
        printf("Invalid option.\n");
}

void delete_element() {
    int option;
    printf("\n1. Delete from beginning\n");
    printf("2. Delete from end\n");
    printf("3. Delete from position\n");
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1)
        delete_at_beginning();
    else if (option == 2)
        delete_at_end();
    else if (option == 3)
        delete_at_position();
    else
        printf("Invalid option.\n");
}

void insert_at_beginning() {
    int value;
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insert_at_end() {
    int value;
    struct node *newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert_at_position() {
    int value, position;

    printf("Enter position (0-based): ");
    scanf("%d", &position);

    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insert_at_beginning();
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void delete_at_position() {
    int position;

    printf("Enter position (0-based): ");
    scanf("%d", &position);

    if (position < 0 || head == NULL) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (position == 0) {
        delete_at_beginning();
        return;
    }

    struct node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct node *deleted = temp->next;
    temp->next = deleted->next;
    free(deleted);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Linked list: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void search() {
    int target;
    int position = 1;
    struct node *temp = head;

    printf("Enter value to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }

    while (temp != NULL) {
        if (temp->data == target) {
            printf("Found at position %d.\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value not found.\n");
}

void free_list() {
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
