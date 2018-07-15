#include <stdio.h>
//将一个字符串转换为一个数字
int to_int(char* str,int size)
{
    if(str == NULL)
    {
        return 0;
        //非法输入
    }
    char* start = str;//用于定位这个字符串的开头   
    int num = 0;
    
    if(*str == '+'||*str == '-')
    {
        //碰到正负号跳过
        str++;
    }
    while(*str)
    {
        if(*str <= '0' || *str >= '9')
        {
            //输入字符串不合法,每一个字符必须为数字            return 0;
            return 0;
        }
        num = num * 10 + (*str -'0');
        //将每一个字符转换为数字
        
        str++;
    }
    if(*start == '-')
    {
        num = -num;
        //如果第一个字符为符号，那么这个数字输出为负的
    }
    return num;
}
int main()
{
    char str[] = "-123456";
    int size = sizeof(str)/sizeof(str[0]);
    int ret = to_int(str,size);
    printf("%d\n",ret);
}
