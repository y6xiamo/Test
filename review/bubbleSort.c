#include <stdio.h>
#include<assert.h>
//用指针
void bubleSort(int arr[],int size)
{
    assert(arr != NULL);
    int *cur = arr;//冒泡的次数
    for( ;cur != &arr[size];cur++)
    {
        int *next = cur + 1;//比较的次数
        for( ;next != &arr[size];next++)
        {
            if(*cur < *next)
            {
                int temp = *cur;
                *cur = *next;
                *next = temp;
            }
        }
    }
}
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
//                int temp = arr[count];
//                arr[count] = arr[cur];
//                arr[cur] = temp;
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
//                int temp = arr[count];
//                arr[count] = arr[cur];
//                arr[cur] = temp;
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
