#include <stdio.h>
//#define Max(a,b) a * b == 8 ? a * b : b
#define Max(a,b) (((a) * (b) == 8) ? ((a) * (b)) :(b))

inline int max(int a,int b)
{
    if(a * b == 8)
    {
        return a*b;
    }
    else
    {
        return b;
    }

}
int main()
{
    printf("%d\n",Max(2,3+1));
    printf("%d\n",max(2,3+1));
    return 0;    
}
