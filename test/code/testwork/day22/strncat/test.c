#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strncat(char* dst,const char* src,int count)
{
    assert(dst);
    assert(src);

    char* tmp = dst;
    while(*dst != '\0')
    {
        dst++;
    }
    while((count--)&&(*src != '\0'))
    {
        *dst = *src;
        dst++;
        src++;
    }
    return tmp;
}

int main()
{
    char dst[50] = "hello,bit";
    char src[50] = "12345";

    char* tmp = my_strncat(dst,src,sizeof(src));
    printf("%s\n",tmp);
    return 0;
}
