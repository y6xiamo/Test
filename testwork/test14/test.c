#include<stdio.h>
#include<string.h>
int main()
{  
    int old = 0;
    printf("please input a num : ");
    scanf("%d",&old);

    int new = 0;
    int tmp = 0;
    while(old)
    {
        tmp = old % 10;
        old = old / 10;
        new = new * 10 + tmp;
    }
    if(new == old){
        printf(" shi hui wen number\n");
    }
    else{
        printf(" bu shi hui wen number\n");
    }
    return 0;
}
