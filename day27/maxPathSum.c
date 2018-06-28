#include <iostream>

/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    int maxPathSum(TreeNode *root) {

        int max_path = 0;
        _maxPath(root,max_path);
        return max_path;
    
    }
    int _maxPath(TreeNode* root,int _maxPath)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = max(_maxPath(root->lchild,_maxPath),0);
        int right = max(_maxPath(root->rchild,_maxPath),0);
        int _maxPath = max(left+right+root->val,_maxPath);
        return _maxPath;


    };


};

int main()
{

    return 0;
}
