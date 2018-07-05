#include<iostream>
//Definition for binary tree
//二叉树的结构
  struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
//判断两个树是否相等 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)
        {
            return true;//都为空，相等
        }
        if((p == NULL && q != NULL)||(p != NULL && q == NULL)||(p->val != q->val))
        {
            return false;
            //一个为空另一个不为空或者两个结点值不同就不相等
        }
        //递归的遍历
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        
    }

};

int main()
{
    
    return 0;
}
