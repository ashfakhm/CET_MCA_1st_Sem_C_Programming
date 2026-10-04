#include <stdio.h>

#define SIZE 100

static void insert(int values[], int *count)
{
    int position;
    int value;

    if (*count == SIZE) {
        printf("Array is full.\n");
        return;
    }
    printf("Enter position (1-%d): ", *count + 1);
    if (scanf("%d", &position) != 1 || position < 1 || position > *count + 1) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter value: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        return;
    }
    for (int index = *count; index >= position; index--)
        values[index] = values[index - 1];
    values[position - 1] = value;
    (*count)++;
    printf("Inserted %d.\n", value);
}

static void delete_element(int values[], int *count)
{
    int position;

    if (*count == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter position (1-%d): ", *count);
    if (scanf("%d", &position) != 1 || position < 1 || position > *count) {
        printf("Invalid position.\n");
        return;
    }
    int deleted = values[position - 1];
    for (int index = position - 1; index < *count - 1; index++)
        values[index] = values[index + 1];
    (*count)--;
    printf("Deleted %d.\n", deleted);
}

static void search(const int values[], int count)
{
    int target;
    int found = 0;

    printf("Enter value to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return;
    }
    for (int index = 0; index < count; index++) {
        if (values[index] == target) {
            printf("Found at position %d.\n", index + 1);
            found = 1;
        }
    }
    if (!found)
        printf("Value not found.\n");
}

static void display(const int values[], int count)
{
    printf("Array: ");
    for (int index = 0; index < count; index++)
        printf("%d ", values[index]);
    printf("\n");
}

int main(void)
{
    int values[SIZE];
    int count;
    int choice;

    printf("Enter number of initial elements (0-%d): ", SIZE);
    if (scanf("%d", &count) != 1 || count < 0 || count > SIZE) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (int index = 0; index < count; index++) {
        if (scanf("%d", &values[index]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    do {
        printf("\n--- Array Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
        case 1:
            insert(values, &count);
            break;
        case 2:
            delete_element(values, &count);
            break;
        case 3:
            search(values, count);
            break;
        case 4:
            display(values, count);
            break;
        case 5:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
    





