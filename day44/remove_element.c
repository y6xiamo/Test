#include <iostream>
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int count = 0;

        for( ;i < A.length; i++)
        {
            if(A[i] != elem)
            {
                count++;
            }
            else
            {

                A[1] = A[i+1];
            }

        }
        return count;
    }

};

int main()
{
    return 0;
}
