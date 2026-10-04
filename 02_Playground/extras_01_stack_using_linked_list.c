#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    while (1) {
        printf("\n--- Linked List Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add an element to the stack
void push() {
    int val;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow! (Memory allocation failed)\n");
        return;
    }
    
    printf("Enter the value to push: ");
    scanf("%d", &val);
    
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    
    printf("Pushed %d into the stack.\n", val);
}

// Function to remove an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! (Stack is empty)\n");
        return;
    }
    
    struct node *temp = top;
    printf("Popped value: %d\n", temp->data);
    top = top->next;
    free(temp); // Free memory of the deleted node
}

// Function to view the top element without removing it
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Function to display all stack elements
void display() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct node *temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}








