#include <stdio.h>
//反转一个区间，可以是一个句子也可以是一个单词
void reverse_word(char arr[],int left,int right)
{
    char tmp;
    while(left < right)
    {
        //从前往后两两交换
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
 //   return;
}
void reverse_string(char arr[],int size)
{
    if(arr == NULL)
    {
        return;
        //非法输入
    }
    int i = 0;
    int left = 0;
    int right = 0;
    //先将整个句子反转
    reverse_word(arr,0,size-1);
    while(i <= size)
    {
        //碰到一个空格，说明一个单词结束
        //将这个单词反转，标点符号也包括到单词中
        if(arr[right] == ' ')
        {
            reverse_word(arr,left,right-1);
            //更新right和left指针，使其指向下一个单词
            right++;
            left = right;
        }
        else
        {
            //不等于空格，继续向后查找
            right++;
        }
        i++;

    }
//    return;
}
int main()
{
    char arr[] = "I like BeiJing.";
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",size);
    printf("%s\n",arr);

    //反转一个字符串，不改变标点符号的顺序
    //例如："I like BeiJing."需要改成 "BeiJing. like I"
    reverse_string(arr,size-1);
    printf("%s\n",arr);
    return 0;
}
