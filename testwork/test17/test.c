#include<stdio.h>
#include<string.h>
int main()
{
    int arr[5] = {1,2,3,4,5};
    int *left = arr;
    int *right = arr + sizeof(arr) -1;
    int i = 0;
    int tmp = 0;

    while(left < right)
    {
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
   for(i = 0; i < 5;i++)
   {
        printf("%d\n",arr[i]);
   }

    return 0;
}
