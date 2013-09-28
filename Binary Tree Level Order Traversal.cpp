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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        int cur = 1, cnt = 0;
        if (!root)  return res;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty())
        {
            vector<int> tmpV;
            while (cnt++ < cur)
            {
                TreeNode *tmpN = level.front();
                level.pop();
                tmpV.push_back(tmpN->val);
                if (tmpN->left) level.push(tmpN->left);
                if (tmpN->right) level.push(tmpN->right);
            }
            res.push_back(tmpV);
            cur = level.size();
            cnt = 0;
        }
        return res;
    }
};
