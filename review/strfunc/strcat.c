#include <stdio.h>
#include<string.h>
//字符串拼接
char* my_strcat(char* dest,const char* src)
{
    if(src == NULL && dest == NULL)
    {
        return NULL;
    }
//    if(dest == NULL)
//    {
//        return src;
//    }
    if(src == NULL)
    {
        return dest;
    }
    char* p_dest = dest;
    while(*p_dest)
    {
        p_dest++;
    }
    while(*p_dest++ = *src++)
    {
        ;
    }
    return dest;

}
int main()
{
    char src[] = "hello";
    char dest[128] = "world";
    my_strcat(dest,src);
//    strcat(dest,src);
    int i = 0;
    for(;i <(int)(sizeof(dest)/sizeof(dest[0]));i++)
    {
        printf("%c ",dest[i]);
    }

    return 0;
}
