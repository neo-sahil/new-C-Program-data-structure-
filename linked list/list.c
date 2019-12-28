#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *getNode();
struct node *create();

void main()
{
    int option;
    do
    {
        printf("-----MAIN MENU-----\n");
        printf("1-for create list\n");
        printf("2-for insertion at ending\n");
        printf("3-for insertion at begginng\n");
        printf("0-for exit\n");
        scanf("%d",&option);

        switch (option)
        {
        case 1: create();
            printf("linked list created!\n"); 
            break;
        default:
            break;
        }
    } while (option != 4);
    
}

struct node *getNode()
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the node:\n");
    scanf("%d",&new->data);
    new->next=NULL;
    return new;
}

struct node *create()
{
    struct node *new, *p;
    int n=0;
    while (n != -1)
    {
        new = getNode();
        if(start == NULL)
        {
            start = new;
            printf("Node is created and inserted!!\n");
        }
        else
        {
            p=start;
            while(p->next!=NULL){
                p=p->next;
            }
            p->next = new;
            printf("Node is created and inserted!!\n");
        }
        printf("if you want to add more node press '0'\n otherwise press '-1' \n");
        scanf("%d",&n);
    }
    
}
