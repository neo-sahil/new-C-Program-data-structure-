#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node* getnode()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data\n");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    return ptr;
}

void createStack()
{
    struct node *ptr;
    int n=0;
    while(n == 0)
    {
        ptr=getnode();
        if(ptr==NULL)
        {
            printf("Overflow\n");
            return;
        }
        else
        {
            ptr->next=start;
            start=ptr;
            printf("Data is pushed\n");
            printf("If you want to push more data then press 0 otherwise anything\n");
            scanf("%d",&n);
        }
    }
}

void push()
{
    struct node *ptr;
    ptr=getnode();
    if(ptr==NULL)
    {
        printf("OverFlow\n");
        return;
    }
    else
    {
        ptr->next=start;
        start=ptr;
        printf("data is pushed\n");
    }
}

void POP()
{
    struct node *ptr,*temp;
    temp=start;
    if(start==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    else
    {
        start=start->next;
        free(temp);
        printf("data item is poped\n");
    }
}

void traverse()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    printf("\n");
    while(temp->next != NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("---MENU---\n");
        printf("1-create stack\n");
        printf("2-PUSH data in to the stack\n");
        printf("3-POP data from the stack\n");
        printf("4-to traverse data in the stack\n");
        printf("5-exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                createStack();
                printf("Stack is craeted\n");
                break;
            case 2:
                push();
                break;
            case 3:
                POP();
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(0);
                break;
        }
    }
}