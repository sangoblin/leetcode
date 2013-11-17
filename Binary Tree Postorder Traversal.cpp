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
        stack<TreeNode*> postD, postT;
        if (root)   postT.push(root);
        
        while (!postT.empty())
        {
            auto cur = postT.top();
            postT.pop();
            postD.push(cur);
            if (cur->left)  postT.push(cur->left);
            if (cur->right) postT.push(cur->right);
        }
        
        while (!postD.empty())
        {
            res.push_back(postD.top()->val);
            postD.pop();
        }

        return res;
    }
};
