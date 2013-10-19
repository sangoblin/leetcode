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
    int res = 0;
    void sumNumKernel(TreeNode* root, int cur)
    {
        if (!root->left && !root->right)
        {
            res += cur*10+root->val;
            return;
        }
        if (root->left)
            sumNumKernel(root->left, cur*10+root->val);
        if (root->right)
            sumNumKernel(root->right, cur*10+root->val);
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = 0;
        if (!root)  return 0;
        sumNumKernel(root, 0);
        return res;
    }
};
