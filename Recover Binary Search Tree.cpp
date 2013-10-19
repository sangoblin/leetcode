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
    bool isValidBST(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if (!root)  return true;
        int lVal = left?left->val:INT_MIN, rVal = right?right->val:INT_MAX;
        if (root->val>lVal && root->val<rVal)
            return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
        else if (root->val < lVal)
        {
            root->val ^= left->val ^= root->val ^= left->val;
            return false;
        }
        else if (root->val > rVal)
        {
            root->val ^= right->val ^= root->val ^= right->val;
            return false;
        }
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (!isValidBST(root, nullptr, nullptr))
        {}
    }
};
