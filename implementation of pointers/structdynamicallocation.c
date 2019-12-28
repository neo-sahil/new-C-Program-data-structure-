#include<stdio.h>
#include<stdlib.h>
struct person
{
    int age;
    float weight;
    char name[30];
};
void main()
{
    struct person *ptr;
    int i,n;

    printf("Enter the number of persons:\n");
    scanf("%d",&n);

    ptr = (struct person*)malloc(n*sizeof(struct person));

    for(i=0;i<n;i++)
    {
        printf("Enter first name and respectively:\n");
        scanf("%s%d",(ptr+i)->name,&(ptr+i)->age);
    }
    printf("Displaying information\n");
    for(i=0;i<n;i++)
    {
        printf("Name:%s\n age:%d\n",(ptr+i)->name,(ptr+i)->age);
    }
}