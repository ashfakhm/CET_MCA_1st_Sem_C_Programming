#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *newnode,*head=NULL,*temp;
    int i,n;
    printf("Enter the no of nodes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter the data");
        scanf("%d",&newnode->data);

        if(temp==NULL)
        {

        }
    }

}
