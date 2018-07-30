#include <stdio.h>
char* my_strcpy(char* dst,const char* src)
{
    if(dst == NULL || src == NULL)
    {
        return NULL;
    }
    while(*dst++ = *src++)
    {
        ;
    }
    return dst;
 //   while(*src)
 //   {
 //       *dst = *src;
 //       dst++;
 //       src++;
 //   }
 //   *dst = '\0';
}
int main()
{
    char src[] = "abcdef";
    char dst[128] ={0};
    my_strcpy(dst,src);
    int i = 0;
    for( ;i <(int)(sizeof(dst)/sizeof(dst[0]));i++)
    {
        printf("%c ",dst[i]);
    }


    return 0;
}
