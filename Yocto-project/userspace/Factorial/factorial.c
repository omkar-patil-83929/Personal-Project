#include<stdio.h>
#include<stdlib.h>

int factoarial(int num);
int main(int argc,char *argv[])
{
    unsigned int num;
    if(argc<=1)
    {
        printf("Invalid command argument\n");
        exit(EXIT_FAILURE);
    }
    
    num = atoi(argv[1]);
    printf("Factorial of %d is %d\n",num,factorial(num));
    return (0);
}

int factorial(int num)
{
    if(num==0)  
        return (0);
    else if(num==1)
        return (1);
    else
        return num * factorial(num-1);
}