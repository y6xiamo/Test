#include <stdio.h>
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
    }
    int i = 0;
    int max_sum = 0;
    for( ;i < len; ++i)
    {
        int j = i;
        for( ;j < len;++j)
        {
            int sum = 0;
            int k = i;
            for( ; k <= j ;++k)
            {
                sum += array[k];
            }
            if(sum > max_sum)
            {
                max_sum = sum;
            }

        }
    }
    return max_sum;

}
int main()
{
    int array[] = {0,-1,0,-4,0,0};
    int len = sizeof(array)/sizeof(array[0]);
    int max_sum = getMaxSum(array,len);
    printf("max_sum is %d\n",max_sum);
    return 0;
}


