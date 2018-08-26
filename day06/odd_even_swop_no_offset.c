#include <stdio.h>
//这个版本可以实现奇数在前，偶数在后，
//但是奇数和奇数，偶数和偶数相对位置变了
void Swap(int* a,int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void Odd_Even_Swop(int* arr,int beg,int end)
{
    if(arr == NULL)
    {
        return;
    }
    //定义两个指针，一个从头开始遍历，一个从尾部开始
    while(beg < end)
    {
        //循环结束表示找到一个奇数
        while(beg < end && (arr[beg] % 2 != 0))
        {
            beg++;
        }
        //循环结束表示找到一个偶数
        while(beg < end && (arr[end] % 2 == 0))
        {
            end--;
        }
        Swap(&arr[beg],&arr[end]);
        beg++;
        end--;
    }
    return;
}
int main()
{
    int arr[] = {2,1,19,24,78,15,47,38,63,56};
    int size = sizeof(arr)/sizeof(arr[0]);
//    printf("%d",size);
    Odd_Even_Swop(arr,0,size-1);

    int i = 0;
    for( ;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
