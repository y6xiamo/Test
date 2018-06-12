#include<stdio.h>
int main()
{
    int a = 0;//chitao before
    int b = 1;//chitao after

    int i = 0;
    for(i = 1; i < 10; i++)
    {
        a = (b + 1) * 2;
        b = a;
    }

    printf("a = %d\n",a);

    return 0;
}
