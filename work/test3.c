#include <stdio.h>
//查找第一个单独出现的字符
char find_first_alone_num(char str[],int size)
{
    if(str == NULL)
    {
        return 0;
        //非法输入
    }
    printf("size:%d\n",size);
    int i = 0;
    int cur = 0;//用来表示当前的元素
    int flag = 0;//
    for( ;i < size;i++)
    {
        int j = i+1;
        cur = str[i];
        for( ;j < size - i - 1;j++)
        {
            if(str[j] != cur)
            {
                flag = 1;
                break;
            }
        }
    }
    
        if(flag == 0)
          {
              return cur;
          }
         else
         {
             return 0;
         }

}
 // printf("cur : %c\n",cur);
   // }
   // if(flag == 0):   // {
   //     return cur;
   // }
   // else
   // {
    //   return 0;
    //}


int main()
{
    char str[]= "asdfasdfo";
    int size = sizeof(str)/sizeof(str[0]);
    printf("%d\n",size);
    char ret = find_first_alone_num(str,size);
    printf("%c\n",ret);
    return 0;
}
