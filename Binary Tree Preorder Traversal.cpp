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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        stack<TreeNode*> back;
        auto cur = root;
        while (cur || !back.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                if (cur->right)
                    back.push(cur->right);
                cur = cur->left;
            }
            else
            {
                cur = back.top();
                back.pop();
            }
        }
        return res;
    }
};
