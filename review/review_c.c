#include <stdio.h>
//判断一个机器是大端还是小端
int check_sys2()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c;
}
int check_sys()
{
    int i = 1;
    return (*(char*)&i);
}
int main()
{
    unsigned i;
    for(i = 9;i >= 0;i--)
    {
        printf("%u\n",i);
    }
//    int i = -20;
//    unsigned int j = 10;
//    printf("%d\n",i+j);
//    char a = -1;
//    signed char b = -1;
//    unsigned char c = -1;
//
//    printf("a = %d b = %d c = %d\n",a,b,c);
 //   int ret = check_sys2();
 //   if(ret == 1)
 //   {
 //       printf("大端\n");
 //   }
 //   else
 //   {
 //       printf("小端\n");
 //   }

    return 0;
}
