#include<stdio.h>
int main()
{
    long int mul = 1;
    long int sum = 0;

    int i = 0;
    for(i = 1;i <= 20;i++)
    {
        mul = mul * i;
        sum = sum + mul;
    }

    printf("sum = %d\n",sum);
    return 0;
}
