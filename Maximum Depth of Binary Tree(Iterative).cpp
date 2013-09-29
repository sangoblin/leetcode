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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)  return 0;
        queue<TreeNode*> level;
        level.push(root);
        int cnt = 0, cur = 1, maxD = 0;
        while (!level.empty())
        {
            while (cnt++ < cur)
            {
                TreeNode *tmpN = level.front();
                level.pop();
                if (tmpN->left) level.push(tmpN->left);
                if (tmpN->right) level.push(tmpN->right);
            }
            cur = level.size();
            cnt = 0;
            ++ maxD;
        }
        return maxD;
    }
};
