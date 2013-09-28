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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        queue<TreeNode*> left, right;
        if (root->left)
            left.push(root->left);
        if (root->right)
            right.push(root->right);
        if (left.empty()!=right.empty())
            return false;
        while (!left.empty() && !right.empty())
        {
            TreeNode *leftN = left.front(), *rightN = right.front();
            left.pop();
            right.pop();
            if (leftN->val != rightN->val)
                return false;
            if (leftN->left && rightN->right)
            {
                left.push(leftN->left);
                right.push(rightN->right);
            }
            else if ((!leftN->left && rightN->right) || (leftN->left && !rightN->right))
                return false;
            if (leftN->right && rightN->left)
            {
                left.push(leftN->right);
                right.push(rightN->left);
            }
            else if ((!leftN->right && rightN->left) || (leftN->right && !rightN->left))
                return false;
        }
        return true;
    }
};
