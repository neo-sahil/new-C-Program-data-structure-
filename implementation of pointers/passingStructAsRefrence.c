#include<stdio.h>

typedef struct complex{
    float real;
    float img;
}complex;

void addnumbers(complex c1, complex c2, complex *result);

void main()
{
    complex c1,c2,result;

    printf("Enter first number\n");
    printf("Enter the real part\n");
    scanf("%f",&c1.real);
    printf("Enter the imaginary part\n");
    scanf("%f",&c1.img);

    printf("Enter second number\n");
    printf("Enter the real part\n");
    scanf("%f",&c2.real);
    printf("Enter the imaginary part\n");
    scanf("%f",&c2.img);

    addnumbers(c1,c2,&result);
    printf("Result.real=%f\n",result.real);
    printf("Result.imaginary=%f\n",result.img);
}

void addnumbers(complex c1, complex c2, complex *result)
{
    result->real=c1.real+c2.real;
    result->img=c1.img+c2.img;
}