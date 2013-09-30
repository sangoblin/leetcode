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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> zigzag;
        int cnt = 0, cur = 1, index = 0;
        zigzag.push(root);
        
        while (!zigzag.empty())
        {
            vector<int> tmpV;
            while (cnt++ < cur)
            {
                TreeNode *tmpN = zigzag.front();
                zigzag.pop();
                if (index == 1)
                    tmpV.insert(tmpV.begin(), tmpN->val);
                else
                    tmpV.push_back(tmpN->val);
                if (tmpN->left)     zigzag.push(tmpN->left);
                if (tmpN->right)    zigzag.push(tmpN->right);
            }
            
            cnt = 0;
            index = 1-index;
            cur = zigzag.size();
            res.push_back(tmpV);
        }
        return res;
    }
};
