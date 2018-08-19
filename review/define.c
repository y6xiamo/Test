#include <stdio.h>
//#define Max(a,b) a * b == 8 ? a * b : b
#define Max(a,b) (((a) * (b) == 8) ? ((a) * (b)) :(b))
int main()
{
    printf("%d\n",Max(2,3+1));
    return 0;    
}
