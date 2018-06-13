#include<stdio.h>
int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum1 = 0;
    int sum2 = 0;
    int i;
    int j;

    for(i = 0;i < 3; i++)
    {
        sum1 = sum1 + arr[i][i];
    }

    for(i = 0,j = 2;i < 3,j>=0; i++,j--)
    {
        
            sum2 = sum2 + arr[i][j];
        
    }
    printf("sum1 = %d sum2 = %d\n",sum1, sum2);

    return 0;
}

