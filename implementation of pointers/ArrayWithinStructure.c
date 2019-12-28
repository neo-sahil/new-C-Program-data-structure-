#include<stdio.h>
void main()
{
    struct marks
    {
        int sub[3];
        int total;
    };
    struct marks student[3]={45,67,81,0,75,83,69,0,57,36,71,0};
    struct marks total={0,0,0,0};
    int i,j;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            student[i].total+=student[i].sub[j];
            total.sub[i]+=student[j].sub[i];
        }
        total.total+=student[i].total;       
    }
    printf("Students total\n");
    for(i=0;i<=2;i++)
        printf("Student[%d]=%d\n",i+1,student[i].total);

    printf("Subject total\n");
    for(i=0;i<=2;i++)
        printf("subject-%d=%d\n",i+1,total.sub[i]);
    
    printf("Grand tota=%d\n",total.total);
}