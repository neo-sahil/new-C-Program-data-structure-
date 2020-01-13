#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front;
    int rear;
    int capacity;
    int *array;
};

struct queue *createqueue(int cap)
{
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->capacity=cap;
    q->front=-1;
    q->rear=-1;
    q->array=malloc(sizeof(int)*q->capacity);
    return(q);
}

void enqueue(struct queue *q, int item)
{
    if(q->rear == q->capacity-1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        if(q->front==-1 && q->rear==-1)
        {
            q->front=q->rear=0;
        }
        else
        {
            q->rear++;
        }
        q->array[q->rear]=item;
        printf("data is inserted into the queue\n");
    }
}

void dequeue(struct queue *q)
{
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        q->array[q->front]=NULL;
        if(q->front == q->rear)
            q->front=q->rear=0;
        else
            q->front=q->front+1;

        printf("Data is deleted and release fron the queue\n");
    }
}

void peek(struct queue *q)
{
    int n;
    n=q->front;
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        while(n != q->rear+1)
        {
            printf("%d  ",q->array[n]);
            n++;
        }
        printf("\n");
    }
}

void main()
{
    int choice, item;
    int cap;
    struct queue *q;
    printf("Enter the capacity of the queue\n");
    scanf("%d",&cap);
    q=createqueue(cap);
    while(1)
    {
        printf("\n---main menu---\n");
        printf("---------------\n");
        printf("1-for enqueue\n");
        printf("2-for dequeue\n");
        printf("3-for traversal\n");
        printf("4-for exit\n");
        printf("\nEnter your choice?");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data you wnat to inseart\n");
                scanf("%d",&item);
                enqueue(q,item);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Please enter a valid choice\n");
        }
    }
}