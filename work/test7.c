#include <stdio.h>
#include<stdlib.h>
void Odd_Even_Swop(int* arr,int size,int* new_arr)
{
    if(arr == NULL ||new_arr == NULL)
    {
        return;
    }
    int i = 0;
    while(i<size)
    {
        if(arr[i] % 2 != 0)
        {
            new_arr[i] = arr[i];
        }
        i++;
    }
//    int k = 0;
//    for( ;k < size;k++)
//    {
//        if(new_arr[k] == 0)
//        {
//            break;
//        }
//    }
//    i = k;
//    while(i<size)
//    {
//        if(arr[i] % 2 == 0)
//        {
//            new_arr[i] = arr[i];
//        }
//        i++;
//    }
    return;
}
int main()
{
    int arr[] = {2,1,19,24,78,15,47,38,63,56};
    int size = sizeof(arr)/sizeof(arr[0]);
//    printf("%d",size);
    int* new_arr  =(int*)malloc(sizeof(arr));
    Odd_Even_Swop(arr,size,new_arr);

    int i = 0;
    for( ;i < size;i++)
    {
        printf("%d ",new_arr[i]);
    }
    printf("\n");
    free(new_arr);
    return 0;
}
