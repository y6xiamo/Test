#include <iostream>
using namespace std;

//二叉树的结构
 // Definition for binary tree
    struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //任意一条路径上的最大值
    int maxPathSum(TreeNode *root) {

        int max_path = 0;
        _maxPathSum(root,max_path);//用这个函数完成递归
        return max_path;
    
    }
    int _maxPathSum(TreeNode* root,int maxPath)
    {
        if(root == NULL)
        {
            return 0;
        }
        //最大路径之和 = 左子树最大路径 + 根结点 + 右子树最大路径
        int left = max(_maxPathSum(root->left,maxPath),0);//左子树的最大路径(结点值可能为负，所以要和0比较)
        int right = max(_maxPathSum(root->right,maxPath),0);//右子树的最大路径
        maxPath = max(maxPath,left + right + root->val);//将当前最大路径和重新计算后的路径中的较大值赋给最大路径
        return max(left,right) + root->val;//左右子树路径中较大的 + 根结点

    };


};

int main()
{
    return 0;
}
