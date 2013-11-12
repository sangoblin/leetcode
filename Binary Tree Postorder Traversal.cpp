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
        auto cur = make_pair(root, true);
        stack<pair<TreeNode*, bool> > post;
        vector<int> res;
        
        while (cur.first || !post.empty())
        {
            if (nullptr == cur.first)
            {
                cur = post.top();
                post.pop();
            }
            
            if (nullptr==cur.first->left && nullptr==cur.first->right)
            {
                res.push_back(cur.first->val);
                cur.first = nullptr;
            }
            else if (cur.second)
            {
                post.push(make_pair(cur.first, false));
                if (cur.first->right && cur.second)
                {
                    post.top().second = false;
                    post.push(make_pair(cur.first->right, true));
                }
                cur = make_pair(cur.first->left, true);
            }
            else
            {
                res.push_back(cur.first->val);
                cur.first = nullptr;
            }
        }

        return res;
    }
};
