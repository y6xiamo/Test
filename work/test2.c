#include <stdio.h>
//查找出现次数超过一半的数字
int find_num_more_than_half(int *arr,int size)
{
    if(arr == NULL)
    {
        return 0;
        //非法输入
    }
    int i = 0;
    int count = 0;//用来记录次数
    for( ;i< size;i++)
    {
        //每次用当前元素和他的下一个元素比较
        int j = i + 1;
        while(j < size)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
                j++;
        }
    
        //count >= sixze/2 说明找到了这个元素
        if(count >= size/2)
        {
            return arr[i];
        }
    }
    return 0;
}
int main()
{
    int arr[20] = {1,2,3,2,2,2,5,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int num = find_num_more_than_half(arr,size);
    printf("%d\n",num);
    return 0;
}
