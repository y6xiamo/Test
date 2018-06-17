#include<stdio.h>
#include<assert.h>

int my_strncmp(const char* str1,const char* str2,int count)
{
    assert(str1);
    assert(str2);
   
    while(count--)
    {
        if((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
        {
            str1++;
            str2++;
        }
    }
    return *str1 - *str2;
}


int main()
{
    char str1[10] = "abcde123";
    char str2[10] = "abcd123";
    int count =  my_strncmp(str1,str2,7);
    if(count > 1)
    {
        printf("str1 大于str2\n");
    }
    else if(count == 0)
    {
        printf("str1等于str2\n");
    }
    else
    {
        printf("str1小于str2\n");
    }
    return 0;
}



