#include<iostream>

 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//判断是否是二叉搜索树
//二叉搜索树的规则：左子树小于根结点小于右子树
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root,-1,100);                          
    }
    bool isValidBST(TreeNode* root,int min,int max)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->val <= min || root->val >= max)
        {
            return false;
        }
        return isValidBST(root->left,min,root->val) && 
               isValidBST(root->right,root->val,max);

    }
 };
int main()
{
    return 0;
}
