#include <stdio.h>
//判断一个机器是大端还是小端
int check_sys2()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c;
}
int check_sys()
{
    int i = 1;
    return (*(char*)&i);
}
int main()
{
    int ret = check_sys2();
    if(ret == 1)
    {
        printf("大端\n");
    }
    else
    {
        printf("小端\n");
    }

    return 0;
}
