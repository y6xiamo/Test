#include <stdio.h>
#include<assert.h>
#include<string.h>
//按字节拷贝,遇到\0不会停止
void *my_memcpy(void* dest,const void* src,size_t count)
{
    assert(dest);
    assert(src);

    char* p_src = (char*)src;
    char* p_dest = (char*)dest;
    while(count)
    {
        *p_dest = *p_src;
        p_dest++;
        p_src++;
        count--;
    }
    return dest;

}
int main()
{
    char src[] = "abcd1234";
    char dest[10] = {0};
    //my_memcpy(dest,src,sizeof(src)/sizeof(src[0]));
    printf("%s\n",memcpy(dest,src,5));
    printf("%s\n",my_memcpy(dest,src,5));
    return 0;
}
