#include<stdio.h>
#include<assert.h>
#include<string.h>


char *my_strncpy(char *dst,const char *src,int count)
{
    assert(dst);
    assert(src);

    char *tmp = dst;
    while(count-- &&(*dst = *src))
    {
        src++;
        dst++;
    }
    if(*src == '\0')
    {
        *dst= '\0';
        dst++;
    }

    return tmp;

}
int main()
{
    char dst[64];
    char src[32] = "abcdef1234";
    char *cur;
    cur = my_strncpy(dst,src,10);
    printf("%s\n",cur);
    return 0;
}
