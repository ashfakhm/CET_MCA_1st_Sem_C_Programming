#include <stdio.h>

#define CAPACITY 5

void enqueue(int queue[], int *front, int *rear)
{
        int value;

        if ((*rear + 1) % CAPACITY == *front) {
                printf("Queue is full.\n");
                return;
        }
        printf("Enter a value: ");
        scanf("%d", &value);
        if (*front == -1)
                *front = 0;
        *rear = (*rear + 1) % CAPACITY;
        queue[*rear] = value;
        printf("%d added to the queue.\n", value);
}

void dequeue(int queue[], int *front, int *rear)
{
        int value;

        if (*front == -1) {
                printf("Queue is empty.\n");
                return;
        }
        value = queue[*front];
        if (*front == *rear) {
                *front = -1;
                *rear = -1;
        } else {
                *front = (*front + 1) % CAPACITY;
        }
        printf("Removed: %d\n", value);
}

void display(int queue[], int front, int rear)
{
        if (front == -1) {
                printf("Queue is empty.\n");
                return;
        }
        printf("Queue: ");
        while (1) {
                printf("%d ", queue[front]);
                if (front == rear)
                        break;
                front = (front + 1) % CAPACITY;
        }
        printf("\n");
}

int main(void)
{
        int queue[CAPACITY];
        int front = -1;
        int rear = -1;
        int choice;

        while (1) {
                printf("\n--- Circular Queue ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                        enqueue(queue, &front, &rear);
                        break;

                case 2:
                        dequeue(queue, &front, &rear);
                        break;

                case 3:
                        display(queue, front, rear);
                        break;

                case 4:
                        return 0;

                default:
                        printf("Invalid choice. Please choose 1 to 4.\n");
                }
        }
}
