#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack* createstack(int cap)
{
    struct Stack *s;
    s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    s->capacity=cap;
    s->array=malloc(sizeof(int)*s->capacity);
    return(s);
}

int isFull(struct Stack *s)
{
    if(s->top == s->capacity-1)
        return(1);
    else
        return(0);
}

int isEmpty(struct Stack *s)
{
    if(s->top == -1)
        return(1);
    else
        return(0);
}

void push(struct Stack *s, int item)
{
    if(isFull(s))
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        s->top++;
        s->array[s->top]=item;
        printf("item is pushed\n");
    }
}

void pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Underflow\n");
        return; 
    }
    else
    {
        s->top--;
        printf("item from the top of the stack is poped\n");
    }
}

void peek(struct Stack *s)
{
    int n = s->top;
    printf("\nitems in the stack\n");
    if(isEmpty(s))
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        while(n != -1)
        {
            printf("%d\n",s->array[n]);
            n=n-1;
        }
    }
}

void main()
{
    struct Stack *s;
    int choice, item, n;

    printf("Enter the capacity of the stack\n");
    scanf("%d",&n);
    s=createstack(n);
    while(1)
    {
        printf("1-push\n");
        printf("2-pop\n");
        printf("3-peek\n");
        printf("4-exit\n");

        printf("Enter your chioce\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the item you want push\n");
                scanf("%d",&item);
                push(s,item);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                exit(0);
        }
    }
}