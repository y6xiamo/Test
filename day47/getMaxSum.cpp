#include <iostream>
class MaxSum {
using namespace std;

public:
    int getMaxSum(vector<int> A, int n)
    {
        vector<int> max_sum(n);   //子问题最优解的数组
        max_sum[0] = A[0];
        
        int i = 1;
        for( ;i < n;++i)
         {
            max_sum[i] = max(A[i],max_sum[i-1]+A[i]);
         }

          i = 0;
         int sum = 0;
         for( ; i < n;++i)
         {
             if(sum < max_sum[i])
             {
                 sum = max_sum[i];
             }
         }
         return sum;
    }
};
int main()
{
    return 0;
}
