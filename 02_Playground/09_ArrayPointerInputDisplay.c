#include <stdio.h>

int main(void)
{

    printf("Enter the Size Of Array You Want:\n");
    int size;
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size\n");
        return 1;
    }

    int arr[size];
    int *ptr = arr;

    // Enter array elements using pointer
    for (int i = 0; i < size; i++)
    {
        printf("Enter The Element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    // Display array elements using pointer
    printf("The Array Now Has These Elements:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", *(ptr + i));
    }

    return 0;
}
