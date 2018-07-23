#include <stdio.h>
//int getMaxSum(int array[],int len)
//{
//    if(array == NULL)
//    {
//        return 0;
//        //非法输入
//    }
//    if(len > 3000)
//    {
//        return 0;
//        //非法输入
//    }
//    int i = 0;
//    //用于遍历这个数组，是枚举子序列的起点
//    int max_sum = 0;//最大连续数列和
//    for( ;i < len; ++i)
//    {
//        int j = i;
//        //枚举子序列的终点
//        for( ;j < len;++j)
//        {
//            int sum = 0;
//            //每一个子序列的和
//            int k = i;
//            //下面这个循环用于求出每个子序列的和
//            for( ; k <= j ;++k)
//            {
//                sum += array[k];
//            }
//            //如果子序列的和大于最大子序列的和
//            //就用他替换掉最大子序列之和
//            if(sum > max_sum)
//            {
//                max_sum = sum;
//            }
//
//        }
//    }
//    return max_sum;
//
//}
int getMaxSum(int array[],int len)
{
    if(array == NULL)
    {
        return 0;
        //非法输入
    }
    if(len > 3000)
    {
        return 0;
        //非法输入
    }
    int max_sum = 0;//用来保存最大连续数列之和
    int sum = 0;//用来保存每个数列之和

    
}
int main()
{
    int array[] = {0,-1,0,-4,0,0};
    int len = sizeof(array)/sizeof(array[0]);
    int max_sum = getMaxSum(array,len);
    printf("max_sum is %d\n",max_sum);
    return 0;
}


