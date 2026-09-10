#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    struct node *a1, *a2, *a3;
    a1 = malloc(sizeof(struct node));
    a2 = malloc(sizeof(struct node));
    a3 = malloc(sizeof(struct node));

    if (a1 == NULL || a2 == NULL || a3 == NULL)
    {
        printf("Memory allocation failed\n");
        free(a1);
        free(a2);
        free(a3);
        return 1;
    }

    a1->data = 10;
    a1->next = a2;
    a2->data = 20;
    a2->next = a3;
    printf("Enter Value: ");
    scanf("%d", &a3->data);
    a3->next = NULL;

    printf("%d %d %d\n", a1->data, a2->data, a3->data);

    free(a1);
    free(a2);
    free(a3);

    return 0;
}