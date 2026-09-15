#include <stdio.h>
#include <stdlib.h>

void push(int *s, int *top, int limit, int item)
{
    if (*top == limit - 1)
    {
        printf("Stack Overflow! Cannot push %d\n", item);
    }
    else
    {
        (*top)++;
        s[*top] = item;
        printf("Inserted %d into the stack.\n", item);
    }
}

void pop(int *s, int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow! No elements to pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", s[*top]);
        (*top)--;
    }
}

void display(int *s, int top)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack Elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}

int main()
{
    int *s, limit, top = -1, item, choice;

    printf("Enter Stack Limit (Capacity): ");
    scanf("%d", &limit);

    s = (int *)malloc(limit * sizeof(int));

    do
    {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &item);
            push(s, &top, limit, item);
            break;
        case 2:
            pop(s, &top);
            break;
        case 3:
            display(s, top);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Option\n");
        }
    } while (choice != 4);

    free(s);
    return 0;
}