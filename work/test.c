#include <stdio.h>
//反转字符串
void reverse_string(char* str,int size,int offset)
{
    if(str == NULL)
    {
        return;//非法输入
    }
    if(size == 0)
    {
        return;
    }
    if(offset < 0 || offset > size)

}
int main()
{
    char str[] = "ABCDEFGH";
    int size = sizeof(str)/sizeof(str[0]);
    reverse_string(str,size,4);
    printf("%s\n",str);
    return 0;
}
