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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        stack<TreeNode*> post;
        
        while (root || !post.empty())
        {
            if (nullptr == root)
            {
                root = post.top();
                post.pop();
                if (!post.empty() && root->right==post.top())
                {
                    auto tmp = root;
                    root = root->right;
                    post.pop();
                    post.push(tmp);
                }
                else
                {
                    res.push_back(root->val);
                    root = nullptr;
                    continue;
                }
            }
            
            while (root->left)
            {
                if (root->right)    post.push(root->right);
                post.push(root);
                root = root->left;
            }
            
            if (!root->right)
            {
                res.push_back(root->val);
                root = nullptr;
            }
            else
            {
                post.push(root);
                root = root->right;
            }
        }
        
        return res;
    }
};
