#include <stdio.h>
//借助指针
size_t my_strlen3(char* str)
{
    if(str == NULL)
    {
        return -1;
    }
    if(*str == '\0')
    {
        return 0;
    }
    char* p_str = str;
    while(*p_str)
    {
        p_str++;
    }
    return p_str - str;
}
//递归
int my_strlen2(char* str)
{
    if(*str == '\0')
    {
        return 0;
    }
    return 1 + my_strlen2(str+1);
}
//借助计数的方式
int my_strlen(char* str)
{
    int count = 0;
    while(*str)
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char str[] = "abcdef";
//    int len = my_strlen(str);
    int len = my_strlen2(str);
    printf("len = %d\n",len);
    return 0;
}
