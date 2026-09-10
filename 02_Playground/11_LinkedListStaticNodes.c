#include <stdio.h>
#include <stdlib.h>

struct linkedlist
{
    int data;
    struct linkedlist *next;
};

int main(void)
{
    struct linkedlist *newlinkedlist, *new2linkedlist, *new3linkedlist;
    newlinkedlist = malloc(sizeof(struct linkedlist));
    if (newlinkedlist == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    newlinkedlist->data = 10;
    newlinkedlist->next = NULL;

    new2linkedlist = malloc(sizeof(struct linkedlist));
    if (new2linkedlist == NULL)
    {
        printf("Memory allocation failed\n");
        free(newlinkedlist);
        return 1;
    }
    new2linkedlist->data = 20;
    newlinkedlist->next = new2linkedlist;
    new2linkedlist->next = NULL;

    new3linkedlist = malloc(sizeof(struct linkedlist));
    if (new3linkedlist == NULL)
    {
        printf("Memory allocation failed\n");
        free(newlinkedlist);
        free(new2linkedlist);
        return 1;
    }
    new3linkedlist->data = 30;
    new2linkedlist->next = new3linkedlist;
    new3linkedlist->next = NULL;

    printf("Value is %d \n", newlinkedlist->data);
    printf("Value is %d \n", new2linkedlist->data);
    printf("Value is %d \n", new3linkedlist->data);

    free(newlinkedlist);
    free(new2linkedlist);
    free(new3linkedlist);

    return 0;
}