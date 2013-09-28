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
    bool isBalKernel(TreeNode *root, int& depth)
    {
        if (!root)
        {
            depth = 0;
            return true;
        }

        int left, right;
        bool _l = isBalKernel(root->left, left), _r = isBalKernel(root->right, right);
        depth = max(left, right)+1;
        return _l && _r && (abs(left-right)<2);
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth;
        return isBalKernel(root, depth);
    }
};
