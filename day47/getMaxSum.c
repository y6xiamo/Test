#include <stdio.h>
int getMaxSum(int array[],int len)
{
    if(array == NULL)
    {
        return 0;
    }
    if(len > 3000)
    {
        return 0;
    }
    int i = 0;
    int sum = 0;
    while(i < len)
    {
        if(array[i] >= 0)
        {
            sum += array[i];
            ++i;
        }
        else
        {
            break;
        }
    }
    return sum;

}
int main()
{
    int array[5] = {1,2,3,-6,1};
    int len = sizeof(array)/sizeof(array[0]);
    int max_sum = getMaxSum(array,len);
    printf("max_sum is %d\n",max_sum);
    return 0;
}


