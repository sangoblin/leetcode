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
    bool isValidBSTKernel(TreeNode *root, int lVal, int rVal)
    {
        if (!root)  return true;
        if (root->val>lVal && root->val<rVal)
            return isValidBSTKernel(root->left, lVal, root->val) && isValidBSTKernel(root->right, root->val, rVal);
        else
            return false;
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       return isValidBSTKernel(root, INT_MIN, INT_MAX);
    }
};
