#include <stdio.h>
int my_strlen(char* str)
{
    int count = 0;
    while(*str)
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char str[] = "abcdef";
    int len = my_strlen(str);
    printf("len = %d\n",len);
    return 0;
}
