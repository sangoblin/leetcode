/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isSymKernel(TreeNode *left, TreeNode* right)
    {
        if (left==NULL)  return  NULL==right;
        if (!right) return false;
    
        if (left->val==right->val && isSymKernel(left->left, right->right) && isSymKernel(left->right, right->left))
            return true;
        else
            return false;
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)  return true;
        return isSymKernel(root->left, root->right);
    }
};
