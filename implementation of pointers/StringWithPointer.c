#include<stdio.h>
void main()
{
    char str[6]="hello"; // string variable
    char *ptr=str; // poniter variable insted of this we can also use 
                   // char *ptr="hello";
    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");
}