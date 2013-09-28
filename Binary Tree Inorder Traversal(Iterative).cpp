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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> inorder;
        while (root)
        {
            inorder.push(root);
            root = root->left;
        }
        
        while (!inorder.empty())
        {
            TreeNode* tmpN = inorder.top();
            inorder.pop();
            res.push_back(tmpN->val);
            TreeNode* right = tmpN->right;
            while (right) 
            {
                inorder.push(right);
                right = right->left;
            }
        }
        return res;
    }
};
