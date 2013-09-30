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
    bool check(TreeNode *root, int rVal, int side)
    {
        if (!root)  return true;
        if ((side==-1 && root->val>=rVal) || (side==1 && root->val<=rVal))
                return false;
        
        return check(root->left, rVal, side) && check(root->right, rVal, side);
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)  return true;
        
        int left=(root->left)?root->left->val:INT_MIN;
        int right = (root->right)?root->right->val:INT_MAX;
        if (root->val<=left || root->val>=right || !check(root->left, root->val, -1) || !check(root->right, root->val, 1))
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
