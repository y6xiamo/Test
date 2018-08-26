#include <stdio.h>
#include<assert.h>
//字符串比较
int my_strcmp(const char* dest,const char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    int ret = 0;
    while(!(ret = *(unsigned char*)dest - *(unsigned char*)src) && *dest)
    {
        src++;
        dest++;
    }
    //char默认是有符号的，所以要将它强转为无符号的，不然会出错
    //比如129 > 48,char占一个字节，有符号范围为 -128 ~ 127，129会被看成负数，因此 < 48
    if(ret == 0)
    {
        return 0;//相等
    }
    else if(ret > 0)
    {
        return 1;
    }
    else
    {
        return -1;

    }

}
int main()
{
//    char dest[] = "1234a";
//    char src[] = "abcdefg";
//    char dest[] = "1234a";    
//    char src[] = "1234a";
    char dest[] = "1";    
    char src[] = "";
    int ret = my_strcmp(dest,src);
    if(ret > 0)
    {
        printf("desc大于src\n");
    }
    else if(ret <0)
    {
        printf("desc小于src\n");
    }
    else
    {
        printf("dset等于src\n");
    }
    return 0;
}
