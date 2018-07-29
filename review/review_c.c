#include <stdio.h>
#include<string.h>
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

//unsigned char i = 0;
int main()
{
    //浮点数的存储
//    int n = 9;
//    float *pFloat = (float*)&n;
//    printf("n的值为：%d\n",n);
//    printf("*pFloat的值为：%f\n",*pFloat);
//
//    *pFloat = 9.0;
//    printf("n的值为：%d\n",n);
//    printf("*pFloat的值为：%f\n",*pFloat);
//

//    for(i = 0;i <= 255;i++)
//    {
//        puts("hello world!\n");
//        //死循环，无符号char范围为0~255，超过255溢出，将前面的位数丢弃，重劫从0开始
//    }

//    short num = 32767;
//    short int a = num + 1;
//    printf("%d\n",a);
//    char a[1000];
//
//    int i = 0;
//    for( ;i < 1000;i++)
//    {
//        a[i] = -1-i;
//    }
//    printf("%d\n",strlen(a));

 //   unsigned i;
 //   for(i = 9;i >= 0;i--)
 //   {
 //       printf("%u\n",i);//死循环，无符号数减到0再-1，会变成一个非常大的数
 //   }
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
