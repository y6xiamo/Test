#include<stdio.h>
#include<string.h>
//判断一个字符串是否是回文字符串
int main()
{  
    char arr[10] = "accba";
    //定义两个指针，
    //一个从头开始遍历
    //一个从尾部开始遍历
    char *left;
    left = arr;

    char *right; 
    right = arr+strlen(arr)-1; 
    
    

    //
    while((left < right)&&(*left == *right))
    {
        left++;
        right--;
    }
    //
    if(*left == *right)
        printf(" 是回文字符串\n");
    else
        printf(" 不是回文字符串\n");
     
    return 0;
}
