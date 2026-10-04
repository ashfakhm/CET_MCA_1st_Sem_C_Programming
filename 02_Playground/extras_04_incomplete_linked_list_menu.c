#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *newnode


void insertBegging()
{
    newnode=malloc(sizeof(struct node));
    printf("Enter the Element: ";);
    scanf("%d",&newnode->data);
    newnode->next=head;
}
void insertEnding()
{

}

int man()
{
    while(1)
    {
        printf("Menu\n")
        printf("****\n")
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Exit")
        printf("Enter Your Choice:\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertBegginging();
                    break;
            case 2:insertEnding();
                    break;
            case 3:return 0;
                    break;
            default:printf("Invalid Entry");
        }


    }
}
