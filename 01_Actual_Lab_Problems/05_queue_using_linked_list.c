#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static void enqueue(struct node **front, struct node **rear)
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
    new_node->next = NULL;
    if (*rear == NULL)
        *front = new_node;
    else
        (*rear)->next = new_node;
    *rear = new_node;
    printf("Enqueued %d.\n", value);
}

static void dequeue(struct node **front, struct node **rear)
{
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node *removed = *front;
    printf("Dequeued %d.\n", removed->data);
    *front = removed->next;
    if (*front == NULL)
        *rear = NULL;
    free(removed);
}

static void display(const struct node *front)
{
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

static void free_queue(struct node *front)
{
    while (front != NULL) {
        struct node *removed = front;
        front = front->next;
        free(removed);
    }
}

int main(void)
{
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice;

    while (1) {
        printf("\n--- Linked-List Queue ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
        case 1:
            enqueue(&front, &rear);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            display(front);
            break;
        case 4:
            free_queue(front);
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    free_queue(front);
    return 1;
}
