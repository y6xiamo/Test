#include <stdio.h>
#include<string.h>
#include<math.h>
int find_same(int arr1[],int arr2[],int len1,int len2)
{

    int i = 0;
    int j = 0;
//    while(i < len1 && j < len2)
//    {
        for(;i < len1;i++)
        {
            j = 0;
            for( ;j < len2;j++)
            {
                  if(arr1[i] == arr2[j])
                  {
                      return 1;
                  }
                  else
                  {
                      return 0;
                  }
            }
        }
          
 //   }
}

int bin_search(int arr[],int left,int right,int key)
{
    printf("key = %d\n",key);
    while(left <= right)
    {
        int mid = left + ((left + right)>>1);
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key > arr[mid])
        {
            left = mid +1;
            
        }
        else
        {
            right = mid - 1;
        }
        left ++;
        right--;
    }
    return -1;
}

//enum Sex
//{
//    MALE,
//    FEMALE,
//    SECRET
//};
//void test()
//{
//    static int num = 0;
//    num++;
//    printf("%d\n",num);
//}
int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n*fun(n - 1);
    }
}
void swap(int* a,int* b)
{
//    int temp = *a;
//    *a = *b;
//    *b = temp;

//    *a = *a + *b;
//    *b = *a - *b;
//    *a = *a - *b;
 
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void test1(int arr[])
{
    printf("arr[] = %d\n",sizeof(arr));
}
void test2(char ch[])
{
    printf("ch[] = %d\n",sizeof(ch));
}

//判断闰年
int is_leap_year(int year)
{
    if(year % 400 == 0 ||(year / 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//判断一个数是不是素数
int is_prime_num(int num)
{
    int i = 2;
    while(i <= num/2)
    //while(i <= sqrt(num))
    {
        if(num % i == 0)
        {
            break;
        }
        i++;
    }
    if(i > num/2)
//    if(i > sqrt(num))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Add(int* count)
{
   ++*count;
    return *count;
}
int main()
{
//      char arr[] = {'a','b','c','d','e','f'};

//    printf("%d\n",sizeof(arr));
//    printf("%d\n",sizeof(arr+0));
//    printf("%d\n",sizeof(*arr));
//    printf("%d\n",sizeof(arr[1]));
//    printf("%d\n",sizeof(&arr));
//    printf("%d\n",sizeof(&arr+1));
//    printf("%d\n",sizeof(&arr[0]+1));
    
//    printf("%d\n",strlen(arr));
//    printf("%d\n",strlen(arr+0));
//    printf("%d\n",strlen(*arr));
//    printf("%d\n",strlen(arr[1]));
//    printf("%d\n",strlen(&arr));
//    printf("%d\n",strlen(&arr+1));
//    printf("%d\n",strlen(&arr[0]+1));
 //   int a[] = {1,2,3,4};
 //   printf("%d\n",sizeof(a));
 //   printf("%d\n",sizeof(a+0));
 //   printf("%d\n",sizeof(*a));
 //   printf("%d\n",sizeof(a+1));
 //   printf("%d\n",sizeof(a[1]));
 //   printf("%d\n",sizeof(&a));
 //   printf("%d\n",sizeof(*&a));
 //   printf("%d\n",sizeof(&a+1));
 //   printf("%d\n",sizeof(&a[0]));
 //   printf("%d\n",sizeof(&a[0]+1));

//    int count = 0;
//    int ret = Add(&count);
//     ret = Add(&count);
//    ret = Add(&count);
//    printf("ret = %d\n",ret);
//    int num = 17;
//    int ret = is_prime_num(num);
//    if(ret == 1)
//    {
//        printf("是素数\n");
//    }
//    else
//    {
//        printf("不是素数\n");
//    }
//    int year = 2000;
//    int ret = is_leap_year(year);
//    if(ret == 1)
//    {
//        printf("是闰年\n");
//    }
//    else
//    {
//        printf("不是闰年\n");
//    }
//    int a= 1;
//    int b = 2;
//    int c = (a>b,a = b + 10,a,b = a + 1);
//    printf("c = %d\n",c);
//    int i = 0;
//    int a = 0;
//    int b = 2;
//    int c = 3;
//    int d = 4;
//   i = a++&&++b&&d++;
//   i = a++||++b||d++;
//    printf("a = %d\n b = %d\n c = %d\n d = %d\n i = %d\n",a,b,c,d,i);
//    int arr[10] = {0};
//    printf("%p\n",&arr);
//    printf("%p\n",&arr + 1);
//    printf("%p\n",arr);
//    printf("%p\n",arr + 1);
//    int s = 3;
//    int a = 20;
//    printf("%d\n",sizeof(s = a + 1));
//    int arr[10] = {0};
//    char ch[10] = {0};
//    printf("arr = %d\n",sizeof(arr));
//    printf("ch = %d\n",sizeof(ch));
//    test1(arr);
//    test2(ch);
  //  int a = -10;
  //  int *p = NULL;
  //  printf(" %d\n",!2);
  //  printf("%d\n",!0);
  //  a = -a;
  //  p = &a;

  //  printf("%d\n",sizeof(a));
  //  printf("%d\n",sizeof(int));
//    int a = 10;
//    int b = 20;
//    swap(&a,&b);
//    printf("a = %d\n",a);
//    printf("b = %d\n",b);

//    int num = 10;
//    int count = 0;
//   // int i = 0;
//    while(num)
//    {
//        count++;
//        num = num & (num-1);
//    }
//    for(;i < 32;i++)
//    {
//        if(((num>>i) & 1) == 1)
//        {
//            count++;
//        }
//    }
//    printf("count = %d\n",count);
//    int arr[] = {0,6,13,25,43,76,98,320,432};
//    int size = sizeof(arr)/sizeof(arr[0]);
//    int key = 43;
//    int left = 0;
//    int right = size - 1;
//    int ret = bin_search(arr,left,right,key);
//    if(ret > 1)
//    {
//        printf("找到了,下标是:%d\n",ret);
//    }
//    else
//    {
//        printf("没找到\n");
//    }

//    int i = 1;
//    int mul = 1;
//    for( ;i <= 6;i++)
//    {
//        mul *= i;
//    }
//    printf("mul = %d\n",mul);
 //   int i = 1;
 //   int sum = 0;
 //   int mul = 1;
 //   for( ;i <= 10;i++)
 //   {
 //       mul *= i;
 //       sum += mul;
 //   }
 //   printf("sum = %d\n",sum);
//    int n = fun(6);
//    printf("%d\n",n);
//      int i = 0;
//      int k = 0;
//      int count = 0;
//      for(i = 0,k = 0;k = 0;i++,k++)
//      {
//          printf("hahaha\n");
//          k++;
//          count++;
//      }
//      printf("%d\n",count);
//    int *p;
//    *p = 20;//段错误，对空指针解引用
//    int arr1[10] = {1,2,4,7,8,23,0,45,16};
//    int arr2[10] = {10,389,109,21,42,57,3,5,21};
//    int len1 = sizeof(arr1);
//    int len2 = sizeof(arr2);
//    int a = find_same(arr1,arr2,len1,len2);
//    printf("%d\n",a);
//    int i = 0;
//    for(;i < 100;i++)
//    {
//        if(i % 2 != 0)
//        {
//            printf("%d ",i);
//        }
//    }
//    int a = 1;
//    int b = 0;
//    int c = -1;
//    int d = 0;
//    d = ++a || ++b && ++c;
//    printf("d = %d",d);
 //   int num = 10;
 //   int num2 = 0;
 //   const int * p1 = &num;
 //   *p1 = 20;
 //   printf("num = %d\n",num);

 //   int * const p2 = &num2;
 //   p2 = &num;

 //   const int * const p3 = &num;
 //   *p3 = 12;
 //   p3 = &num2;

   // int x = 0;
   //}
   // else if(x == 0)
   // {
   //     y = 0;
   // }
   // else
   // {
   //     y = -1;
   // }
   // printf("y = %d\n",y);
   // printf("%d\n",43);
   // int i = 43;
   // printf("%d\n",printf("%d\n",printf("%d\n",i)));
    //printf返回打印的字符数
//    int i = 0;
//    for( ;i < 10;i++)
//    {
//        test();
//    }
//    printf("%d\n",MALE);//0
//    printf("%d\n",FEMALE);//1
//    printf("%d\n",SECRET);//2

//    const int sz = 10;
//    int arr[10];
//    int arr2[sz];

  //  const int num = 10;
  //  num = 20;
  //  printf("num = %d\n",num);
   // printf("%d\n",sizeof(char));//1
   // printf("%d\n",sizeof(short));//2
   // printf("%d\n",sizeof(int));//4
    //printf("%d\n",sizeof(long));//8
    //printf("%d\n",sizeof(long long));//8
    //printf("%d\n",sizeof(float));//4
    //printf("%d\n",sizeof(double));//8
   // printf("%d\n",strlen("abcdef"));//6
   // printf("%d\n",strlen("c:\test\32\test.c"));//13
    return 0;

  //  printf("%c\n",070);
  //  //070表示3个8进制数 = 56,对应字符数为8
  // printf("%d\n",0x030);
  // //0x00表示3个十六进制数 = 48
}
