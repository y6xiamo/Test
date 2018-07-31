#include <stdio.h>
#include<string.h>
#include<assert.h>
//按字节拷贝，有内存重叠问题
void* my_memmove(void* dest,void* src,int count)
{
    assert(dest);
    assert(src);

    char* p_src = (char*)src;
    char* p_dest = (char*)dest;

    //内存重叠：src < dest && dest < src+count，从后往前拷
    if(p_src < p_dest && p_dest < p_src+count)
    {
        p_src = (char*)src + count -1;
        p_dest = (char*)dest + count -1;
        while(count--)
        {
            *p_dest = *p_src;
            p_dest++;
            p_src++;
        }
    }
    //两种情况：都从前往后拷
    //有内存重叠的情况：dest<src
    //没有内存重叠的情况
    else
    {
        while(count--)
        {
            *p_dest = *p_src;
            p_dest++;
            p_src++;
      }
    }
    return dest;
}
int main()
{
    char str[] = "hello world";

//    printf("%s\n",memmove(str,str+1,strlen(str)));
    printf("%s\n",my_memmove(str,str+1,strlen(str)));
    return 0;
}
