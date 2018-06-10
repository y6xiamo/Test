#include <stdio.h>

void reverse_string(char* str,int size,int offset)
{
    if(str == NULL)
    {
        return;//非法输入
    }

}
int main()
{
    char str[] = "ABCDEFGH";
    int size = sizeof(str)/sizeof(str[0]);
    reverse_string(str,size,4);
    printf("%s\n",str);
    return 0;
}
