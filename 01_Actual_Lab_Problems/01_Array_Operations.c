#include <stdio.h>
#include <stdlib.h>

void insert(int *a, int *n, int item, int pos)
{
    for (int i = *n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = item;
    (*n)++;
}

void delete(int *a, int *n, int pos)
{
    for (int i = pos; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void search(int *a, int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("Item Found At Index: %d\n", i);
            return;
        }
    }
    printf("Item Not Found\n");
}

void display(int *a, int n)
{
    printf("Elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int *a, limit, n, item, pos, choice;

    printf("Enter The Array Limit: ");
    scanf("%d", &limit);
    a = (int *)malloc(limit * sizeof(int));

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n1. Insert  2. Delete  3. Search  4. Display  5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter The Element To Insert: ");
            scanf("%d", &item);
            printf("Enter The Position To Insert: ");
            scanf("%d", &pos);
            insert(a, &n, item, pos);
            break;
        case 2:
            printf("Enter The Index To Delete: ");
            scanf("%d", &pos);
            delete(a, &n, pos);
            break;
        case 3:
            printf("Enter The Item To Search: ");
            scanf("%d", &item);
            search(a, n, item);
            break;
        case 4:
            display(a, n);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Option\n");
        }
    } while (choice != 5);

    free(a);
    return 0;
}