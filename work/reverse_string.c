#include <stdio.h>
//反转n个字符串
void swap(char* a,char* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

}
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
    {
        return;
    }
    //定义两个指针，
    //一个指向字符串的头，一个指向字符串的结尾
    char* start = str;
    char* end = str + offset -1;
    while(start < end)
    {
        swap(start,end);
        start++;
        end--;
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
