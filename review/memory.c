#include <stdio.h>
#pragma pack()
struct s5
{
    int a:2;
    int b:5;
    int c:10;
    int d:30;
};
struct s4
{
    char c1;
//    struct s3 a;
    double b;
};
struct s3
{
    double b;
    char c;
    int i;
}s3,*p;

struct s2
{
    char c1;
    char c2;
    int i;
};

struct s1
{
    char c1;
    int i;
    char c2;
};
union Un
{
    int i;
    char c;
};
int main()
{
    printf("%d\n",sizeof(struct s1));
    printf("%d\n",sizeof(struct s2));
    printf("%d\n",sizeof(struct s3));
    printf("%d\n",sizeof(struct s4));
    printf("%d\n",sizeof(struct s5));
    union Un un;
    printf("%d\n",sizeof(un));
    printf("%x\n",&(un.i));
    printf("%x\n",&(un.c));
    un.i = 0x11223344;
    un.c = 0x55;
    printf("%x\n",un.i);
    return 0;
}
