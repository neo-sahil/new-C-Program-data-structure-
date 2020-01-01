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
void traverse();
void rev_traverse(struct node *temp);

void main()
{
    int option;
    do
    {
        printf("-----MAIN MENU-----\n");
        printf("1-for create list\n");
        printf("2-for traverse left to right\n");
        printf("3-for traverse in reverse\n");
        printf("4-for insertion at ending\n");
        printf("5-for insertion at begginng\n");
        printf("0-for exit\n");
        scanf("%d",&option);

        switch (option)
        {
        case 1: create();
            printf("linked list created!\n"); 
            break;

        case 2: traverse();
              break;

        case 3: rev_traverse(start);
                break;

        default:
            break;
        }
    } while (option != 0);
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

void traverse()
{
    struct node *temp;
    temp=start;
    if(start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("content of the list:\n");
        while(temp != NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void rev_traverse(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        rev_traverse(temp->next);
        printf("%d  ",temp->data);
    }
}