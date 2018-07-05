#include<iostream>

//二叉树的结构
 struct TreeNode {
   int val;
   TreeNode *left;//左子树
   TreeNode *right;//右子树
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//判断是否是二叉搜索树
//二叉搜索树的规则：左子树小于根结点小于右子树
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root,-1,100);//递归的去调用这个函数                          
    }
    bool isValidBST(TreeNode* root,int min,int max)
    {
        if(root == NULL)
        {
            return true;//空树满足二叉搜索树规则
        }
        if(root->val <= min || root->val >= max)
        {
            return false;//不满足规则
        }
        return isValidBST(root->left,min,root->val) && 
               isValidBST(root->right,root->val,max);

    }
 };
int main()
{
    return 0;
}
