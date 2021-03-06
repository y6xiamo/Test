#include <stdio.h>
//交换
void Swap(int* a,int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//奇偶交换函数
//奇数在前，偶数在后

void Odd_Even_Swop(int* arr,int beg,int end)
{
    if(arr == NULL)
    {
        return;
    }
    while(beg < end)
    {
        //定义两个数组下标
        //一个从前往后遍历，如果当前值是奇数，
        //继续往后走,知道找到一个不满足当前条件的元素
        while(beg < end && (arr[beg] % 2 != 0))
        {
            beg++;
        }
        //另一个从后往前遍历，如果是偶数，
        //往前走，寻找第一个不满足当前条件的值
        while(beg < end && (arr[end] % 2 == 0))
        {
            end--;
        }
        //走到这，说明找到了分别不满足上述条件的两个元素，交换
        Swap(&arr[beg],&arr[end]);
        //继续遍历
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
