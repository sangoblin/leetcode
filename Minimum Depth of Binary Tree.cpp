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
    int depth;
    void minKernel(TreeNode* root, int cur)
    {
        if (!root->left && !root->right)
        {
            depth = min(depth, cur);
            return;
        }
        if(root->left)
            minKernel(root->left, cur+1);
        if (root->right)
            minKernel(root->right, cur+1);
    }
    
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        depth = INT_MAX;
        if (!root)   return 0;
        minKernel(root, 1);
        return depth;
    }
};
