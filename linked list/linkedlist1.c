//inserting node at the begining of linked list

#include<stdio.h>
#include<stdlib.h>
void begininsert(int);
struct node
{
    int data;
    struct node *next;
    
};
struct node *head;
void main()
{
    int choice, item;
    do{
        printf("Enter the item you wnat to insert?\n");
        scanf("%d",&item);
        begininsert(item);
        printf("Press 0 to insert more or 1 to eixt\n");
        scanf("%d",&choice);
    }while(choice==0);
}

void begininsert(int item)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr==NULL)
    {
        printf("OVERFLOW\n");
    }
    else{
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("node inserted\n");
    }
}