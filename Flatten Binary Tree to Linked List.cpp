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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)  return;
        auto back = root->right;
        root->right = root->left?root->left:root->right;
        flatten(root->left);
        if (root->left)
        {
            root->left = nullptr;
            while (root->right)
                root = root->right;
        }
        root->right = back;
        flatten(back);
    }
};
