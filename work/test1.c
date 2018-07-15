#include <stdio.h>
//将一个字符串转换为一个数字
int to_int(char* str,int size)
{
    if(str == NULL)
    {
        return 0;
        //非法输入
    }
    char* start = str;
    
    int num = 0;
    
    if(*str == '+'||*str == '-')
    {
        str++;
    }
    while(*str)
    {
        if(*str <= '0' || *str >= '9')
        {
            return 0;
        }
        num = num * 10 + (*str -'0');
        str++;
    }
    if(*start == '-')
    {
        num = -num;
    }
    return num;
}
int main()
{
    char str[] = "123456";
    int size = sizeof(str)/sizeof(str[0]);
    int ret = to_int(str,size);
    printf("%d\n",ret);
}
