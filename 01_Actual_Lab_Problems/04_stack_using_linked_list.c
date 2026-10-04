#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static void push(struct node **top)
{
    int value;
    struct node *new_node = malloc(sizeof(*new_node));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter value: ");
    if (scanf("%d", &value) != 1) {
        free(new_node);
        printf("Invalid input.\n");
        return;
    }
    new_node->data = value;
    new_node->next = *top;
    *top = new_node;
    printf("Pushed %d.\n", value);
}

static void pop(struct node **top)
{
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *removed = *top;
    printf("Popped %d.\n", removed->data);
    *top = removed->next;
    free(removed);
}

static void peek(const struct node *top)
{
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Top value: %d\n", top->data);
}

static void display(const struct node *top)
{
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

static void free_stack(struct node *top)
{
    while (top != NULL) {
        struct node *removed = top;
        top = top->next;
        free(removed);
    }
}

int main(void)
{
    struct node *top = NULL;
    int choice;

    while (1) {
        printf("\n--- Linked-List Stack ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
            break;
        case 5:
            free_stack(top);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    free_stack(top);
    return 1;
}
