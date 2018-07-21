#include <iostream>
class Solution {
public:
    //移除A中的n个元素,返回删除后的A的长度
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int count = 0;
        //count用来计数,表示删除后A中的元素个数
        for( ;i < A.length; i++)
        {
            if(A[i] != elem)
            {
                //A中元素不等于要删除的元素
                //count++
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
