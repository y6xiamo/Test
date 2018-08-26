#include <stdio.h>
#include<assert.h>
void Swap(int* a,int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//用区间来分割
void bubleSort(int arr[],int size)
{
    if(arr == NULL)
    {
        return;
    }
    if(size <= 1)
    {
        return;
    }
    //[0,bound)表示有序区间
    //[bound,size)表示待排序区间
    int bound = 0;
    for( ;bound < size;bound++)
    {
        int cur = size -1;
        for(;cur > bound;cur--)
        {
            if(arr[cur] > arr[cur-1])
            {
                Swap(&arr[cur],&arr[cur-1]);
            }
        }
    }
}
//用指针
//void bubleSort(int arr[],int size)
//{
//    assert(arr != NULL);
//    int *cur = arr;//冒泡的次数
//    for( ;cur != &arr[size];cur++)
//    {
//        int *next = cur + 1;//比较的次数
//        for( ;next != &arr[size];next++)
//        {
//            if(*cur < *next)
//            {
//                Swap(cur,next);
//            }
//        }
//    }
//}
//升序
//void bubleSort(int arr[],int size)
//{
//    assert(arr != NULL);
//    int count = 0;//冒泡的次数
//    for( ;count < size;count++)
//    {
//        int cur = count + 1;//比较的次数
//        for( ;cur < size;cur++)
//        {
//            if(arr[count] > arr[cur])
//            {
//               Swap(&arr[count],&arr[cur]);
//            }
//        }
//    }
//}
//降序
//void bubleSort(int arr[],int size)
//{
//    assert(arr != NULL);
//    int count = 0;//冒泡的次数
//    for( ;count < size;count++)
//    {
//        int cur = count + 1;//比较的次数
//        for( ;cur < size;cur++)
//        {
//            if(arr[count] < arr[cur])
//            {
//                Swap(&arr[count],&arr[cur]);
//            }
//        }
//    }
//}
int main()
{
    int arr[] = {2,6,16,9,4,2,7,3,0,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size = %d\n",size);
    bubleSort(arr,size);
    int i = 0;
    for(;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
