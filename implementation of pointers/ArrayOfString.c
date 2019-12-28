#include<stdio.h>
void main()
{
    //char city[4][12]={"chennai","kolkata","mumbai","New Delhi"};
    //or
    char *city[4]={"chennai","kolkata","mumbai","New Delhi"};
    //temparory variable

    int r,c;
    //print citites
    for(r=0;r<4;r++)
    {
        c=0;
        while(*(city[r]+c)!='\0')
        {
            printf("%c",*(city[r]+c));
            c++;
        }
        printf("\n");
    }
}