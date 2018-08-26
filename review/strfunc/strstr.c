#include <stdio.h>
//在一个字符串里查找字串
char* my_strstr(const char* str1,const char* str2)
{
    if(str1 == NULL ||str2 == NULL)
    {
        return NULL;
    }
    if(*str2 == '\0')
    {
        return NULL;
    }
    char* start =(char*) str1;
    char* p_str2 = (char*)str2;
    char* p_str1 = NULL;
    while(*start)
    {
        p_str1 = start;;
        p_str2 = (char*)str2;
        while((*p_str1)&&(*p_str2)&&(*p_str1 == *p_str2))
        {
            p_str1++;
            p_str2++;
        }
        if(*p_str2 == '\0')
        {
           return start;
        }
        start++;
    }
    return NULL;

}
int main()
{
    char str1[] = "efcgiabckfabcdetg";
    char str2[] = "abcd";
    printf("%s\n",my_strstr(str1,str2));
    
    return 0;
}

