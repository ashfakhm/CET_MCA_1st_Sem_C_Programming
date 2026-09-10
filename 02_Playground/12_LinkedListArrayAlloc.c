#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

int main(void)
{
    struct linkedlist *linkedlists;

    linkedlists = malloc(3 * sizeof(struct linkedlist));
    if (linkedlists == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    linkedlists[0].data = 10;
    linkedlists[0].next = &linkedlists[1];

    linkedlists[1].data = 20;
    linkedlists[1].next = &linkedlists[2];

    linkedlists[2].data = 30;
    linkedlists[2].next = NULL;

    printf("Value is %d\n", linkedlists[0].data);
    printf("Value is %d\n", linkedlists[1].data);
    printf("Value is %d\n", linkedlists[2].data);

    free(linkedlists);

    return 0;
}
