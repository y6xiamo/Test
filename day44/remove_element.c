#include <iostream>
class Solution {
public:
    //移除A中的n个元素
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int count = 0;
        //count用来计数
        for( ;i < A.length; i++)
        {
            if(A[i] != elem)
            {
                count++;
            }
            else
            {

                A[i] = A[i+1];
            }

        }
        return count;
    }

};

int main()
{
    return 0;
}
