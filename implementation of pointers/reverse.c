#include<stdio.h>
int length(char*);
char* reverse(char*);

void main()
{
 printf("%d",length("Computer"));
 printf("\n%s",reverse("Computer"));
}

int length(char* p)
{
 int i;
 for(i=0;*(p+1)!='\0';i++);
 return(i);
}

char* reverse(char* p)
{
 int i,l;
 char t;
 for(l=0;*(p+l)!='\0';l++);
 for(i=0;i<l/2;i++)
 {
  t=*(p+i);
  *(p+i)=*(p+l-1-i);
  *(p+l-1-i)=t;
 }
 return(p);
}







