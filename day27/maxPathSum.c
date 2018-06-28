#include <iostream>
using namespace std;

 // Definition for binary tree
    struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode *root) {

        int max_path = 0;
        _maxPathSum(root,max_path);
        return max_path;
    
    }
    int _maxPathSum(TreeNode* root,int maxPath)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = max(_maxPathSum(root->left,maxPath),0);
        int right = max(_maxPathSum(root->right,maxPath),0);
        maxPath = max(maxPath,left + right + root->val);
        return max(left,right) + root->val;

    };


};

int main()
{
    return 0;
}
