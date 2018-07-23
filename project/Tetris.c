#include <stdio.h>
#include<stdlib.h>

#define N 6

void infeat_around(int arr[][N],int i,int j)
{
    if(i < 0 ||i >= N ||j < 0|| j >= N ||arr[i][j] != 1)
    {
        return;
    }
    arr[i][j] = 2;
    infeat_around(arr,i-1,j);//上面
    infeat_around(arr,i+1,j);//下面
    infeat_around(arr,i,j+1);//左面
    infeat_around(arr,i,j-1);//右面
    

}
//求一个数组有多少拐
int land(int arr[N][N],int m,int n)
{
    int land = 0;
    int i = 0;
    for( ;i < m;i++)
    {
        int j = 0;
        for(; j< n;j++)
        {
            if(arr[i][j] == 1)
            {
                land++;
                //感染周围
                infeat_around(arr,i ,j);
            }

        }

    }
    return land;
}
int main()
{
    int arr[N][N] = {
        1,1,1,0,0,0,
        1,0,0,0,1,1,
        1,0,0,0,1,0,
        0,0,1,1,1,0,
        0,0,0,0,0,0,
        1,1,1,0,0,0,
    };
    printf("land = %d\n",land(arr,N,N));
    return 0;
}
////旋转二维数组的四个角
//void rotate(int arr[N][N],int a,int b,int c,int d)
//{
//    int i = 0;
//    for( ;i < d - b;i++)
//    {
//        int tmp = arr[a][b+i];
//        arr[a][b+i] = arr[c-i][b];//将左下角的数赋给左上角
//        arr[c-i][b] = arr[c][d-i];//将右下角的数赋给左下角
//        arr[c][d-i] = arr[a+i][d];//将右上角的数赋给右下角
//        arr[a+i][d] = tmp;//将左上角赋给右上角
//    }
//}
//
////数组的旋转
//void rotateArr(int arr[N][N])
//{
//    int a = 0;//表示第一行
//    int b = 0;//表示第一列
//    int c = N - 1;//表示最后一行
//    int d = N - 1;//表示最后一列
//    {
//        rotate(arr,a++,b++,c--,d--);
//    }
//}
//
//void show(int arr[N][N])
//{
//    int i = 0;
//    for( ;i < N;i++)
//    {
//        int j = 0;
//        for( ;j < N;j++)
//        {
//            printf("%-3d",arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[N][N];
//    int i = 0;
//    int num = 1;
//    for( ;i < N;i++)
//    {
//        int j = 0;
//        for( ;j < N;j++)
//        {
//            arr[i][j] = num;
//            num++;
//        }
//    }
//    show(arr);
//    printf("\n");
//    rotateArr(arr);
//    show(arr);
//    
//    return 0;
//}
