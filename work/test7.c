#include <stdio.h>
#include<stdlib.h>
//奇偶交换
void Odd_Even_Swop(int* arr,int size,int* new_arr)
{
    if(arr == NULL ||new_arr == NULL)
    {
        return;
    }
    int i = 0;
    while(i<size)
    {
        //如果是奇数，直接赋值
        if(arr[i] % 2 != 0)
        {
            new_arr[i] = arr[i];
        }
        i++;
    }
    //有点问题
    //让k走到新数组元素的最后
   int k = 0;
   for( ;k < size;k++)
   {
       if(new_arr[k] == 0)
       {
           break;
       }
   }

   //将偶数赋给新数组，接着奇数的位置
   i = 0;
   while(i<size)
   {
       if(arr[i] % 2 == 0)
       {
           new_arr[k] = arr[i];
       }
       i++;
   }
 return;
}
int main()
{
    int arr[] = {2,1,19,24,78,15,47,38,63,56};

    int size = sizeof(arr)/sizeof(arr[0]);
//    printf("%d",size);
    int* new_arr  =(int*)malloc(sizeof(arr));
    //重新开辟一块空间,存储交换后的元素，原来的数组结构不变
    Odd_Even_Swop(arr,size,new_arr);

    //打印元素
    int i = 0;
    for( ;i < size;i++)
    {
        printf("%d ",new_arr[i]);
    }
    printf("\n");
    free(new_arr);
    return 0;
}
