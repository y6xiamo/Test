#include<iostream>

 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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
