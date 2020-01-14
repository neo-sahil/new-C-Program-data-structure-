#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

struct node *getnode()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert into the queue\n");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    return ptr;
}

void enqueue()
{
    struct node *ptr;
    ptr = getnode();
    if(ptr == NULL)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next=NULL;
            rear->next=NULL;
        }
        else if(front->next == NULL)
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
            front->next=ptr;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
        }
        printf("data is inserted\n");
    }
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp=front;
        front=front->next;
        free(temp);
        printf("Data is deleted\n");
    }
}

void peek()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp=front;
        while(temp != NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n===Main Menu===\n");
        printf("===============\n");
        printf("1-for the insertion\n");
        printf("2-for the deletion\n");
        printf("3-for the traversal\n");
        printf("4-for exit\n");
        printf("Enter your chioce? ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please Enter a valid chioce\n");
        }
    }
}