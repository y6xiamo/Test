#include<stdio.h>
#include<stdlib.h>

void fun()
{
    int *p=malloc(sizeof(int));
    p[10]= 100 ;

}
int main()
{
    fun();
    printf("finish\n");
    return 0;
}
