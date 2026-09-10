

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

    printf("Enter the no of Nodes: ");
    scanf("%d", &n);

    if (n <= 0)
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
            return 1;
        }

        printf("Enter Data: ");
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

    // Printing
    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    int ch = 0;
    while (ch != 4)
    {
        printf("\n1.Insert At Beggining");
        printf("\n2.Insert At Ending");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nSelect Your Choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            newnode = malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("\nMemory allocation failed\n");
                break;
            }
            printf("\nEnter the Element You Want To Insert:");
            scanf("%d", &newnode->data);
            printf("You Inserted : %d\n", newnode->data);
            newnode->next = head;
            head = newnode;
        }
        else if (ch == 2)
        {
            if (head == NULL)
            {
                printf("\n List is empty, insert at beginning first\n");
            }
            else
            {
                newnode = malloc(sizeof(struct node));
                if (newnode == NULL)
                {
                    printf("\nMemory allocation failed\n");
                    break;
                }
                printf("\nEnter the Element You Want To Insert:");
                scanf("%d", &newnode->data);
                printf("You Inserted : %d\n", newnode->data);
                newnode->next = NULL;
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }

        else if (ch == 3)
        {
            temp = head;

            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\n Invalid Choice");
        }
    }

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
