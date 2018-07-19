#include <iostream>
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int count = 0;

        for( ;i < n; i++)
        {
            if(A[i] != elem)
            {
                A[i] = A[i+1];
                count++;
            }

        }
        return count；
    }

};

