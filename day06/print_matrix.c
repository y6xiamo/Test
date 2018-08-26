#include <stdio.h>
#define row 4
#define col 4
//顺时针打印矩阵
void PrintMatrixClockwisely(int arr[row][col])
{
    if(arr == NULL)
    {
        return;
    }
    int start = 0;
    while((row>start*2) && (col>start*2))
    {
        PrintMatrixInCircle(arr,start);
        ++start;
    }
}
//在圆里打印矩阵，分四步
void PrintMatrixInCircle(int arr[row][col],int start)
{
    if(arr == NULL)
    {
        return;
    }
    //由start算出（endx,endy)
    int endx = start + row -1;
    int endy = start + col -1;
    //第一步，从左到右打印
    int i = 0;
    for( ;i <= endx;i++)
    {
        printf("%d ",arr[start][i]);
    }
    //第二步，从上到下打印
    if(start < endy)
    {
        for(i = start + 1;i <= endy;i++)
        {
            printf("%d ",arr[i][endy]);
        }
    }
    //第三步，从右往左打印
    if(start < endx && start < endy)
    {
        for(i = endx-1;i >= start;i--)
        {
            printf("%d ",arr[endx][i]);
        }
    }
    //第四步，从下往上打印
    if(start > 0)
    {
        for(i = endx -1;i >= start + 1;i--)
        {
            printf("%d ",arr[i][start]);
        }
    }
    
}
int main()
{
    int arr[row][col] = {{1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12},
                         {13,14,15,16}};

    PrintMatrixClockwisely(arr);
    return 0;

}
