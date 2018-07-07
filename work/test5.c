#include <stdio.h>
#define row 3
#define col 3
//在杨氏矩阵里查找一个元素是否存在
int find(int arr[row][col],int size,int to_find)
{
    if(arr == NULL)
    {
        return 0;
        //非法输入
    }
    if(size <= 0)
    {
        return 0;
        //数组为空，输入错误
    }
    //杨氏矩阵规则：
    //每一行从左往右递增
    //每一列从上往下递增
    int i = 0;
    int j = col - 1;
    //从第0行的最后一列开始比较
    while(i <= row && j >= 0)
    {
        if(to_find < arr[i][j])
        {
            //要查找的元素小于当前数组元素
            //说明在当前元素左边，列减减
            j--;
        }
        else if(to_find > arr[i][j])
        {
            //要查找元素大于当前数组元素
            //说明在当前元素下面，行加加
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[row][col] = {{1,2,3},
                     {5,6,7},
                     {8,9,10}};
    int size = sizeof(arr)/sizeof(arr[0][0]);
    int to_find = 16;
    int ret = find(arr,size,to_find);
    if(ret == 1)
    {
        printf("找到了该元素\n");
    }
    else
    {
        printf("该元素不存在\n");
    }
    return 0;

}

