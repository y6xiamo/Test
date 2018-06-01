#include <stdio.h>
#include<stdlib.h>
//输入一个整数数组，奇数在前，偶数在后，并保证奇数和偶数相对位置不变
void Odd_Even_Swop(int* arr,int size,int* new_arr)
{
    if(arr == NULL ||new_arr == NULL)
    {
        return;
    }
   int arr_index = 0;//用于遍历arr数组
   int new_arr_index = 0;//用于遍历new_array数组
   for(;arr_index < size;arr_index++)
   {
       //找到一个奇数
       if(arr[arr_index] % 2 != 0)
       {
           //将它插入到新数组去
           new_arr[new_arr_index] = arr[arr_index];
           new_arr_index++;
       }
   }
//   printf("%d",new_arr_index);
   arr_index = 0;//从头开始重新遍历arr数组 
   for(;arr_index < size;arr_index++)
   {
       //找到一个偶数
       if(arr[arr_index] % 2 == 0)
       {
           //追加到刚才的新数组后面
           new_arr[new_arr_index] = arr[arr_index];
           new_arr_index++;
       }
   }
  return;
}
int main()
{
    int arr[] = {2,1,19,24,78,15,47,38,63,56};
    int size = sizeof(arr)/sizeof(arr[0]);
//    printf("%d",size);
    int* new_arr  =(int*)malloc(sizeof(arr));
    Odd_Even_Swop(arr,size,new_arr);

    int i = 0;
    for( ;i < size;i++)
    {
        printf("%d ",new_arr[i]);
    }
    printf("\n");
    free(new_arr);
    return 0;
}
