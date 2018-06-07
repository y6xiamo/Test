#include <stdio.h>
int find_first_repeat_num(int arr[],int len,int* num)
{
    if(arr == NULL && num == NULL)
    {
        return 0;
    }
    int left = 0;
    while(left < len)
    {
        int  right = len - 1;
        while(left < right)
        {
            if(arr[left] == arr[right])
            {
                *num = arr[left];
                return 1;
            }
            right--;
        }
        left++;

    }
    return 0;
}
int main()
{
    int arr[] = {2,6,1,0,2,5,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    int num = 0;
    int ret = find_first_repeat_num(arr,len,&num);
    if(ret == 1)
    {
        printf("找到了第一个重复的数字：%d\n",num);
    }
    else
    {
        printf("没有找到重复的数字\n");
    }
    return 0;
}
