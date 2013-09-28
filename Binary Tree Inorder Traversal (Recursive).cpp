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
    vector<int> res;
    void inorderTraKernel(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            res.push_back(root->val);
            return;
        }
        if (root->left) inorderTraKernel(root->left);
        res.push_back(root->val);
        if (root->right) inorderTraKernel(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if (!root) return res;
        inorderTraKernel(root);
        return res;
    }
};
