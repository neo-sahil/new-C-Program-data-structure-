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
void beginsert();
void lastinsert();
void traverse();
int countnode(struct node *st);
void insert_at_mid();
void delete_at_beg();
void delete_at_end();
void delete_at_mid();
void rev_traverse(struct node *temp);

void main()
{
    int option,n;
    do
    {
        printf("-----MAIN MENU-----\n");
        printf("1-for create list\n");
        printf("2-for traverse left to right\n");
        printf("3-for traverse in reverse\n");
        printf("4-for insertion at beggning\n");
        printf("5-for insertion at ending\n");
        printf("6-for insertion at intermidiate position\n");
        printf("7-for counting number of nodes\n");
        printf("8-for deleting a node at beggning\n");
        printf("9-for deleting a node at end\n");
        printf("10-for deleting a node at intermidiate position\n");
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

        case 4: beginsert();
                break;

        case 5: lastinsert();
                printf("Node is inserted\n");
                break;
        
        case 6: insert_at_mid();
                break;

        case 7: printf("Number of nodes are--%d\n",countnode(start));
                break;
        
        case 8: delete_at_beg();
                break;

        case 9: delete_at_end();
                break;

        case 10: delete_at_mid();
                 break;

        default:
            break;
        }
    } while (option != 0);
    printf("Good bye\n");
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

void beginsert()
{
    struct node *ptr = getNode();
    if(ptr==NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        ptr->next=start;
        start=ptr;
        printf("Node is inserted at beggining\n");
    }
}

void lastinsert()
{
    struct node *ptr = getNode();
    struct node *temp=start;

    if(ptr==NULL)
    {
        printf("Overflow\n");
        return;
    }
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->  next=ptr;
    }
}

int countnode(struct node *st)
{
    if(st==NULL)
    {
        return 0;
    }
    else
    {
        return(1+countnode(st->next));
    }
}

void insert_at_mid()
{
    struct node *ptr, *temp , *prev;
    int pos, nodectr, ctr=1;
    ptr=getNode();
    if(ptr==NULL)
    {
        printf("OverFlow\n");
        return;
    }
    printf("Enter the position where you want to insert this node\n");
    scanf("%d",&pos);
    nodectr=countnode(start);
    if(pos>1 && pos<nodectr)
    {
        temp=prev=start;
        while(ctr<pos)
        {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=ptr;
        ptr->next=temp;
        printf("Node is inserted\n");
    }
    else
    {
        printf("this %d is not a middle position",pos);
    }
}

void delete_at_beg()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("No node are exist to delete\n");
    }   
    else
    {
        temp=start;
        start=temp->next;
        free(temp);
        printf("Node is deleted\n");
    }
}

void delete_at_end()
{
    struct node *temp, *prev;
    if(start==NULL)
    {
        printf("No node is exist to delete\n");
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            prev = temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        printf("Node deleted\n");
    }
}

void delete_at_mid()
{
    struct node *temp, *prev;
    int pos, nodectr, ctr=1;
    if(start==NULL)
    {
        printf("No node exist to delete\n");    
    }
    else
    {
        printf("Enter the position of the node which you want to delete\n");
        scanf("%d",&pos);
        nodectr = countnode(start);
        if(pos>1 && pos<nodectr)
        {
            temp=prev=start;
            while(ctr<pos)
            {
                prev=temp;
                temp=temp->next;
                ctr++;
            }
            prev->next=temp->next;
            free(temp);
            printf("Node deleted\n");
        }
        else
        {
            printf("Invalid postion\n");
        }
    }
}