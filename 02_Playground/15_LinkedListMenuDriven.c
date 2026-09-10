#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    struct node *head = NULL;
    struct node *newnode;
    struct node *temp;

    int i, n;
    int choice;

    // Create initial linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        newnode = malloc(sizeof(struct node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            while (head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    // Menu
    while (1)
    {
        printf("\n\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert at beginning
            newnode = malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }

            printf("Enter data: ");
            scanf("%d", &newnode->data);

            newnode->next = head;
            head = newnode;

            printf("Node inserted at beginning.\n");
            break;

        case 2:
            // Insert at end
            newnode = malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Memory allocation failed\n");
                break;
            }

            printf("Enter data: ");
            scanf("%d", &newnode->data);

            newnode->next = NULL;

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newnode;
            }

            printf("Node inserted at end.\n");
            break;

        case 3:
            // Display
            if (head == NULL)
            {
                printf("Linked list is empty.\n");
            }
            else
            {
                temp = head;

                printf("Linked list: ");

                while (temp != NULL)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }

                printf("\n");
            }
            break;

        case 4:
            // Free memory before exiting
            while (head != NULL)
            {
                temp = head;
                head = head->next;
                free(temp);
            }

            printf("Program exited.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
