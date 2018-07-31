#include <stdio.h>
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
int main()
{
    printf("%d\n",sizeof(struct s1));
    printf("%d\n",sizeof(struct s2));
    return 0;
}
