#include <stdio.h>
char find_first_alone_num(char str[],int size)
{
    if(str == NULL)
    {
        return 0;
    }
    //printf("%d\n",size);
    int i = 0;
    int cur = 0;
    int flag = 0;
    for( ;i < size;i++)
    {
        int j = 1;
        cur = str[i];
        for( ; j < size - i;j++)
        {
            if(str[j] == cur)
            {
                flag = 1;
                break;
            }
        }
          if(flag == 0)
          {
              return cur;
          }
          flag = 0;
 // printf("cur : %c\n",cur);
    }
   // if(flag == 0)
   // {
   //     return cur;
   // }
   // else
   // {
        return 0;
    //}
}
int main()
{
    char str[]= "asdfasdfo";
    int size = sizeof(str)/sizeof(str[0]);
    char ret = find_first_alone_num(str,size-1);
    printf("%c\n",ret);
    return 0;
}
