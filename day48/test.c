#include <stdio.h>
#include<string.h>
//enum Sex
//{
//    MALE,
//    FEMALE,
//    SECRET
//};
void test()
{
    static int num = 0;
    num++;
    printf("%d\n",num);
}
int main()
{
    int i = 0;
    for( ;i < 10;i++)
    {
        test();
    }
//    printf("%d\n",MALE);
//    printf("%d\n",FEMALE);
//    printf("%d\n",SECRET);

//    const int sz = 10;
//    int arr[10];
//    int arr2[sz];

  //  const int num = 10;
  //  num = 20;
  //  printf("num = %d\n",num);
   // printf("%d\n",sizeof(char));
   // printf("%d\n",sizeof(short));
   // printf("%d\n",sizeof(int));
   // printf("%d\n",sizeof(long));
   // printf("%d\n",sizeof(long long));
   // printf("%d\n",sizeof(float));
   // printf("%d\n",sizeof(double));
   // printf("%d\n",strlen("abcdef"));
   // printf("%d\n",strlen("c:\test\32\test.c"));
    return 0;

  //  printf("%c\n",070);
  // printf("%d\n",0x030);
}
