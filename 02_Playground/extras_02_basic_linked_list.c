#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    
    struct node *next;
};
int main()
{
    struct node *newnode,*new2node,*new3node,*temp;
    newnode=malloc(sizeof(struct node));
    new2node=malloc(sizeof(struct node));
    new3node=malloc(sizeof(struct node));
    newnode->data=10;
    newnode->next = new2node;
    new2node->data=20;
    new2node->next = new3node;
    new3node->data=30;
    new3node->next = NULL;
    //printf("list consist of : %d %d %d",newnode->data,new2node->data,new3node->data);
    temp=newnode;
    while(temp != NULL){
        printf("value :%d\n",temp->data);
        temp=temp->next;
    }
    return 0;
}
