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
    typedef vector<int>::iterator VIter;
    TreeNode *buildTreeKernel(VIter ib, VIter ie, VIter pb, VIter pe)
    {
        if (ib==ie)  return NULL;
        TreeNode *root = new TreeNode(*(pe-1));
        auto index = find(ib, ie, root->val);
        root->left = buildTreeKernel(ib, index, pb, pb+(index-ib));
        root->right = buildTreeKernel(index+1, ie, pb+(index-ib), pe-1);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return buildTreeKernel(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
